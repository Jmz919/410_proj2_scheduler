/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

#include <vector>
#include "../includes/stats.h"
#include "../includes/PCB.h"

Stats::Stats(std::vector<PCB> &finished_vector) {
	vec = &finished_vector;
	av_wait_time = 0;
	av_turnaround_time = 0;
	av_response_time = 0;
};

//~Stats(){};

//loops thru vec, prints 1 line for each process using the following format
//Process 1 Required CPU time:2  arrived:0 started:0 finished:2
//if there are 10 processes in vector, should print 10 lines
void Stats::showAllProcessInfo(){
	std::vector<PCB> processes = *vec;
	for (long unsigned int i = 0; i < processes.size(); i++) {
		std::cout << "Process " << i << "Required CPU time: " << processes[i].required_cpu_time << " arrived: "
				<< processes[i].arrival_time << " started: " << processes[i].start_time << " finished:" << processes[i].finish_time;
	}
};

//after a process is placed in the ready_q, how long does
//it take before its placed on the processor?
//response_time per process = start_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_response_time(){
	if (vec == NULL) {
		return 0;
	}

	float sum = 0;
	std::vector<PCB> processes = *vec;
	for (long unsigned int i = 0; i < processes.size(); i++) {
		sum += processes[i].start_time - processes[i].arrival_time;
	}
	av_response_time = sum/processes.size();
	return av_response_time;
};

//after a process is placed in the ready_q, how long does
//it take to complete?
//turnaround time per process = finish_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_turnaround_time(){
	if (vec == NULL) {
		return 0;
	}

	float sum = 0;
	std::vector<PCB> processes = *vec;
	for (long unsigned int i = 0; i < processes.size(); i++) {
		sum += processes[i].finish_time - processes[i].arrival_time;
	}
	av_turnaround_time = sum / processes.size();
	return av_turnaround_time;
};

//after a process is placed in the ready_q, how much time does it
//spend waiting for processor time?
//wait time per process = finish_time - arrival_time-required_CPU_time
//this funtion returns the average over all processes
float Stats::get_av_wait_time(){
	if (vec == NULL) {
		return 0;
	}

	float sum = 0;
	std::vector<PCB> processes = *vec;
	for (long unsigned int i = 0; i < processes.size(); i++) {
		sum += processes[i].finish_time - processes[i].arrival_time - processes[i].required_cpu_time;
	}
	av_wait_time = sum / processes.size();
	return av_wait_time;
};

