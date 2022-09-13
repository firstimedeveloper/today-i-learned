유저 모드: 하드웨어 접근이 안됨, 접근 시도 할 시, 익셉션이 발동함. 운영체제의 익셉션 핸들러 --> 커널모드로 변환됨.

cooperative approach: wait until a process makes a system call
non-cooperative approach: os takes control
- problem: 해킹에 취약함, 프로그램에 버그가 있어도 컴퓨터가 먹통이 될 수 있음.
Earlier versions of OSs used to take the cooperative approach.

interrupt: an unexpected event from outside the process
exception: an unexpected even from within the process

timer interrupt: (intel) interrupt number 0.


context switch: written in assembly

scheduling:
- preemptive: can take cpu time from a running job
- non-preemptive: cannot take cpu time from a running job
  - sjf: smallest average turnaround time for a non-preemptive
    - problem: 간발의 차로 큰 job가 들어오면, 결국 다 늦어짐.
    - 

---
starvation
- long running jobs never recieving any cpu time
