# Sorting in python
Use case: 
[link to ps Q](https://programmers.co.kr/learn/courses/30/lessons/17676)
The problem asks to return the maximum number of requests that happened in a day within a 1 second window.

let's say there's a list of lists.
arr = [[time, state], [time, state], [time, state], ...]
where the state == [0 or 1]. 0 for the start time, 1 for the end time.

if we wanted to sort the above list first based on time, and then (for when times are equal), the state,

we would use:

``` python
sort(arr, key=lambda x:(x[0], x[1]))
```
What the above code means is, for every element of arr, we want to sort based on x[0] (which is the time in our case), and then x[1] (the state)

