/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Feb 18, 2021
 *      Author: Josh Zutell
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

#include <vector>
#include <algorithm>
#include "../includes/scheduler_SRTF.h"

//Sort function to sort each process based on remaining cpu times
bool sortCPUTime(PCB i, PCB j) {
	return i.remaining_cpu_time < j.remaining_cpu_time;
}

//override base class behavior if necessary, otherwise call it
bool  Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	// If another process on ready_q and the next process remaining cpu time is less than current remaining cpu time
	// Then it is time to switch
	if (!ready_q->empty() && p.remaining_cpu_time > ready_q->front().remaining_cpu_time) {
		return true;
	}
	// If current process is finished or invalid process then switch
	return p.remaining_cpu_time <= 0 || p.process_number == UNINITIALIZED;
};

//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort() {
	std::vector<PCB> my_vec;

	// Put all the processes in a vector to more easily sort
	while (!ready_q->empty()) {
		my_vec.push_back(ready_q->front());
		ready_q->pop();
	}

	// Sort the vector and place them back into queue
	std::sort(my_vec.begin(), my_vec.end(), sortCPUTime);
	for (long unsigned int i = 0; i < my_vec.size(); i++) {
		ready_q->push(my_vec[i]);
	}
};

