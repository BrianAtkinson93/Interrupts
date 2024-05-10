#ifndef STRUCTS_H
#define STRUCTS_H

#include <signal.h>

// Define constants if needed
#define SET_ALARM 0

// Structure to hold the table information
typedef struct
{
    int sig_num;
    const char *sig_name;
    const char *action;
    const char *description;
} signal_info;

// Declaration of teh array of singals and descriptions
extern signal_info signals[];

// Declaration of the signal handler func
void handle_interrupt(int sig);

#endif