# FORENSICS CHALLENGE: MARSHAL IN THE MIDDLE

## Challenge Description
The security team was alerted to suspicous network activity from a production
web server.  Can you determine if any data was stolen and what it was?

```
bro/conn.log
bro/ssl.log
bro/files.log
bro/http.log
bro/packet_filter.log
bro/weird.log
bro/dns.log
bundle.pem
secrets.log
chalcap.pcapng
```

### INITIAL INSPECTION

First thing we note is that we have three different types of file extensions,
`.log`, `.pem` and `.pcapng`.

##### PRIVACY ENHANCED MAIL

The `.pem` file (internet tells me it is `Privacy Enchanced Mail` file which
is a `Base64` encoded DER certificate) contains what appears to be a RSA
Private Key.

```
$ cat bundle.pem
-----BEGIN CERTIFICATE-----
MIIFrTCCA5WgAwIBAgIUFHWEs92j/6b3twM03DJozrSlvQowDQYJKoZIhvcNAQEN
BQAwXjELMAkGA1UEBhMCVVMxCzAJBgNVBAgTAlRYMQ8wDQYDVQQHEwZEYWxsYXMx
DDAKBgNVBAoTA0hUQjEPMA0GA1UECxMGU2VjT3BzMRIwEAYDVQQDEwlTbm9vcHkg
Q0EwHhcNMTcwODI1MjIyMTAwWhcNMjIwODI0MjIyMTAwWjBeMQswCQYDVQQGEwJV
UzELMAkGA1UECBMCVFgxDzANBgNVBAcTBkRhbGxhczEMMAoGA1UEChMDSFRCMQ8w
DQYDVQQLEwZTZWNPcHMxEjAQBgNVBAMTCVNub29weSBDQTCCAiIwDQYJKoZIhvcN
AQEBBQADggIPADCCAgoCggIBAKY2/WZU+LgNwQkfTFnVmqyqqmEj08sk70ICs3e7
F7oYBIhHVOT7RynahnYmjt2Mva0wtPBwCwdU83YLhLIkiKgCALfQaI1MwSM2JQaD
V2iBCNh0Ap8V6OsfzyAQMWHDWbzhb53Hc/+hkv7rHCphJ8zg8KkmxuOHZmCkwCQ9
uTmqFeFXRGoeSLgLMiA5Rg5P+19gQf8TCpk1UNSuvhaoDWRxuD4hdMx9uccpGC1z
yrmMKXVtR/pMS+pIhPloF1SkmBLmvEvr31oSICN1WqYzwHC9MqQ0+4NeOc/KnDW7
tgsK29T7X0GuvpaR0+eUmUIRPPYT8pvClXpdDqnID+SWYc4yFxVjP9HtOxryT6k0
9WxsZE5aAQHdsIRJooBAgEvTq6tO/LK1f29A+PiNdH4U8azS0ffU970HpSU+Ep7f
R7qNvzD4r3Z34skZE6kqO7RSYhbamABzO+g1IipQ/GUUK8IoLSKoq1Xe3tRRF9WC
6CjMf63w/E1nHnHY802JxV6N2YjJqvAKEPivBylQIgE4d4EggTX4nGBO+MSptCjf
p0nd+B5xsCNyGybKeWxWtDhlBPWHGUVchU9EIOoAsaLvnqKQ0h8fE9Of1bFk6a5s
yRpzL6cJyGjMsXygu94T+n9SjGMhv8hg1DUsSLAdDe7MylntbJk84mg3erPnrumk
taMXAgMBAAGjYzBhMA4GA1UdDwEB/wQEAwIBBjAPBgNVHRMBAf8EBTADAQH/MB0G
A1UdDgQWBBSKalGWHdc0/NX3v6pgdceRzOa3GzAfBgNVHSMEGDAWgBSKalGWHdc0
/NX3v6pgdceRzOa3GzANBgkqhkiG9w0BAQ0FAAOCAgEAPAkMPTKlLDe/MVzhgMq/
PIrKTwTrvwZOBtb4fxcezjs0MvWh89BBkjFQHoZ4mtSR6hV8eI+nt9moU1FuGlSe
NIwiYqGCoRaVLsSM8cHWZSxXPgeMCZFe1bpMm6dVFHHmcuSuZrLLHgn5dMX9r6sM
Yt7myL46TK+gFB4FUTSBuzb58f5Bq/jUO8Q61pb3DftR02cH8wb+8kIUu5iE5aZH
WgG4zPTprXRveNWjNfM6l+TzwI8iBHs+N8e0tp/hMvDgmiV4tocT5Tt2GJ1c9E9N
szXYwhoLABuq/3UHswthAsezHzMcHHR+erBXJZWQCgLdwd5UXeA7AL93JvmLS7sR
nT7yHGZn+1HWne5ytD/YbSri6OcIJBm5j4JVBc/Q/1Re7f6LgMO40b8ZGzHWkkVC
73JR6u/+KQr5+IJGPtu2bBcbJACQV0Mp7kArthkaks5mHvGiOU+QgA/IPYHktTvx
tgFkwBCvx3eXQRUBlzaQ8e4EnxWoCA8Wl8P5EtVXUlVzTZkbDc+f+9lkToOWWMzH
jyZ5Mnr04b2t4Y5zeDYvtmOSUSaotw2+0ODNyy9uIhaKjpbM46dL8/H42ih+y9rF
1utj/Xp4zPiPhBA7LXDbfjYdbB9T+uc/uDKhRPEL5iycYp994pLjG8SqWY8aETfa
sabN9OTXKVuNAtAFosBuP9I=
-----END CERTIFICATE-----
-----BEGIN RSA PRIVATE KEY-----
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
-----END RSA PRIVATE KEY-----
```

