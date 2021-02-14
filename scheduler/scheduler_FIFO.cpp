/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
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
	return p.remaining_cpu_time <= 0 || p.process_number == UNINITIALIZED;
};

//FIFO - not preemptive - no sorting needed
void Scheduler_FIFO::sort() {
	std::queue<PCB> my_queue = *ready_q;
};

