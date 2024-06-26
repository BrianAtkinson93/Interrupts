#include <stdio.h>  // Input and output functions
#include <stdlib.h> // Standard functions like exit
#include <signal.h> // For signal handling and macros
#include <unistd.h> // Used for sleep
#include "../headers/structs.h"


// Array of signals and descriptions.
signal_info signals[] = {
    {SIGHUP, "SIGHUP", "Terminate", "Hangup"},
    {SIGINT, "SIGINT", "Terminate", "Terminal interrupt signal"},
    {SIGQUIT, "SIGQUIT", "Terminate (core dump)", "Terminal quit signal"},
    {SIGILL, "SIGILL", "Terminate (core dump)", "Illegal instruction"},
    {SIGTRAP, "SIGTRAP", "Terminate (core dump)", "Trace/breakpoint trap"},
    {SIGABRT, "SIGABRT", "Terminate (core dump)", "Process abort signal"},
    {SIGFPE, "SIGFPE", "Terminate (core dump)", "Erroneous arithmetic operation"},
    {SIGKILL, "SIGKILL", "Terminate", "Kill (cannot be caught or ignored)"},
    {SIGSEGV, "SIGSEGV", "Terminate (core dump)", "Invalid memory reference"},
    {SIGPIPE, "SIGPIPE", "Terminate", "Write on a pipe with no one to read it"},
    {SIGALRM, "SIGALRM", "Terminate", "Alarm clock"},
    {SIGTERM, "SIGTERM", "Terminate", "Termination signal"},
    {0, NULL, NULL, NULL} // Terminator
};

// Signal handler function
void handle_interrupt(int sig)
{
    printf("\nFunction called: hand_interrupt(%d)\n\n", sig);
    // Search for the signal in the array
    for (int i = 0; signals[i].sig_num != 0; i++)
    {
        if (signals[i].sig_num == sig)
        {
            printf("Interrupt received: %s\n", signals[i].sig_name);
            printf("Description: %s\n", signals[i].description);
            printf("Action: %s\n", signals[i].action);
            break;
        }
    }
    // Signal handling code here
    // After handling, you might reset the timer or handle the data

    // Exit program or do additional tasks here
    printf("Handling complete, program will exit now.\n");
    exit(0);
}

int main()
{
    /*
    The sigaction structure is defined as something like:

        struct sigaction {
            void     (*sa_handler)(int);
            void     (*sa_sigaction)(int, siginfo_t *, void *);
            sigset_t   sa_mask;
            int        sa_flags;
            void     (*sa_restorer)(void);
        };

    ...

    sa_handler specifies the action to be associated with signum and
    can be one of the following:

       •  SIG_DFL for the default action.

       •  SIG_IGN to ignore this signal.

       •  A pointer to a signal handling function.  This function
          receives the signal number as its only argument.

    */

    printf("Setting up handling for SIGALRM...\n");
    struct sigaction sa;

    if (SET_ALARM == 1) { sa.sa_handler = SIG_DFL; }    // We can also set sa.sa_handler to SIG_DFL to set the default behavior
    else { sa.sa_handler = handle_interrupt; };         // Set the function to handle the signal

    sa.sa_flags = 0;          // No flags
    sigemptyset(&sa.sa_mask); // Allows other signals to interrupt the handler

    // Apply the signal action setting to SIGALRM
    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        perror("sigaction");
        return EXIT_FAILURE;
    }

    // Configure the timer to fire an interrupt (SIGALRM) after 5 seconds
    alarm(5);

    printf("Timer set for 5 seconds. Waiting for interrupt...\n");

    // Simulate a long-running task that gets interrupted
    while (1) {
        sleep(1); // Sleep to simulate work and reduce CPU usage
        printf("Working...\n");
    }

    return 0;
}
