/* ---------------------------------------------------------------------------
** Ilinois Institute of Technology
** Memory cpp File
** Author: Igor Lopes
** September 21st, 2015
** -------------------------------------------------------------------------*/
#include <ctime> //ctime function used with Random.
#include <cstdlib> //Random function.
//------------------Header--------------------------------------------------
#include "memory.h"

using namespace std;

int Memory::getSize(){ return rand() % maxSize + minSize; }

char Memory::getChar(){
	const char alphabet[]=
	"abcdefghijklmnopqrstuvwxyz"
	"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	"0123456789";
	int lenght = sizeof (alphabet) - 1;

	return alphabet[rand() % lenght];
}

void Memory::allocDynamic(){
	int size = getSize() * 1000;
	char *pchar;
	pchar = (char*) malloc (size);
	for(int i = 0; i < size; i++){
		pchar[i] = getChar();
	}
	cout << "Memory Allocated: " << size << "bytes" << endl;
}

void Memory::allocStatic(){
	int size = staticSize * 1000;
	char *pchar;
	pchar = (char*) malloc (size);
	for(int i = 0; i < size; i++){
		pchar[i] = getChar();
	}
	cout << "Memory Allocated: " << size << "bytes" << endl;
}

void Memory::debugValues(){ //Print the values of the variables passed to this class.
	cout <<"Min Size:"<< minSize <<endl;
	cout <<"Max Size:"<< maxSize <<endl;
	cout <<"Static Size:"<< staticSize <<endl;
	if(isStatic){
		cout << "Static: true" <<endl;
	} else {
		cout << "Static: false" <<endl;
	}
}
