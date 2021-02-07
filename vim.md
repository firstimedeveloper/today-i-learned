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



