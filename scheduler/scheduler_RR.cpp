/*
 * SchedulerSTRR.cpp
 *
 *  Created on: Sep 7, 2019
 *      Author: keith
 *
 *      implements round robin scheduling algorithm
 *      pre-emptive
 */

#include <queue>
#include "../includes/PCB.h"
#include "../includes/scheduler_RR.h"

//override base class behaviour if necessary, otherwise call it
bool Scheduler_RR::time_to_switch_processes(int tick_count, PCB &p) {
	return tick_count > time_slice;
};

//RR - preemptive - no sorting of ready_q needed.
void Scheduler_RR::sort(){
	std::queue<PCB> my_queue = *ready_q;
};

