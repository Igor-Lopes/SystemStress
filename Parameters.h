/* ---------------------------------------------------------------------------
** Ilinois Institute of Technology
** Software that simulated the aging phenomena on memory/cpu.
** Authors: Igor Lopes
** Novemer 3rd, 2015
** -------------------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>

using namespace std;

class Parameters{

private:
string parameters[18];
int minSize;
int maxSize;
int minInterv;
int maxInterv;
int staticSize;
int staticTime;
bool isRunning;
bool isStatic;
bool memStatus;
bool cpuStatus;
bool cpuStatic;
int cpuStart;
int cpuStaticSize;
int cpuStaticInterv;
int cpuMinInterv;
int cpuMaxInterv;
int cpuMinSize;
int cpuMaxSize;
public:
	void readParameters(){
        	ifstream fin ("Parameters.config");
        	string line;
        	int last_index = 0;
        	while(getline(fin, line)){
                	parameters[last_index] = line;
                	last_index++;
        	}
        	fin.close();
	}

	void setParameters(){
		string run = filterStr(parameters[0], "RUNNING= ");

		if(run.compare("true") == 0){
			isRunning = true;
		} else {
			isRunning = false;
		}

		string stat  = filterStr(parameters[11], "MEM_STATIC= ");

		 if(stat.compare("true") == 0){
                        isStatic = true;
                } else {
                        isStatic = false;
                }

		string memS = filterStr(parameters[1], "MEMORY= ");
		 if(memS.compare("true") == 0){
                        memStatus = true;
                } else {
                        memStatus = false;
                }

		string cpuS = filterStr(parameters[2], "CPU= ");
                 if(cpuS.compare("true") == 0){
                        cpuStatus = true;
                } else {
                        cpuStatus = false;
                }

		string cpuStat = filterStr(parameters[3], "CPU_STATIC= ");
                 if(cpuStat.compare("true") == 0){
                        cpuStatic = true;
                } else {
                        cpuStatic = false;
                }

		cpuStart = stoi(filterStr(parameters[4], "CPU_START,= "));
		cpuStaticInterv = stoi(filterStr(parameters[5], "CPU_INTERV_STATIC ,= "));
                cpuMinInterv = stoi(filterStr(parameters[6], "CPU_INTERV_MIN,= "));
                cpuMaxInterv = stoi(filterStr(parameters[7], "CPU_INTERV_MAX,= "));
                cpuStaticSize = stoi(filterStr(parameters[8], "CPU_ALLOC_STATIC,= "));
                cpuMinSize = stoi(filterStr(parameters[9], "CPU_ALLOC_MIN,= "));
                cpuMaxSize = stoi(filterStr(parameters[10], "CPU_ALLOC_MAX,= "));

		staticSize = stoi(filterStr(parameters[12], "MEM_ALLOC_STATIC,= "));
		staticTime = stoi(filterStr(parameters[13], "MEM_INTERV_STATIC,= "));
		minInterv = stoi(filterStr(parameters[14], "MEM_INTERV_MIN= "));
		maxInterv = stoi(filterStr(parameters[15], "MEM_INTERV_MAX= "));
		minSize = stoi(filterStr(parameters[16], "MEM_ALLOC_MIN= "));
		maxSize = stoi(filterStr(parameters[17], "MEM_ALLOC_MAX,= "));
	}

	string filterStr(string str, const char* toRemove){
		for(int i = 0; i < strlen(toRemove); i++){
			str.erase( remove(str.begin(), str.end(), toRemove[i] ), str.end() );
		}
		return str;
	}

	int getMinInterval(){ return minInterv; }

	int getMaxInterval(){ return maxInterv; }

	int getMinSize(){ return minSize; }

	int getMaxSize(){ return maxSize; }

	int getStaticSize(){ return staticSize; }

	int getStaticTime(){ return staticTime; }

	bool getStatus(){ return isRunning; }

	bool getMemStatus() { return memStatus; }

	bool getStatic(){ return isStatic; }

	bool getCpuStatus() { return cpuStatus; }

	bool getCpuStatic() { return cpuStatic; }

	int getCpuStart() { return cpuStart; }

	int getCpuStaticInterv() { return cpuStaticInterv; }

	int getCpuMinInterv() { return cpuMinInterv; }

	int getCpuMaxInterv() { return cpuMaxInterv; }


	int getCpuStaticSize() { return cpuStaticSize; }

	int getCpuMinSize() { return cpuMinSize; }

	int getCpuMaxSize() { return cpuMaxSize; }

	void debugValues(){ //Print the values of the variables read from the Parameters file.

		cout <<"Program Running Status"<< getStatus() <<endl;

		cout <<"Mem Running Status:"<< getMemStatus() <<endl;
		cout <<"Mem static Status:" <<getStatic() <<endl;
		cout <<"Mem Static Time:"<< getStaticTime() <<endl;
		cout <<"Mem Min Interv:"<< getMinInterval() <<endl;
                cout <<"Mem Max Interv:"<< getMaxInterval() <<endl;
		cout <<"Mem Static Size:"<< getStaticSize() <<endl;
		cout <<"Mem Min Size:"<< getMinSize() <<endl;
                cout <<"Mem Max Size:"<< getMaxSize() <<endl;

		cout <<"Cpu Running Status:"<< getCpuStatus() <<endl;
		cout << "Cpu Static Status:" << getCpuStatic() <<endl;
		cout <<"Cpu Static Interv:" << getCpuStaticInterv() <<endl;
		cout << "Cpu Min Interv" << getCpuMinInterv() <<endl;
		cout << "Cpu Max Interv" << getCpuMaxInterv() <<endl;
		cout << "Cpu Start Size:" << getCpuStart() <<endl;
		cout << "Cpu Min Size:" << getCpuMinSize() <<endl;
		cout << "Cpu Max Size:" << getCpuMaxSize() <<endl;
	}

};

