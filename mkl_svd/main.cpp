// Author : amirul.

#include <iostream>
#include <mkl_vsl.h>
#include <mkl.h>
#define min(a,b) ((a)>(b)?(b):(a))

using namespace std;

int main()
{
	/* Locals */
	MKL_INT m = 2, n = 3, lda = m, ldu = m, ldvt = n, info;
	/* Local arrays */
	float s[m];
	float superb[min(m,n)-1];
	float u[ldu*m], vt[ldvt*n];
	float a[lda*n] ;

	/*
	a = [ 3  2  2 ]
		[ 2  3 -2 ]
	*/

	a[0] = 3;
	a[1] = 2;
	a[2] = 2;
	a[3] = 3;
	a[4] = 2;
	a[5] = -2;

	cout << "a input :\n";
	for (int i = 0; i <lda*n; i++)
	{
		cout << a[i] <<endl;
	}

	/* Executable statements */
	//printf( "LAPACKE_cgesvd (column-major, high-level) Example Program Results\n" );
	/* Compute SVD */
	info = LAPACKE_sgesvd( LAPACK_COL_MAJOR, 'A', 'A', m, n, a, lda, s, u, ldu, vt, ldvt, superb );
   
	cout << "\n\nResult\ns output :\n";
	for (int i = 0; i < m; i++)
	{
		cout << s[i] <<endl;
	}		
	
	cout << "\nu output :\n";
	for (int i = 0; i < ldu*m; i++)
	{
		cout << u[i] <<endl;
	}

	cout << "\nvt output :\n";
	for (int i = 0; i < ldvt*n; i++)
	{
		cout << vt[i] <<endl;
	}

	/* 
	Results				Math			Actual Result
	------------------------------------------------------
	*s@2
	[2]
	[0]:5								5
	[1]:2.99999976						3
	*u@4
	[4]
	[0]:-0.70710665		-1/sqrt(2)		1/sqrt(2)
	[1]:-0.707106888	-1/sqrt(2)		1/sqrt(2)
	[2]:-0.707106888	-1/sqrt(2)		1/sqrt(2)
	[3]:0.70710665		1/sqrt(2)		-1/sqrt(2)
	*vt@9
	[9]
	[0]:-0.707106829	-1/sqrt(2)		1/sqrt(2)
	[1]:-0.235702321	-1/sqrt(18)		1/sqrt(18)
	[2]:-0.666666687	-2/3			2/3
	[3]:-0.707106888	-1/sqrt(2)		1/sqrt(2)
	[4]:0.235702232		1/sqrt(18)		-1/sqrt(18)
	[5]:0.666666687		2/3				-2/3
	[6]:4.8959933e-08	0				0
	[7]:-0.942809105	-2/sqrt(18)		2/sqrt(18)
	[8]:0.333333313		1/3				-1/3

	Refer to www.d.umn.edu/~mhampton/m4326svd_example.pdf
	*/
}