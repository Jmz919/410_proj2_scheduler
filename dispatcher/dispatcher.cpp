/*
 * Dispatcher.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */

#include "../includes/dispatcher.h"
#include "../includes/constants.h"
#include "../includes/CPU.h"
#include "../includes/PCB.h"

//pull current process (if any) off CPU and return it
//if nothing on CPU returns an uninitialized PCB
PCB Dispatcher::get_from_CPU() {
	return cpu->get_process_off_core();
};

//place the current process on the CPU for execution
void Dispatcher::put_on_CPU(PCB  &process){
	cpu->put_process_on_core(process);
};

//is CPU idle or working
bool Dispatcher::isValidJobOnCPU(){
	return cpu->get_COPY_of_Current_Process().process_number != UNINITIALIZED;
};
