include Makefile.config
DEBUG_FLAG = 
OPT_FLAG = -O3
Release: all
debug: DEBUG_FLAG += -g
debug: OPT_FLAG = 
export DEBUG_FLAG
export OPT_FLAG
debug : all
all  : main

main:
	mpicc -cc=icc $(DEBUG_FLAG) -c main.cpp $(CPP_FLAGS)  $(OPT_FLAG) -o main.o 
	mpicc -cc=icc $(DEBUG_FLAG) *.o  $(OPT_FLAG) -o mpiExample.out

clean:
	rm -f obj/*.o