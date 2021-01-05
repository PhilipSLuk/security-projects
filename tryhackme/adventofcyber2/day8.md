# TRYHACKME: ADVENTOFCYBER2 [DAY 8] NETWORKING - What's Under the Christmas Tree?

```
After a few months of probation, intern Elf McEager has passed with glowing feedback from Elf McSkidy. During the meeting, Elf McEager asked for more access to The Best Festival Company's (TBFC's) internal network as he wishes to know more about the systems he has sworn to protect.

Elf McSkidy was reluctant to agree. However, after Elf McEager's heroic actions in recovering Christmas, Elf McSkidy soon thought this was a good idea. This was uncharted territory for Elf McEager - he had no idea how to begin finding out this information for his new responsibilities. Thankfully, TBFC has a wonderful up-skill program covering the use of Nmap for ElfMcEager to enrol in.
```

TOPICS: Nmap

### QUESTIONS

When was Snort created?

```
1998
```

Using Nmap on 10.10.152.126 , what are the port numbers of the three services running?  (Please provide your answer in ascending order/lowest -> highest, separated by a comma)

```

$ sudo nmap -T4 -sS 10.10.152.126                                    1 ⨯
[sudo] password for ffb: 
Starting Nmap 7.91 ( https://nmap.org ) at 2020-12-18 15:31 EST
Nmap scan report for 10.10.152.126
Host is up (0.54s latency).
Not shown: 997 closed ports
PORT     STATE SERVICE
80/tcp   open  http
2222/tcp open  EtherNetIP-1
3389/tcp open  ms-wbt-server

Nmap done: 1 IP address (1 host up) scanned in 2.99 seconds

80,2222,3389
```

Run a scan and provide the -Pn flag to ignore ICMP being used to determine if the host is up

```
nmap -T4 -sS 10.10.152.126
```

Experiment with different scan settings such as-A and -sV whilst comparing the outputs given.

```
nmap -A -Pn 10.10.152.126
nmap -sV -Pn 10.10.152.126
```

Use Nmap to determine the name of the Linux distribution that is running, what is reported as the most likely distribution to be running?

```
ubuntu
```

Use Nmap's Network Scripting Engine (NSE) to retrieve the "HTTP-TITLE" of the webserver. Based on the value returned, what do we think this website might be used for?

```
$ nmap --script http-title -p 80 10.10.152.126 
Starting Nmap 7.91 ( https://nmap.org ) at 2020-12-18 15:43 EST
Nmap scan report for 10.10.152.126
Host is up (0.11s latency).

PORT   STATE SERVICE
80/tcp open  http
|_http-title: TBFC&#39;s Internal Blog

Nmap done: 1 IP address (1 host up) scanned in 0.92 seconds

blog
```
