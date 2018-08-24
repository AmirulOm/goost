#include <iostream>
#include <string>
#include <mpi.h>

using namespace std;

int main(int argc, char *argv[])
{

	int status;
	int tag;
	int rank = 0;
	int num_procs = 0;
	int required = MPI_THREAD_SERIALIZED;
	int provided;

	status = MPI_Init_thread(&argc, &argv, required, &provided);
	status = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	status = MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

	cout << "hi, my rank is" << rank << endl;

	return 0;
}