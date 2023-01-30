# Installation
1. Clone the latest stable release of the kernel
```shell
git clone git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux-stable.git linux_stable
cd linux_stable
git branch -a | grep linux -5
git checkout linux-5.12.y
```

2. Copy the configuration for the current kernel from /boot

```shell
ls /boot
cp /boot/config-5.0.0-21-generic .config
```
3. Compile the Kernel

Using the current configurations of your system has a good chance of working correctly for building the new kernel.

```shell
# do either
make oldconfig
# or to create a config file based on the list of modules
# currently loaded on your system,
lsmod > /tmp/my-lsmod
make LSMOD=/tmp/my-lsmod localmodconfig

# then
make -j3 all 
# the j option specifies the number of jobs to run for compilation

```
4. Install the new Kernel

```shell
# adding sudo before su may be necessary
su -c "make modules_install install"
```

5. Seeing the `dmesg` log output from a previous session
```
# last boot
sudo journalctl -o short-precise -k -b -1
# all boots
sudo journalctl -o short-precise -k -b -all
```

### troubleshooting
- [setting up git-email correctly with gmail](https://stackoverflow.com/questions/68238912/how-to-configure-and-use-git-send-email-to-work-with-gmail-to-email-patches-to)
- [fixing certification error](https://unix.stackexchange.com/questions/293642/attempting-to-compile-kernel-yields-a-certification-error)
- [authentication error when using 'su'](https://askubuntu.com/questions/446570/why-does-su-fail-with-authentication-error)
- [fixing certification error 2](https://superuser.com/questions/1214116/no-openssl-sign-file-signing-key-pem-leads-to-error-while-loading-kernel-modules/1322832#1322832)
- [compiling error](https://stackoverflow.com/questions/68157695/error-scripts-makefile-modinst33-arch-x86-crypto-aegis128-aesni-ko)
- [adding signature to your own module](https://stackoverflow.com/questions/24975377/kvm-module-verification-failed-signature-and-or-required-key-missing-taintin)
- [dmesg from previous boots](https://unix.stackexchange.com/questions/181067/how-to-read-dmesg-from-previous-session-dmesg-0)
