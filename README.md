#### Compile with gcc
`$ gcc portListen.c -o portListen `

### Run it
`$ ./portListen 5081`

#### Post To It Using Node JS Fetch
1. Open another terminal
2. start node
3. paste and run ( hit &lt;ENTER&gt;) the following:
```
fetch("http://localhost:5081", { method: "POST", body: "Hello from fetch!" });
```
#### Output
You'll see the following in the terminal where the portListen app is running:
<img width="422" height="205" alt="image" src="https://github.com/user-attachments/assets/b530b909-3f10-45c3-bcc4-f489540eed4b" />



