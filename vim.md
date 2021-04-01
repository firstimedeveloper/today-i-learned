# Helpful vim commands

## Using macros

```
// To create a macro
q<letter><command>q

// To use the macro
<number>@<letter> // where number defaults to 1
```

### Example usage
1. press `qa` to start recording a macro with the letter `a`.
1. enter the commands. When incrementing, use ^a and ^x to decrement instead of hard coding numbers.
1. press q when done with the commands.
1. `@a` to execute the command once. `10@a` to execute the command ten times. `@@` to execute the macro (that was entered most recently) again.

# Searching and replacing
```
:%s/[find]/[replace]/g
// % searches for the entire file
// g replaces all occurances in the current line
```
## Escape characters

There are many special characters that need to be escaped when searching.
For example, when  searching for `[0]`, the brackets need to be escaped resulting in `\[0\]`. 
There are many other special characters that need to be escaped like backslash itself (`\\`).

# (vim on WSL) better copying and paste in vim
---
When using vim on iterm2, I could easily copy (yank) and paste across different vim sessions. However, using WSL on windows, yanking and pasting across different vim sessions no longer worked.

Searching online, the general solution was to be able to use the system (windows) clipboard. Basically, yanking would copy the selected text to the system clipboard, and pasting will then paste from the windows clipboard. There were several options which all had their pros and cons.
1. **A simple script in the vimrc file** that allowed you to usie Clip.exe (as mentioned in wsl.md), when copying. [solution here](https://superuser.com/questions/1291425/windows-subsystem-linux-make-vim-use-the-clipboard)
This seemed easy enough, and was a great solution if you just wanted to copy some text to the windows clipboard. However what I wanted to do was to copy and paste across vim sessions, not just copy to the windows side. This meant that I first needed to copy from vim to the system clipboard (which this solution did well), but then also somehow paste (using p) in vim from the system clipboard.

I could've pasted using copy+(shift)+v, but I wanted to use p.

2. Moving on, another option (which admitedly I did not try), was to **set up a server on the windows side** and somehow allowing everything to work together. Based on the comments, this seemed to work, but for some reason, setting up a server on the windows side to make copying and paste work on vim just seemed too much.
3. The third option was sort of **an extended version of 1, that uses a third party package on github**. [solution here](https://stackoverflow.com/questions/44480829/how-to-copy-to-clipboard-in-vim-of-bash-on-windows). You first install the package, set it to your path (details on how to do that in the above link), and add some lines in your vimrc (this part not necessary if using neovim). 

So the option I went with was the third option. 
Since I didn't want to install neovim just to make this work a little bit easier, I went for the 'vim' version. 
However this also has its limitations as everytime I'm yanking and pasting, I'm basically running a script to access the system clipboard. This means it's quite noticably slower than normal.
However, other than that, my problem of copy and pasting across vim sessions is solved quite perfectly. As a side benefit, since everything I yank from within vim is also copied to the system clipboard, which could be useful when searching.

