# TRYHACKME: ADVENTOFCYBER2 [DAY 18] REVERSE ENGINEERING - The Bits of Christmas Story

```
"Silly Santa...Forgetting his password yet again!" complains Elf McEager. However, it is in fact Elf McEager who is silly for not creating a way to reset Santa's password for the TBFC dashboard.

Santa needs to get back into the dashboard for Christmas! Can you help Elf McEager reverse engineer TBFC's application to retrieve the password for Santa?!
```

TOPICS: Remmina, ILSpy, Dotpeek

### QUESTIONS

What is Santa's password?

```
sbyte* numPtr = (sbyte*) &\u003CModule\u003E.\u003F\u003F_C\u0040_0BB\u0040IKKDFEPG\u0040santapassword321\u0040;
```

Now that you've retrieved this password, try to login...What is the flag?

```
int num3 = (int) MessageBox.Show("Welcome, Santa, here's your flag thm{046af}", "That's the right key!", MessageBoxButtons.OK, MessageBoxIcon.Asterisk);
```
