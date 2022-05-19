# Useful commands for handling input in python

#### Input is a single value of some type
```python
#string (default)
name = input()

#casting to float
radius = float(input())

#cast to int
n = int(input())
```
#### Input consists of multiple 'words'/tokens in one line
``` python
# number of input is fixed and known in advance
name, email = input().split()
```

what if we want to cast the individual values to another type?

#### Using the 'map' function
``` python
# we can 'map' each of the values given from split()ing our input and cast it using int()
width, height = map(int, input().split())
```

#### input to list
``` python
# list of strings
names = list(input().split())
```

``` python
# list of ints
nums = list(map(int, input().split())
```
