# TRYHACKME: ADVENTOFCYBER2 [DAY 6] WEB EXPLOITATION - Be careful with what you wish on a Christmas night

```
This year, Santa wanted to go fully digital and invented a "Make a wish!" system. It's an extremely simple web app that would allow people to anonymously share their wishes with others. Unfortunately, right after the hacker attack, the security team has discovered that someone has compromised the "Make a wish!". Most of the wishes have disappeared and the website is now redirecting to a malicious website.  An attacker might have pretended to submit a wish and put a malicious request on the server! The security team has pulled a back-up server for you on MACHINE_IP:5000. Your goal is to find the way the attacker could have exploited the application.
```

TOPICS: Stored XSS, Reflected XSS, OWASP ZAP

### QUESTIONS

What vulnerability type was used to exploit the application?

```
stored cross-site scripting
```

What query string can be abused to craft a reflected XSS?

```
?q=<script>alert(1)</script>
```

Run a ZAP (zaproxy) automated scan on the target. How many XSS alerts are in the scan?

```
2 (Persistent Cross Site Scripting, Reflected Cross Site Scripting)
```