Weird that it seems to include more than just the private key, but researching
around I found that a `.pem` file may contain the entire certificate chain..
so I assume that is what is happening here.

```
.pem - Defined in RFC's 1421 through 1424, this is a container format that may
include just the public certificate (such as with Apache installs, and CA
certificate files /etc/ssl/certs), or may include an entire certificate chain
including public key, private key, and root certificates. 

https://serverfault.com/questions/9708/what-is-a-pem-file-and-how-does-it-differ-from-other-openssl-generated-key-file
 ```

I assume I'm going to need this to decrypt something I find in the logs..

##### PCAP NEXT GENERATION

Now let's figure out what the `.pcapng` file is..

```
Packet capture format that contains a "dump" of data packets captured over a
network; saved in the PCAP Next Generation file format, a standard format for
storing captured data.

https://fileinfo.com/extension/pcapng
```

This appears to be a file we'll need to use `wireshark` to inspect.

##### BRO LOGGING

All the log files under `bro/*.log` appear to by related to logging done by a
network analysis framework tool called `Bro`.

```
Once Bro has been deployed in an environment and monitoring live traffic, it
will, in its default configuration, begin to produce human-readable ASCII logs.
Each log file, produced by Bro’s Logging Framework, is populated with organized,
mostly connection-oriented data. As the standard log files are simple ASCII
data, working with the data contained in them can be done from a command line
terminal once you have been familiarized with the types of data that can be
found in each file. In the following, we work through the logs general
structure and then examine some standard ways of working with them.

https://www.bro.org/sphinx-git/logs/index.html#bro-logging
```

##### SECRETS.LOG

And finally, we have this file called `secrets.log`.  No idea what this is, but
perhaps related to the final flag we'll be looking for?

```
$ head secrets.log 

CLIENT_RANDOM 59a18ad4db33aee1c71dcb4bbb4bd184da7792d0cac8836f8f93ea71d587efd9 734e1550f70968b574d8662c468481c6bdd6efd04aecc52b71fb175f24b4c657bb0da77f7923a9e381e6bc721694e466
CLIENT_RANDOM 59a18ad4b27cdf1deb206209c13ec9886da69589fb44f14c816681d4cb2e1ba2 08627dabfda20e398be1ccee9165cc1b4341d858abdb54ae85cf8dd7f58f53eb322adbacaea7a4850e6f13c63d5fa0d7
CLIENT_RANDOM 2a7e8aef5a083b4063debef0aa3997109166f8a8bcec1029e01bb3769235ce53 d8c1f9845a95eec65747235cdf80a051c56c5bfc85213582c3ddf07d4190feac79d9e0c8daffce144e18a12e72569dd9
CLIENT_RANDOM 3e4f127acc4b63b90160f84dd537a714106dfe06ba61b934cad78c69d3e1f021 046ef9f774df12e10192ac3603a6eaa4e7afb04a31c7d71a5631e3979773a97abfb08a9e3f860ff40eeb3221e3ead743
CLIENT_RANDOM 59a18ad5fc650b540e22a1b396701562f37caceed5ae60865162cba6e2dfb796 873b3a04fc408f2c255a5bd960af7f78bef7a4746c7f58d9eaf99160430b8f69893bfc96d1732b116cb224079b1fe450
CLIENT_RANDOM 4a8f4b5668afacff041b0bb937132e37baf2895dc1bb13c50c96329fbef11d2d 012c669afb20f6a4fd9b46fe5b23f69bad717a67f5f717855876d95b8e394a1f23ada75b89832dfe4dbf979bccf86af2
CLIENT_RANDOM 59a18ad54633ee5d6ebbd7eb68028577c740348a29fa2a55fb64832740f6aa61 eedbb8946c80b57d46861f8abb943bb878d1b647dbe262436d4b733b6fb95b719ab4da026fee0d4aefa5b378b992bcc7
CLIENT_RANDOM 6ab39dc1534817cbd1281cc4bc46a1a6a2ef2ace704879b5ac3a07288d7bd4f7 2ab506ba55355040080a6c56e3db32780330041bb74e80fc4900c10005c16cfcdaa015f986357f120043c14645a607df
CLIENT_RANDOM 6b925c29b3fff89db716fd442e00278ab03a16465b189ec5d6b4313844030909 b24675a0b3b7673dbe4d15ee843bedb85cc6a615ee6e8e6d4efa8eedfb67eda467301b00d0f0584f5713296747c18a8a
```

### WIRESHARK
