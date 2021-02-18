/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Feb 18, 2021
 *      Author: Josh Zutell
 *
 *      implements FIFO scheduling algorithm
 *      not pre-emptive
 */

#include <queue>
#include "../includes/constants.h"
#include "../includes/PCB.h"
#include "../includes/scheduler_FIFO.h"

//override base class behaviour if necessary, otherwise call it
bool Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p){
	return Scheduler::time_to_switch_processes(tick_count, p);
};

//FIFO - not preemptive - no sorting needed
void Scheduler_FIFO::sort() {};

