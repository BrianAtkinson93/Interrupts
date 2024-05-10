# Interupts

## What is an interupt?
An interrupt is a signal sent from either hardware or software indicating that some event needs immediate attention. The signal then "interrupts" the current process, saves state (switches context), and then executes a function called an interrupt handler, or an interrupt service routine (ISR) to deal with the event.

## Originating Sources
* __Hardware Interrupt__: Hardward interrupts are generated by hardware or physical devices, something like a keyboard, mouse, network card, etc. signaling the need to process data or actions. For example, a keyboard interrupt signals a key press.
* __Software Interrupt__: Software Interrupts are triggered by software through a system call. This happens when software requests a service like reading a file, allocating memory, etc.

## Interrupt Signal
The purpose of an interrupt signal is to notify the CPU of a high-priority condition requiring immediate attention. Once the CPU finishes executing the current instruction, it saves the current state. This saved state includes information necessary to allow the CPU to resume its previous activity without loss of data or functionality. The CPU then switches context to execute the interrupt service routine (ISR) designated for handling this specific interrupt. After the ISR completes its task, the previously saved state is reloaded, enabling the CPU to continue from exactly where it was interrupted. This process ensures that the system can handle real-time events efficiently while maintaining ongoing tasks seamlessly.

## Main.c
`main.c` is structured to simulate an interrupt scenario using the `SIGALRM` signal. This is a form of software interrupt provided by the UNIX/LINUX operating systems.

1. Signal Handling Setup
The program begins by setting up the handling mechanism for the `SIGALRM` signal. This is done by using the `sigaction` structure and function, which are part of the standard library.

* Structure Definition (`struct sigaction sa`): This strucutre is used to define how a particular signal should be handled. The `sa_handler` points to the function that should be executed when the signal is received which we have modified to point to `handle_interrupt`.  
* Signal Mask (`sigemptyset(&sa.sa_mask)`): This function initializes the signal mask to block no other signals when the `handle_interrupt` function is running, meaning it can be interrupted by other signals.  
* Applying the Signal Action (`sigaction(SIGALRM, &sa, NULL)`): This line sets up the defined action for `SIGALRM` signal. If there is an error while setting up the signal action the program prints an error message and exits.

## References

sigaction(2) -- Linux manual pages [https://man7.org/linux/man-pages/man2/sigaction.2.html](https://man7.org/linux/man-pages/man2/sigaction.2.html) 