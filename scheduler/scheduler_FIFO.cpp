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
#include "../includes/PCB.h"
#include "../includes/scheduler_FIFO.h"

//override base class behaviour if necessary, otherwise call it
bool  Scheduler_FIFO::time_to_switch_processes(int tick_count, PCB &p){
	if (p.finish_time == UNINITIALIZED) {
		return false;
	}
	return true;
};

//FIFO - not preemptive - no sorting needed
void Scheduler_FIFO::sort() {
	std::queue<PCB> my_queue = *ready_q;
};

