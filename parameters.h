/* ---------------------------------------------------------------------------
** Ilinois Institute of Technology
** Parameters header file.
** Author: Igor Lopes
** September 21st, 2015
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
  void readParameters();
  void setParameters();
  string filterStr(string str, const char* toRemove);
  int getMinInterval();
  int getMaxInterval();
  int getMinSize();
  int getMaxSize();
  int getStaticSize();
  int getStaticTime();
  bool getStatus();
  bool getMemStatus();
  bool getStatic();
  bool getCpuStatus();
  bool getCpuStatic();
  int getCpuStart();
  int getCpuStaticInterv();
  int getCpuMinInterv();
  int getCpuMaxInterv();
  int getCpuStaticSize();
  int getCpuMinSize();
  int getCpuMaxSize();
  void debugValues();
};
