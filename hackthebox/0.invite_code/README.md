# Hack the Box Invite Code

Challenge: Feel free to hack your way in :)

https://www.hackthebox.eu/invite

# Notes:

1. Interesting code here: hackthebox.eu/js/inviteapi.min.js

```javascript
eval(function(p,a,c,k,e,d){e=function(c){return c.toString(36)};if(!''.replace(/^/,String)){while(c--){d[c.toString(a)]=k[c]||c.toString(a)}k=[function(e){return d[e]}];e=function(){return'\\w+'};c=1};while(c--){if(k[c]){p=p.replace(new RegExp('\\b'+e(c)+'\\b','g'),k[c])}}return p}('1 i(4){h 8={"4":4};$.9({a:"7",5:"6",g:8,b:\'/d/e/n\',c:1(0){3.2(0)},f:1(0){3.2(0)}})}1 j(){$.9({a:"7",5:"6",b:\'/d/e/k/l/m\',c:1(0){3.2(0)},f:1(0){3.2(0)}})}',24,24,'response|function|log|console|code|dataType|json|POST|formData|ajax|type|url|success|api|invite|error|data|var|verifyInviteCode|makeInviteCode|how|to|generate|verify'.split('|'),0,{}))
```

2. Beautified code (jsbeautifier.org):

```javascript
function verifyInviteCode(code) {
    var formData = {
        "code": code
    };
    $.ajax({
        type: "POST",
        dataType: "json",
        data: formData,
        url: '/api/invite/verify',
        success: function (response) {
            console.log(response)
        },
        error: function (response) {
            console.log(response)
        }
    })
}

function makeInviteCode() {
    $.ajax({
        type: "POST",
        dataType: "json",
        url: '/api/invite/how/to/generate',
        success: function (response) {
            console.log(response)
        },
        error: function (response) {
            console.log(response)
        }
    })
}
```

3. In the `makeInviteCode()` function, we see an API call to `/api/invite/how/to/generate`. Calling that API returns:

```javascript
{
    "0": 200,
    "success": 1,
    "data": {
        "data": "Va beqre gb trarengr gur vaivgr pbqr, znxr n CBFG erdhrfg gb /ncv/vaivgr/trarengr",
        "enctype": "ROT13"
    }
}
```

4. Decoding the string using ROT13 (decode.org):

```
In order to generate the invite code, make a POST request to /api/invite/generate
```

5. Calling the '/api/invite/generate' API gives:

```javascript
{
    "0": 200,
    "success": 1,
    "data": {
        "code": "QVZRQ1otUklRVlktSUNNQUwtVFNWSkEtT0xGVEE=",
        "format": "encoded"
    }
}
```

6. Decoding the 'code' parameter from BASE64 (base64decode.org) gives us an invite code to use!
