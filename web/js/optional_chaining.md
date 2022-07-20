# Optional Chaining

### What is it?
Starting from Node.js version 14, you can use optional chaining, or the `?.` operator for accessing values of objects that may be null or unidentified.

Does **work** with un-declared root objects./
Does work with undefined root objects

[mdn docs](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Optional_chaining)

No need to check whether the object exists or not.

``` javascript
const animals = {
  dog: {
    name: 'heukja'
  },
  cat: {
    name: 'labong'
  }
};
// previously to check for a property that may be missing,
// you had to do something like this
if (animals.turtle && animals.turtle.name == 'turtly')
  return true;

// now you can do someting like this
if (animals?.turtle.name === 'turtly')
  return true;
```



