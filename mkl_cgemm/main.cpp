
#include <iostream>
#include <mkl_vsl.h>
#include <mkl.h>

using namespace std;
int main()
{
	int row_a = 2;
	int col_a = 3;

	int row_b = 3;
	int col_b = 4;

	MKL_Complex8 a[row_a * col_a];
	MKL_Complex8 b[row_b * col_b];
	MKL_Complex8 c[row_a * col_b];
	MKL_Complex8 alpha;
	MKL_Complex8 beta;
	alpha.real = 1;
	alpha.imag = 0;
	beta.real = 0;
	beta.imag = 0;

	/*
	Store in column base
	[ 1 2 3 ]
	[ 4 5 6 ]
	*/

	a[0].real = 1;
	a[1].real = 4;
	a[2].real = 2;
	a[3].real = 5;
	a[4].real = 3;
	a[5].real = 6;
	a[0].imag = 1;
	a[1].imag = 4;
	a[2].imag = 2;
	a[3].imag = 5;
	a[4].imag = 3;
	a[5].imag = 6;
	
	/*
	Store in row based
	[ 1  2  3  4 ]
	[ 5  6  7  8 ]
	[ 9 10 11 12 ]
	*/

	b[0].real = 1;
	b[1].real = 2;
	b[2].real = 3;
	b[3].real = 4;
	b[4].real = 5;
	b[5].real = 6;
	b[6].real = 7;
	b[7].real = 8;
	b[8].real = 9;
	b[9].real = 10;
	b[10].real = 11;
	b[11].real = 12;
	b[0].imag = 1;
	b[1].imag = 2;
	b[2].imag = 3;
	b[3].imag = 4;
	b[4].imag = 5;
	b[5].imag = 6;
	b[6].imag = 7;
	b[7].imag = 8;
	b[8].imag = 9;
	b[9].imag = 10;
	b[10].imag = 11;
	b[11].imag = 12;

	

	cblas_cgemm(CblasColMajor,
				CblasNoTrans,   		//const CBLAS_TRANSPOSE transa,
				CblasTrans,				//const CBLAS_TRANSPOSE transb,
				row_a,					//const MKL_INT m,
				col_b,					//const MKL_INT n,
				col_a,					//const MKL_INT k,
				&alpha, 				//const void *alpha,
				a,						//const void *a,
				row_a,					//const MKL_INT lda,
				b,						// const void *b,
				col_b,					//const MKL_INT ldb,
				&beta,  				// const void *beta,
				&c,						//void *c,
				row_a);					//const MKL_INT ldc

	for (int i = 0; i < row_a*col_b; i++)
	{
		cout<< c[i].real << " " << c[i].imag << endl;
	}			
}