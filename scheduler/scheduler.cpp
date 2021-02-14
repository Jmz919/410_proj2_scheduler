/*
 * scheduler.cpp
 *
 *  Created on: Feb 11, 2021
 *      Author: Josh Zutell
 */

#include <queue>
#include <algorithm>

#include "../includes/constants.h"
#include "../includes/scheduler.h"
#include "../includes/PCB.h"

	//add a process, either a new one or one that
	//had been running on the CPU and has been preempted
void Scheduler::add(PCB p) {
	ready_q->push(p);

//	if (preemptive) {
//		ready_q->push(p);
////		sort();
//	}
//	else {
//		if (ready_q != 0) {
//			if (ready_q->size() == 0) {
//				ready_q->push(p);
//			}
//			else {
//				std::vector<PCB> my_vec;
//				while (!ready_q->empty()) {
//					my_vec.push_back(ready_q->front());
//					ready_q->pop();
//				}
//
//				bool contains = false;
//				for (long unsigned int i = 0; i < my_vec.size(); i++) {
//					if (p.process_number == my_vec[i].process_number) {
//						contains = true;
//						break;
//					}
//				}
//
//				if (!contains) {
//					my_vec.push_back(p);
//				}
//
//				for (long unsigned int i = 0; i < my_vec.size(); i++) {
//					ready_q->push(my_vec[i]);
//				}
//			}
//		}
//	}
};

	//get next process
PCB Scheduler::getNext() {
	PCB process = ready_q->front();
	ready_q->pop();
	return process;
};

	//returns true if there are no  jobs in the readyQ
	//false otherwise
bool Scheduler::isEmpty() {
	return ready_q->empty();
};

	//if process has completed (used all its remaining_cpu_time) or
	//if we are using a preemptive scheduling algorithm and the
	//timeslice is over then its time to switch processes
	//returns:
	//true - switch processes
	//false - do not switch
bool  Scheduler::time_to_switch_processes(int tick_count, PCB &p) {
	if (!preemptive) {
		return p.remaining_cpu_time == 0;
	}

	return tick_count % time_slice == 0;
};






