/*
 * scheduler.cpp
 *
 *  Created on: Feb 11, 2021
 *      Author: Josh Zutell
 */

#include <queue>

#include "../includes/constants.h"
#include "../includes/scheduler.h"
#include "../includes/PCB.h"

	//add a process, either a new one or one that
	//had been running on the CPU and has been preempted
void Scheduler::add(PCB p) {
	if (preemptive) {
		ready_q->push(p);
	}
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
		if (p.finish_time == UNINITIALIZED) {
			return false;
		}
		return true;
	}

	return tick_count > time_slice;
};






