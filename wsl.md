# WSL
---

## piping command to windows clipboard
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

### creating a zsh function to make things easier
[stackoverflow link](https://unix.stackexchange.com/questions/33255/how-to-define-and-load-your-own-shell-function-in-zsh)
Create a directory and name it something like `~/.my_zsh_functions`.
Under this directory, create a file named `clip`. The filename will be used as the function name automatically.
In `clip`, write `cat $1 | clip.exe`.
This will take the first argument ($1) and execute the command.

Now, in `~/.zshrc`, enter the following:
```
fpath=(~/.my_zsh_functions "${fpath[@]}")
autoload -Uz clip
```
Now `clip <filename>` can be used to execute the whole command!
