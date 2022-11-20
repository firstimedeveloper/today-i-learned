# useful MAC configuration settings using terminal commands

```
# make dock (un)hide delay into 0 (or any other value)
defaults write com.apple.dock autohide-delay -float 0; defaults write com.apple.dock autohide-time-modifier -int 0; killall Dock

# make defualt screenshot to jpg
defaults write com.apple.screencapture type jpg

# show hidden apps (app icon in dock becomes translucent)
defaults write com.apple.Dock showhidden -bool TRUE && killall Dock
```
