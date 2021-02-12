/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
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
	return tick_count > time_slice;
};

//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort() {
	std::vector<PCB> my_vec;
	std::queue<PCB> my_queue = *ready_q;

	while (!my_queue.empty()) {
		my_vec.push_back(my_queue.front());
		my_queue.pop();
	}

	std::sort(my_vec.begin(), my_vec.end(), sortCPUTime);
	for (long unsigned int i = 0; i < my_vec.size(); i++) {
		my_queue.push(my_vec[i]);
	}

	ready_q = &my_queue;
};
