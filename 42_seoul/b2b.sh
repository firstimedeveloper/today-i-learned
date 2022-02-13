su -
# add user to group(s)
useradd -aG (user42, sudo) juhan
# show user’s groups
id juhan
# make user42 default group for juhan
usermod -g user42 juhan
