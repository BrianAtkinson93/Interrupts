#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function
void handle_interrupt(int sig)
{
    printf("Interrupt received: SIGALRM\n");
    // Signal handling code here
    // After handling, you might reset the timer or handle the data

    // Exit program or do additional tasks here
    printf("Handling complete, program will exit now.\n");
    exit(0);
}

int main()
{
    // Set up the signal handler
    struct sigaction sa;
    sa.sa_handler = handle_interrupt; // Set the function to handle the signal
    sa.sa_flags = 0;                  // No flags
    sigemptyset(&sa.sa_mask);

    // Apply the signal action setting to SIGALRM
    if (sigaction(SIGALRM, &sa, NULL) == -1)
    {
        perror("sigaction");
        return EXIT_FAILURE;
    }

    // Configure the timer to fire an interrupt (SIGALRM) after 5 seconds
    alarm(5);

    printf("Timer set for 5 seconds. Waiting for interrupt...\n");

    // Simulate a long-running task that gets interrupted
    while (1)
    {
        sleep(1); // Sleep to simulate work and reduce CPU usage
        printf("Working...\n");
    }

    return 0;
}
