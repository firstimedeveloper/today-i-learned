# Threading in Python

## What is a thread?
Threads are basically a unit of execution for a given program or process. A multi-threaded application is capable of processing more than one task in parallel, which is a concept we call concurrency. One of the main reason for multi-threading is to make use of multiple CPU cores, to compute more operations per second. There can be multiple threads in a process, and each of them have their own stack, but share the same heap or memory space. Threads having their own stack allows them to actually do something like calling functions.

Many languages allow the creation of multiple threads, and thus start a concurrent program. 

## Threads in Python3
Because threads of a single process share memory, it is important to have lock and unlocking mechanisms in place to avoid data races. For example, if one thread were to free some malloc'ed data, and shortly after another thread tries to access the free'ed data, an error would occur (Although not entirely true as malloc and free are actually thread-safe, but you get the point). This locking and unlocking mechanism can be achieved by using a mutex.

In python, threads are managed by the Global Interpreter Lock or GIL. GIL is basically a mutex that allows only one thread to have control of the python interpreter. There can only be one thread that can be running in a program at a time. 

### So are threads not a thing in Python?
Threads are still used in python, albeit a bit differenly than in languages such as C. Because there can only be one thread running in a given process, threads in python aren't concurrent. What this means is that multithreading in python actually makes the program slower than if it were to use one thread (Since there is an added overhead, on top of the fact that only one thread can be executed at a time).

### So what is the point of threading in Python?
Threads can be useful in cases where threads are blocked by I/O rather than being CPU-bound. Since the GIL doesn't get locked when a thread is waiting for I/O, another thread can be run while one thread is waiting for I/O.

## To summarize
Due to Python's GIL, parallel computing cannot be reached from multithreading. In python, to harness parallelism for a CPU-intensive task, one would need to use multiple processes instead of threads. However, due to the fact that the GIL doesn't lock when a thread is waiting for I/O, threads can be used to allow concurrency for IO-bound tasks.
