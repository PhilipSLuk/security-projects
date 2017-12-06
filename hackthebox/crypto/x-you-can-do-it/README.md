# CRYPTO CHALLENGE: YOU CAN DO IT!

## Challenge Description
The flag is in the format HTB{plaintext}

```
$ cat you_can_do_it.txt 
YHAOANUTDSYOEOIEUTTC!
```

### SUBSTITUTION

```
https://quipqiup.com/
```

Using the `statistics` mode yielded the following:

```
0	-1.775	RPENED TO WARNING I TOOK!
1	-1.802	ASON OF THE MAN IN WITH HU!
2	-1.814	CVE HER SO MUCH THAT SOON!
3	-1.829	GION OF REPUGNANT ARE EX!
4	-1.844	INDED FOR A PIECES CORRU!
```

That doesn't look like it..

### VIGENERE

```
http://www.mygeocachingprofile.com/codebreaker.vigenerecipher.aspx
```

That didn't lead any where either..

### ANAGRAM

Found some hint from a forum that suggested it might be an anagram..

```
http://boulter.com/anagram/?letters=YHAOANUTDSYOEOIEUTTC
```

Using this approach to iteractively choose words and reducing the remaining
problem set yield the following!

```
YHAOANUTDSYOEOIEUTTC!
YOUSEETHATYOUCANDOIT!
```
