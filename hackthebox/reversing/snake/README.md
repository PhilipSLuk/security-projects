# REVERSING CHALLENGE: SNAKE

## Challenge Description
Flag should be in the format: HTB{username:password} 

```
snake.py
```

### EXECUTION

Okay, so a Python script. Let's see what we are dealing with here..

```
$ python snake.py 

___________.__               _________              __           
\__    ___/|  |__   ____    /   _____/ ____ _____  |  | __ ____  
  |    |   |  |  \_/ __ \   \_____  \ /    \__  \ |  |/ // __ \ 
  |    |   |   Y  \  ___/   /        \   |  \/ __ \|    <\  ___/ 
  |____|   |___|  /\___  > /_______  /___|  (____  /__|_ \___  >
                \/     \/          \/     \/     \/     \/    \/ 


The Snake Created by 3XPL017
Your number is 420
Authentication required

Enter your username
foo
Wrong username try harder
```

Looks like the first thing we need to figure out is the expected `username`.

### FILE INSPECTION - PASSWORD

Let's take a peak at the code..

```
$ cat snake.py
#!/usr/bin/python2.7
import random
lr = '\x64'
print '''
___________.__               _________              __
\__    ___/|  |__   ____    /   _____/ ____ _____  |  | __ ____
  |    |   |  |  \_/ __ \   \_____  \ /    \\__  \ |  |/ // __ \
  |    |   |   Y  \  ___/   /        \   |  \/ __ \|    <\  ___/
  |____|   |___|  /\___  > /_______  /___|  (____  /__|_ \\___  >
                \/     \/          \/     \/     \/     \/    \/

'''
chains = [0x74, 0x68, 0x69, 0x73, 0x20, 0x69, 0x73, 0x20, 0x61, 0x20, 0x74, 0x72, 0x6f, 0x6c, 0x6c]
db = '\x6e'
ef = '\x63'
chars = []
keys = [0x70, 0x61, 0x73, 0x73, 0x77, 0x6f, 0x72, 0x64, 0x21, 0x21]
nn = '\x61'
lock_pick = random.randint(0, 0x3e8)
lock = lock_pick * 2
password = [0x69, 0x74, 0x73, 0x20, 0x6e, 0x6f, 0x74, 0x20, 0x74, 0x68, 0x61, 0x74, 0x20, 0x65, 0x61, 0x73, 0x79]
lock = lock + 10
ty = '\x61'
lock = lock / 2
auth = [0x6b, 0x65, 0x65, 0x70, 0x20, 0x74, 0x72, 0x79, 0x69, 0x6e, 0x67]
lock = lock - lock_pick
gh = '\x6e'
print 'The Snake Created by 3XPL017'
print 'Your number is ' + str(lock_pick)
for key in keys:
    keys_encrypt = lock ^ key
    chars.append(keys_encrypt)
for chain in chains:
    chains_encrypt = chain + 0xA
    chars.append(chains_encrypt)
aa = '\x61'
rr = '\x6f'
slither = aa + db + nn + ef + rr + gh + lr + ty
print 'Authentication required'
print ''
user_input = raw_input('Enter your username\n')
if user_input == slither:
    pass

else:
    print 'Wrong username try harder'
    exit()
pass_input = raw_input('Enter your password\n')
for passes in pass_input:
    for char in chars:
        if passes == str(chr(char)):
            print 'Good Job'
            break
        else:
            print 'Wrong password try harder'
            exit(0)
    break
```

So the sections governing the `username` check is at line 38 where `slither` is
set and compared to our input..

```
slither = aa + db + nn + ef + rr + gh + lr + ty
print 'Authentication required'
print ''
user_input = raw_input('Enter your username\n')
if user_input == slither:
    pass
``` 

Looking up the values each of the variables which make up the `slither`
assignment, we see it is built up of a concatenation of a series of individual
characters. Let's write up our own quick script to see what the resultant
string is..

```
$ cat test.py 
slither = '\x61' + '\x6e' + '\x61' + '\x63' + '\x6f' + '\x6e' + '\x64' + '\x61'
print slither
$ python test.py 
anaconda
```

Alright then. Let's feed that into the script and see how far we get..

```
$ python snake.py 

___________.__               _________              __           
\__    ___/|  |__   ____    /   _____/ ____ _____  |  | __ ____  
  |    |   |  |  \_/ __ \   \_____  \ /    \__  \ |  |/ // __ \ 
  |    |   |   Y  \  ___/   /        \   |  \/ __ \|    <\  ___/ 
  |____|   |___|  /\___  > /_______  /___|  (____  /__|_ \___  >
                \/     \/          \/     \/     \/     \/    \/ 


The Snake Created by 3XPL017
Your number is 144
Authentication required

Enter your username
anaconda
Enter your password
foo
Wrong password try harder
```

Great, we got passed the first gate. Let's try and figure out what the expected
password is now.

### FILE INSPECTION - USERNAME

The relevant piece of the script governing the password is the following..

