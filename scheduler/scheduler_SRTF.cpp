/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Feb 13, 2021
 *      Author: Josh Zutell
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

#include <queue>
#include <vector>
#include <algorithm>

#include "../includes/PCB.h"
#include "../includes/scheduler_SRTF.h"

bool sortCPUTime(PCB i, PCB j) {
	return i.remaining_cpu_time < j.remaining_cpu_time;
}

//override base class behaviour if necessary, otherwise call it
bool  Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	return (p.required_cpu_time - p.remaining_cpu_time) % time_slice == 0 || p.remaining_cpu_time == 0 ||
			p.process_number == UNINITIALIZED;
};

//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort() {
	std::vector<PCB> my_vec;
	while (!ready_q->empty()) {
		my_vec.push_back(ready_q->front());
		ready_q->pop();
	}

	std::sort(my_vec.begin(), my_vec.end(), sortCPUTime);
	for (long unsigned int i = 0; i < my_vec.size(); i++) {
		ready_q->push(my_vec[i]);
	}
};
