#pragma once

#include "common.h"

typedef enum{
    NEW,
    READY,
    RUNNING,
    WAITING,
    TERMINATED
} ProcessState;

typedef struct{
    int pid;
    int cpu_burst;
    int io_burst;
    int remaining_time;

    double arrival_time;
    double start_time;
    double completion_time;
    double total_wait_time;

    ProcessState state;
} Process;

Process* create_process(int pid, int arrival_time, int cpu_burst, int io_burst, int time_tick);
void update_process_state(Process *process, ProcessState new_state);
void terminate_process(Process *process);
