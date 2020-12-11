# TRYHACKME: ADVENTOFCYBER2 - [DAY 4] WEB EXPLOITATION - Santa's Watching

```
We're going to be taking a look at some of the fundamental tools used in web application testing. You're going to learn how to use Gobuster to enumerate a web server for hidden files and folders to aid in the recovery of Elf's forums. Later on, you're going to be introduced to an important technique that is fuzzing, where you will have the opportunity to put theory into practice.

Our malicious, despicable, vile, cruel, contemptuous, evil hacker has defaced Elf's forums and completely removed the login page! However, we may still have access to the API. The sysadmin also told us that the API creates logs using dates with a format of YYYYMMDD.
```

TOPICS: Fuzzing, Gobuster, wfuzz

### QUESTIONS

Given the URL "http://shibes.xyz/api.php", what would the entire wfuzz command look like to query the "breed" parameter using the wordlist "big.txt" (assume that "big.txt" is in your current directory).  Note: For legal reasons, do not actually run this command as the site in question has not consented to being fuzzed!

```
wfuzz -c -z file,big.txt http://shibes.xyz/api.php?breed=FUZZ
```

Use GoBuster (against the target you deployed -- not the shibes.xyz domain) to find the API directory. What file is there?

```
gobuster dir -u http://10.10.185.213 -w /usr/share/wordlists/dirb/big.txt 

site-log.php
```

Fuzz the date parameter on the file you found in the API directory. What is the flag displayed in the correct post?

```
wfuzz -c -z file,wordlist --hw 0 http://10.10.185.213/api/site-log.php?date=FUZZ
 /usr/lib/python3/dist-packages/wfuzz/__init__.py:34: UserWarning:Pycurl is not compiled against Openssl. Wfuzz might not work correctly when fuzzing SSL sites. Check Wfuzz's documentation for more information.
********************************************************
* Wfuzz 3.0.1 - The Web Fuzzer                         *
********************************************************

Target: http://10.10.185.213/api/site-log.php?date=FUZZ
Total requests: 63

===================================================================
ID           Response   Lines    Word     Chars       Payload   
===================================================================

000000026:   200        0 L      1 W      13 Ch       "20201125"

Total time: 0
Processed Requests: 63
Filtered Requests: 62
Requests/sec.: 0

THM{D4t3_AP1}
```
