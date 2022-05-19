# What are magic methods?
When using python, we frequently come across things such as `__name__, __init__, __contains__`. 
These double underscores are interpreted differently by the python interpreter and the underscores are used to mitigate name clashes.

### 1.`___contains___` built-in method
The `__contains__` built-in method is used for handling the `in` keyword in python.
You can do things like 
``` python
names = [list of names]
if "John Doe" in names:
  #do something
  pass
  
#internally, somthing like this is being called:
names.__contains__("John Doe")
```
#### Overloading the `___contains___` method 
What if we had a list of objects of a custom class we created?
``` python
class Account():
  _id = 0
  def __init__(self, name):
    self.name = name
    self.id = _id
    self._id += 1

  ... methods
  def ___contains__(self, id):
    return self.id == id
    
 # we can do this now
 accounts = [list of accounts]
 id = 100
 if id in accounts:
  # do something
  pass
```
The code above will allow our custom class objects to be identified based on their `id` value.
