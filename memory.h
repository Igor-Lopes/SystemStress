/* ---------------------------------------------------------------------------
** Ilinois Institute of Technology
** Memory header File
** Author: Igor Lopes
** September 21st, 2015
** -------------------------------------------------------------------------*/
#include <iostream>
#include <ctime> //ctime function used with Random.
#include <cstdlib> //Random function.

using namespace std;

class Memory{
private:
  int minSize;
  int maxSize;
  int staticSize;
  bool isStatic;
public:
  Memory(int min, int max, int statSize, bool isStat){
    srand(time(0)); //Sets the seed
    minSize = min;
    maxSize = max;
    staticSize = statSize;
    isStatic = isStat;
  }
  int getSize();
  char getChar();
  void allocDynamic();
  void allocStatic();
  void debugValues();
};
