# Karabiner
As someone who often switches back and forth between a windows pc and a macbook, one thing that irritates me is the different way of switching languages between the two operating systems. 
In fact, for Korean keyboards in windows, changing the input source is a simple press of the button to the right of the spacebar.
Once this becomes muscle memory, the standard mac way of cmd+space/ctrl+space/(long press)caps-lock(for korean keyboards) becomes way too cumbersome.
The equivalent input switch key for osx would be the right_command key, located to the right of the spacebar. Being able to use this key, and this key only to swithch languages would be amazing.

## Enter Karabiner
To make this a reality in osx, we can map the right_command key found to the right of the spacebar to the f18 key. **One (k)aveat, since the command key can be used along with other keys, it would be wise to enable this only when the right command key is pressed alone.**

Now, from the keyboard shortcut settings under system settings, switch the 'Select next source in input menu' shortcut to the right command key and the f18 key will **magically** appear. (More accruately, for me, command+f18 appeared, but this shouldn't be a problem)

All I had to do was import a similar 'switch key if pressed alone' rule made by another user and change it like below. The right command key becomes f18 if pressed alone.
Here's the code (json):
```
{
  "title": "Right command to f18 if alone (to redefine language switch to right command)",
  "rules": [
    {
      "description": "Right command to f18 if alone",
      "manipulators": [
        {
          "type": "basic",
          "from": {
            "key_code": "right_command",
            "modifiers": { "optional": ["any"] }
          },
          "to": [{ "key_code": "right_command", "lazy": true }],
          "to_if_alone": [
            { "key_code": "f18", "modifiers": ["right_gui"] }
          ]
        }
      ]
    }
  ]
}
```

With the above complex rule, as it is called within karabiner, you are now able to change your input source with the right command key as well actually use the right command key when you need to.
