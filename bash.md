# Bash related stuff

## Creating/deleting symlinks
Since I use WSL(Windows subsystem for Linux), this command for creating symlinks is especially helpful.
```
ln -s <path-to-original-directory> <path-of-symlink-directory>
ln -s /mnt/c/dev ~/win_dev
```
The command above will create a symlink to the `dev` directory in my C: drive to a directory named `win_dev`. The `-s` tag signifies that this is a symlink and `-symlink` can be used instead (but why type more when you can achieve the same result with two keystrokes 🤷‍♂️).

By the way the `/mnt/c` part is the way windows recommends sharing between WSL and windows.

To delete the symlink, just removing the newly created directory works fine using `rm`
```
rm <path-to-symlink>
rm ~/win_dev
```

## tldr (too long, didn't read)
A very useful command line tool similar to man or -h but shows basic usage examples in a concise manner
```
brew install tldr
tldr zip
```

## zip
Basic functionality of zipping up multiple files or directories
```
// This will create a zip file named project1.zip in the current directory, containing all the files with the .hdl extension. (.hdl was used for a coursera course called nand2tetris)
zip project1.zip *.hdl
// Adding -r will recursively search through directories as well.
zip -r project1.zip *.hdl
```

Using tldr for other use cases will be of great help.


