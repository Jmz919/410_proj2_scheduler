/*
 * scheduler.cpp
 *
 *  Created on: Feb 18, 2021
 *      Author: Josh Zutell
 */

#include "../includes/scheduler.h"

//add a process, either a new one or one that
//had been running on the CPU and has been preempted
void Scheduler::add(PCB p) {
	ready_q->push(p);
	sort();
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
	// If not preemptive switch only if current process is done running or current process is invalid
	if (!preemptive) {
		return p.remaining_cpu_time <= 0 || p.process_number == UNINITIALIZED;
	}

	// If preemptive switch if time slice is over, process is finished, or invalid process
	return (p.required_cpu_time - p.remaining_cpu_time) % time_slice == 0 || p.remaining_cpu_time <= 0
			|| p.process_number == UNINITIALIZED;
};



