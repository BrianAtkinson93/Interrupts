#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int signal_arrived = 0;

int foo()
{
    printf("Hey! We've received a signal!");

    signal_arrived = 1;
    return 0;
}

int main()
{
    signal(SIGUSR1, foo);
    while (!signal_arrived)
    {
        /* Do Nothing! */
    }

    /* A signal has arrived - we are out of the loop. */
    return 0;
}