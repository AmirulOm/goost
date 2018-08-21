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
	icc $(DEBUG_FLAG) $(subst ../,,$(SEGY_INCLUDE_PATH)) -c main.cpp $(CPP_FLAGS)  $(OPT_FLAG) -I. -openmp -liomp5 -lpthread -lm -ldl -DMKL_ILP64 -o main.o 
	icc $(DEBUG_FLAG) -Wl,--start-group ${MKLROOT}/lib/intel64/libmkl_intel_lp64.a ${MKLROOT}/lib/intel64/libmkl_sequential.a ${MKLROOT}/lib/intel64/libmkl_core.a  *.o -Wl,--end-group  -DMKL_ILP64 -mkl=parallel -liomp5 -lpthread -lm -ldl -openmp $(OPT_FLAG) -o svdExample.out

clean:
	rm -f obj/*.o