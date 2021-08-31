# Configuring debian for Born2BeRoot
## Sudo
(Debian 10) 
1. Become a superuser with `su`.
1. Install `sudo` with `apt-get install sudo`.
1. Add the user account to the sudo group using `/sbin/adduser username sudo`
1. logout, log back in, and test that everything works using `sudo echo 'hello, world'`.

