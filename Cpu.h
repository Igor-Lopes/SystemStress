#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <ctime>

using namespace std;

class Cpu{
public:
	int getPid(){
		return getpid();
	}

	int stressCpu(){
		int i = 0;
		for(;;){
			i++;
			//if(i > 2000000){
			//	i = 0;
			//}
		}
	return i;
	}
};

