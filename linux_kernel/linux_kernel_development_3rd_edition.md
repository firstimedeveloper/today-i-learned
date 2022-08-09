## Linux Kernel Development (3rd Edition)

### Notes

[page number - Quotation]

23 - We value and measure people by the usefulness of their contributions, and when you contribute to Linux, you do so in the knowledge that your work is of small but immediate benefit to tens or even hundreds of millions of human beings.

25 - Find an itch and scratch it! Only when you write code will it all come together.

32 - This system state and memory space is collectively referred to as kernel-space. Conversely, user applications execute in user-space.They see a subset of the machine’s available resources and can perform certain system functions, directly access hardware, access memory outside of that allotted them by the kernel, or otherwise misbehave.When executing kernel code, the system is in kernel-space executing in kernel mode.When running a regular process, the system is in user-space executing in user mode

Applications running on the system communicate with the kernel via system calls <…> When an application executes a system call, we say that the kernel is executing on behalf of the application. Furthermore, the application is said to be executing a system call in kernel-space, and the kernel is running in process context.This relationship— that applications call into the kernel via the system call interface—is the fundamental manner in which applications get work done.

32 - The kernel also manages the system’s hardware. Nearly all architectures, including all systems that Linux supports, provide the concept of interrupts.When hardware wants to communicate with the system, it issues an interrupt that literally interrupts the processor, which in turn interrupts the kernel.
A number identifies interrupts and the kernel uses this number to execute a specific interrupt handler to process and respond to the interrupt. <…> The kernel notes the interrupt number of the incoming interrupt and executes the correct interrupt handler. <…> To provide synchronization, the kernel can disable interrupts—either all interrupts or just one specific interrupt number. In many operating systems, including Linux, the interrupt handlers do not run in a process context. Instead, they run in a special interrupt context that is not associated with any process.This special context exists solely to let an interrupt handler quickly respond to an interrupt, and then exit.

[I]n Linux, we can generalize that each processor is doing exactly one of three things at any given moment:
- In user-space, executing user code in a process
- In kernel-space, in process context, executing on behalf of a specific process
- In kernel-space, in interrupt context, not associated with a process, handling an interrupt

This list is inclusive. Even corner cases fit into one of these three activities: For example, when idle, it turns out that the kernel is executing an idle process in process context in the kernel.


#### Chapter 3: Process Management
50 - process is a program in the midst of execution. They also include a set of resources such as open files and pending signals, internal kernel data, processor state, a memory address space with one or more memory
mappings, one or more threads of execution, and a data section containing global variables. **Processes, in effect, are the living result of running program code.**

Threads of execution, [or threads], are the objects of activity within the process. Each thread includes a unique program counter, process stack, and set of processor registers. **The kernel schedules individual threads, not processes.**

[Linux] does not differentiate between threads and processes. To Linux, a thread is just a special kind of process.

processes provide two virtualizations: a virtualized processor and virtual memory. 
1) The virtual processor gives the process the illusion that it alone monopolizes the system, despite possibly sharing the processor among hundreds of other processes.
1) Virtual memory lets the process allocate and manage memory as if it alone owned all the memory in the system.

51 - **Interestingly, note that threads share the virtual memory abstraction, whereas each receives its own virtualized processor.**

A program itself is not a process; a process is an active program and related resources.

##### Process Descriptor and the Task Structure

The kernel stores the list of processes in a circular doubly linked list called the task list. Each element in the task list is a process descriptor of the type `struct task_struct`, defined in `<linux/sched.h>`.
The `task_struct` is a relatively large data structure, at around 1.7 kilobytes on a 32-bit machine. The process descriptor contains the data that describes the executing program
- open files
- the process's address space,
- pending signals
- the process's state
- and more
<img width="300" alt="Screen Shot 2022-08-10 at 12 14 58 AM" src="https://user-images.githubusercontent.com/8170405/183688429-2b013185-35eb-48a1-9d4b-458fd9b9bb31.png">

