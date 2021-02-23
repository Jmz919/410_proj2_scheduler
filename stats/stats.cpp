/*
 * Stats.cpp
 *
 *  Created on: Feb 18, 2021
 *      Author: Josh Zutell
 */

#include "../includes/stats.h"

Stats::Stats(std::vector<PCB> &finished_vector) {
	vec = &finished_vector;
	av_wait_time = 0;
	av_turnaround_time = 0;
	av_response_time = 0;
};

//loops thru vec, prints 1 line for each process using the following format
//Process 1 Required CPU time:2  arrived:0 started:0 finished:2
//if there are 10 processes in vector, should print 10 lines
void Stats::showAllProcessInfo(){
	std::vector<PCB> processes = *vec;
	for (long unsigned int i = 0; i < processes.size(); i++) {
		std::cout << "Process " << i << " Required CPU time:" << processes[i].required_cpu_time << "  arrived:"
				<< processes[i].arrival_time << " started:" << processes[i].start_time << " finished:" << processes[i].finish_time << "\n";
	}
};

//response_time per process = start_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_response_time(){
	if (vec == NULL) {
		return 0;
	}

    // loops through processes to calculate response time and adds to sum
    // then divides by the number of processes to obtain average
	float sum = 0;
	std::vector<PCB> processes = *vec;
	for (long unsigned int i = 0; i < processes.size(); i++) {
		sum += processes[i].start_time - processes[i].arrival_time;
	}
	av_response_time = sum/processes.size();
	return av_response_time;
};

//turnaround time per process = finish_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_turnaround_time(){
	if (vec == NULL) {
		return 0;
	}

    // loops through processes to calculate turnaround time and adds to sum
    // then divides by the number of processes to obtain average
	float sum = 0;
	std::vector<PCB> processes = *vec;
	for (long unsigned int i = 0; i < processes.size(); i++) {
		sum += processes[i].finish_time - processes[i].arrival_time;
	}
	av_turnaround_time = sum / processes.size();
	return av_turnaround_time;
};

//wait time per process = finish_time - arrival_time-required_CPU_time
//this funtion returns the average over all processes
float Stats::get_av_wait_time(){
	if (vec == NULL) {
		return 0;
	}
    // loops through processes to calculate wait time and adds to sum
    // then divides by the number of processes to obtain average
	float sum = 0;
	std::vector<PCB> processes = *vec;
	for (long unsigned int i = 0; i < processes.size(); i++) {
		sum += processes[i].finish_time - processes[i].arrival_time - processes[i].required_cpu_time;
	}
	av_wait_time = sum / processes.size();
	return av_wait_time;
};

