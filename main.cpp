/* ---------------------------------------------------------------------------
** Ilinois Institute of Technology
** Software that simulated the aging phenomena on memory.
** Authors: Igor Lopes
** September 21st, 2015
** -------------------------------------------------------------------------*/
#include <iostream>
#include <unistd.h> //Library which has the sleep command.
#include <pthread.h> //The library used to manage posix threads.
#include <cstdlib>
//------------------Headers--------------------------------------------------
#include "parameters.h"
#include "memory.h"
#include "cpu.h"

using namespace std;

int getRnd(int n2, int n1){ return rand()% n2 + n1; }

void  *memory(void *arg){ //Posix thread method that will allocate memory and simulate the aging phenomena.
	Parameters p;
	p.readParameters();
	p.setParameters();
	bool memRun = p.getMemStatus();
	int minSize = p.getMinSize();
	int maxSize = p.getMaxSize();
	int minInterv = p.getMinInterval();
	int maxInterv = p.getMaxInterval();
	int staticSize = p.getStaticSize();
	int staticTime = p.getStaticTime();
	bool isStatic = p.getStatic();
	bool isRunning = p.getStatus();
	Memory mem( minSize, maxSize, staticSize, isStatic );
	int seconds = 0;
	cout << "-------------------------- Memory Stressing: Running --------------------------"<<endl;
	while(isRunning && memRun){
		if(seconds == 0){
			if(isStatic == true){
				seconds = staticTime; //Frequency
				mem.allocStatic();
				cout << "Next Allocation in: " << seconds << " Seconds:" <<endl;
			} else {
				seconds = getRnd( maxInterv, minInterv );
				cout << "Next Allocation in: " << seconds << " Seconds:" <<endl;
				mem.allocDynamic();
			}
		}else{
			p.readParameters();
			p.setParameters();
			isRunning = p.getStatus();
			memRun = p.getMemStatus();
			sleep(1);
			seconds--;
		}
	}

	cout << "-------------------------- Memory Stressing: Endend --------------------------"<<endl;
}

void *setWorkLoadCpu(void *arg){
	Parameters p;
	p.readParameters();
	p.setParameters();
	bool cpuRun = p.getCpuStatus();
	int minSize = p.getCpuMinSize();
	int maxSize = p.getCpuMaxSize();
	int minInterv = p.getCpuMinInterv();
	int maxInterv = p.getCpuMaxInterv();
	int staticSize = p.getCpuStaticSize();
	int staticTime = p.getCpuStaticInterv();
	bool isStatic = p.getCpuStatic();
	bool isRunning = p.getStatus();
	int seconds = 0;
	int int_pid = *((int *)arg);
	string pid = to_string(int_pid);
	int curr_lim = p.getCpuStart();
	string limit_arg = "cpulimit -b -l " + to_string(curr_lim) + " -p " + pid;
	system(limit_arg.c_str());
	cout << "-------------------------- CPU Stressing: Running --------------------------"<<endl;
	while(isRunning && cpuRun){
		if(seconds == 0){
			if(isStatic == true){
				seconds = staticTime; //Frequency
				cout << "Current CPU usage limit: "<< curr_lim <<endl;
				cout << "Next CPU Workload in: " << seconds << " Seconds:" <<endl;
				if(curr_lim + staticSize <= 100){
					curr_lim += staticSize;
					limit_arg = "cpulimit -b -l " + to_string(curr_lim) + " -p " + pid;
					system(limit_arg.c_str());
				}
			} else {
				seconds = getRnd( maxInterv, minInterv );
				cout << "Current CPU usage limit: "<< curr_lim <<endl;
				cout << "Next CPU Workload in: " << seconds << " Seconds:" <<endl;
			}
		}else{
			p.readParameters();
			p.setParameters();
			isRunning = p.getStatus();
			cpuRun = p.getCpuStatus();
			sleep(1);
			seconds--;
		}
	}

	string exit_arg = "kill " + pid;
	system(exit_arg.c_str());

	cout << "-------------------------- CPU Stressing: Endend --------------------------"<<endl;
}

void  *stresscpu(void *arg){
	Cpu cpu;
	pthread_t workload;
	int pid = cpu.getPid();
	int rc = pthread_create(&workload,0,setWorkLoadCpu, (void*) &pid);
	cpu.stressCpu();
}

int main(){

	pthread_t threadMem;
	int rc;
	rc = pthread_create(&threadMem,0,memory,NULL);//Creates and starts each thread.
	if(rc){
		cout << "Error "<<endl;
		exit(-1);
	}

	pthread_t threadCpu;
	int lc;
	lc = pthread_create(&threadCpu,0,stresscpu,NULL);
	if(lc){
		cout << "Error Initialing Thread to stresscpu"<<endl;
		exit(-1);
	}
	//Exits
	pthread_exit(NULL);
	return 0;
}
