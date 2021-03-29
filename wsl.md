# WSL
---
Super convenient !!
using `<some-command> | clip.exe`
will pipe the output of `<some-command>` into the windows clipboard!
So for example, 
given a textfile named `hello.txt` containing the word `hello`, running,
```
cat hello.txt | clip.exe
```
will copy hello in to the the windows clipboard.

Combine this with something like ditto and things become super convenient.
