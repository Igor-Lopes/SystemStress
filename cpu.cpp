/* ---------------------------------------------------------------------------
** Ilinois Institute of Technology
** Cpu cpp file.
** Author: Igor Lopes
** September 21st, 2015
** -------------------------------------------------------------------------*/
#include <iostream>
#include <unistd.h>
//------------------Header--------------------------------------------------
#include "cpu.h"

using namespace std;

int Cpu::getPid(){
	return getpid();
}

int Cpu::stressCpu(){
	int i = 0;
	for(;;){
		i++;
		if(i > 2000000){
			i = 0;
		}
	}
	return i;
}
