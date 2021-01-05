# TRYHACKME: ADVENTOFCYBER2 [DAY 14] SPECIAL - Where's Rudolph?

```
Twas the night before Christmas and Rudolph is lost
Now Santa must find him, no matter the cost
You have been hired to bring Rudolph back
How are your OSINT skills? Follow Rudolph's tracks...
```

TOPICS: OSINT

```
https://whatsmyname.app/
https://namecheckup.com/
```

### QUESTIONS

What URL will take me directly to Rudolph's Reddit comment history?

```
https://www.reddit.com/user/IGuidetheClaus2020/comments/

Ouch. Some days I love Twitter. Some days, it's just...lol.
Fun fact: I was actually born in Chicago and my creator's name was Robert!
All that's missing is some jingle juice!
Holy electric bill, Batman!
This reminds me of home. I sure do miss it!
```

According to Rudolph, where was he born?

```
chicago
```

Rudolph mentions Robert.  Can you use Google to tell me Robert's last name?

```
may
```

On what other social media platform might Rudolph have an account?

```
twitter
```

What is Rudolph's username on that platform?

```
https://twitter.com/IGuideClaus2020
```

What appears to be Rudolph's favorite TV show right now?

```
bachelorette
```

Based on Rudolph's post history, he took part in a parade.  Where did the parade take place?

```
Google Image serach: https://www.thompsoncoburn.com/news-events/news/2019-12-09/thompson-coburn-floats-down-michigan-avenue-in-first-magnificent-mile-lights-festival-appearance
```

Okay, you found the city, but where specifically was one of the photos taken?

```
http://exif.regex.info/exif.cgi
https://tcm-sec.com/wp-content/uploads/2020/11/lights-festival-website.jpg

GPS Latitude: 41.891815 degrees
GPS Longitude: -87.624277 degrees
```

Did you find a flag too?

```
Copyright: {FLAG}ALWAYSCHECKTHEEXIFD4T4
```

Has Rudolph been pwned? What password of his appeared in a breach?

```
https://haveibeenpwned.com/
rudolphthered@hotmail.com

https://scylla.sh/
email:rudolphthered@hotmail.com

spygame
```

Based on all the information gathered.  It's likely that Rudolph is in the Windy City and is staying in a hotel on Magnificent Mile.  What are the street numbers of the hotel address?

```
Chicago Marriot Downtown Magnificent Mile - 540 N Michigan Ave, Chicago, IL 60611, United States
```
