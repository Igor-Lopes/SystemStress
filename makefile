CC=g++
CFLAGS=-c -Wall
APP=sysstress
OBJ=main.o parameters.o memory.o cpu.o

$(APP): $(OBJ)
	$(CC) $(OBJ) -o $(APP) -lpthread
main.o: main.cpp parameters.h memory.h cpu.h
	$(CC) -c -std=c++11 main.cpp -lpthread
parameters.o: parameters.cpp parameters.h
	$(CC) -c -std=c++11 parameters.cpp 
memory.o: memory.cpp memory.h
	$(CC) -c memory.cpp
cpu.o: cpu.cpp cpu.h
	$(CC) -c cpu.cpp
clean:
	$(RM) $(OBJ)
	
	
