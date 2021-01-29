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