```
pass_input = raw_input('Enter your password\n')
for passes in pass_input:
    for char in chars:
        if passes == str(chr(char)):
            print 'Good Job'
            break
        else:
            print 'Wrong password try harder'
            exit(0)
```

So we can see that our input appears to be compared character by character
to the string `char`.. but interestingly enough upon close inspection we
notice that only the first character seems to matter since it will either
match with success and break out of the loop or fail to match and exit from
the program. Weird, wonder if that matters.

Anyway, let's look into how `chars` is built up to see what else we can learn.
We extract the following lines that are most relevant..

```
chars = []
lock_pick = random.randint(0, 0x3e8)
lock = lock_pick * 2
lock = lock + 10
lock = lock / 2
lock = lock - lock_pick
keys = [0x70, 0x61, 0x73, 0x73, 0x77, 0x6f, 0x72, 0x64, 0x21, 0x21]
for key in keys:
    keys_encrypt = lock ^ key
    chars.append(keys_encrypt)
chains = [0x74, 0x68, 0x69, 0x73, 0x20, 0x69, 0x73, 0x20, 0x61, 0x20, 0x74, 0x72, 0x6f, 0x6c, 0x6c]
for chain in chains:
    chains_encrypt = chain + 0xA
    chars.append(chains_encrypt)
```

The string `char` is generated by using the string `keys` and `chains` as
input and modifying `keys` with a randomly generated value in `lock_pick` and
modifying `chains` with the offset `0xA`. Writing a quick script to see what
string `keys` and `chains` map to we get `password!!` and `this is a troll`..

```
$ cat test.py 
keys = [0x70, 0x61, 0x73, 0x73, 0x77, 0x6f, 0x72, 0x64, 0x21, 0x21]
chains = [0x74, 0x68, 0x69, 0x73, 0x20, 0x69, 0x73, 0x20, 0x61, 0x20, 0x74, 0x72, 0x6f, 0x6c, 0x6c]
chars_key = []
chars_chain = []
for key in keys:
    chars_key.append(chr(key))

for chain in chains:
    chars_chain.append(chr(chain))

print chars_key
print chars_chain
$ python test.py 
['p', 'a', 's', 's', 'w', 'o', 'r', 'd', '!', '!']
['t', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', ' ', 't', 'r', 'o', 'l', 'l']
```

Since we can just edit the source of our script directly, let's just do that
to dump the expected password since it's easier than trying to trace the code
further..

```
$ diff snake.py snake_mod.py 
29a30
> print 'Your lock is ' + str(lock)
47a49,52
> mypasswd = ""
> for char in chars:
>     mypasswd += str(chr(char))
> print 'Expected password: ' + mypasswd
```

```
$ python snake_mod.py 

___________.__               _________              __           
\__    ___/|  |__   ____    /   _____/ ____ _____  |  | __ ____  
  |    |   |  |  \_/ __ \   \_____  \ /    \__  \ |  |/ // __ \ 
  |    |   |   Y  \  ___/   /        \   |  \/ __ \|    <\  ___/ 
  |____|   |___|  /\___  > /_______  /___|  (____  /__|_ \___  >
                \/     \/          \/     \/     \/     \/    \/ 


The Snake Created by 3XPL017
Your number is 928
Your lock is 5
Authentication required

Enter your username
anaconda
Expected password: udvvrjwa$$~rs}*s}*k*~|yvv
Enter your password
udvvrjwa$$~rs}*s}*k*~|yvv
Good Job
```

What is interesting is that the `lock` despite using random input `lock_pick`
always results in `5`, so the password results in the same string every time.
We can also confirm that entering any password that starts with the letter `u`
is enough to generate the "good job" message. Bug in the script... or clue?

```
$ python snake_mod.py 

___________.__               _________              __           
\__    ___/|  |__   ____    /   _____/ ____ _____  |  | __ ____  
  |    |   |  |  \_/ __ \   \_____  \ /    \__  \ |  |/ // __ \ 
  |    |   |   Y  \  ___/   /        \   |  \/ __ \|    <\  ___/ 
  |____|   |___|  /\___  > /_______  /___|  (____  /__|_ \___  >
                \/     \/          \/     \/     \/     \/    \/ 


The Snake Created by 3XPL017
Your number is 873
Your lock is 5
Authentication required

Enter your username
anaconda
Expected password: udvvrjwa$$~rs}*s}*k*~|yvv
Enter your password
u_random_random_random
Good Job
```

### BUT WAIT..

We expect the flag should be `HTB{anaconda:udvvrjwa$$~rs}*s}*k*~|yvv}`, but
that doesn't work when entered into HTB??? Do we need to reconsider our
assumptions? Does the "only require first letter to be `u`" contain a hint?

Going back to the code, we recall that `keys = password!!` and
`chains = this is a troll`.. could that mean that what we actually need to
enter is only the part of the code from `keys`?? i.e. `udssrjwa$$`.  Is
knowing the full "password" isn't necessary to make the script generate
"success" the hint that the full password wasn't the flag?

If we put in `HTB{anaconda:udvvrjwa$$}` against HTB actually worked.. wow.
