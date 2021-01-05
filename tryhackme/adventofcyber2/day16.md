# TRYHACKME: ADVENTOFCYBER2 [DAY 16] SCRIPTING - Help! Where is Santa?

```
Oh no! Santa 🎅 has taken off, leaving you -- the faithful elves behind! Can you help find Santa's location?

Luckily, the elves are OSINT masters and remember a thing or two. Specifically, they remember:

Santa has a webpage at MACHINE_IP/static/index.html to help lost elves find their way home. Santa never told the elves what port number the webserver is on. Can you find out?!
This webpage has a link somewhere on it, hidden away so anyone that isn't an elf can't find it.
Santa's Sled has an API we can talk too. The key for the API is between 0 and 100, and it's an odd number. But be careful! After an unknown number of attempts, Santa's Sled will ban your IP address. 
```

TOPICS: Scripting

### QUESTIONS

What is the port number for the web server?

```
$ nmap -p 1-10000 -T4 10.10.99.19                                                                130 ⨯
Starting Nmap 7.91 ( https://nmap.org ) at 2020-12-20 22:52 EST
Nmap scan report for 10.10.99.19
Host is up (0.10s latency).
Not shown: 9999 closed ports
PORT     STATE SERVICE
8000/tcp open  http-alt

Nmap done: 1 IP address (1 host up) scanned in 84.11 seconds
```

Without using enumerations tools such as Dirbuster, what is the directory for the API?  (without the API key)

```
http://10.10.99.19:8000/api/
```

Where is Santa right now?

```
$ cat links.py
from bs4 import BeautifulSoup
import urllib2
import re

url = "http://10.10.99.19:8000/static/index.html"

html_page = urllib2.urlopen(url)

soup = BeautifulSoup(html_page,features="html.parser")

for link in soup.findAll('a', attrs={'href': re.compile("^http://")}):
    print link.get('href')

$ python links.py
http://machine_ip/api/api_key

$ cat api.py
from bs4 import BeautifulSoup
import urllib2
import re

for i in range(33,99):
    if i % 2 != 0:
        url = "http://10.10.189.139:8000/api/" + str(i)
        html_page = urllib2.urlopen(url)
        soup = BeautifulSoup(html_page,features="html.parser")
        print(soup)

$ python api.py
{"item_id":33,"q":"Error. Key not valid!"}
{"item_id":35,"q":"Error. Key not valid!"}
{"item_id":37,"q":"Error. Key not valid!"}
{"item_id":39,"q":"Error. Key not valid!"}
{"item_id":41,"q":"Error. Key not valid!"}
{"item_id":43,"q":"Error. Key not valid!"}
{"item_id":45,"q":"Error. Key not valid!"}
{"item_id":47,"q":"Error. Key not valid!"}
{"item_id":49,"q":"Error. Key not valid!"}
{"item_id":51,"q":"Error. Key not valid!"}
{"item_id":53,"q":"Error. Key not valid!"}
{"item_id":55,"q":"Error. Key not valid!"}
{"item_id":57,"q":"Winter Wonderland, Hyde Park, London."}
```

Find out the correct API key. Remember, this is an odd number between 0-100. After too many attempts, Santa's Sled will block you.  To unblock yourself, simply terminate and re-deploy the target instance (10.10.99.19)

```
57
```
