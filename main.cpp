#define _USE_MATH_DEFINES

#include "_complex.h"
#include "FFT.h"
#include <iostream>
#include <cmath>
#include <vector>


using namespace std;
using namespace Fourier_transform;
using namespace complex_num;
int main()
{
	//example of use fast Fourier transform
	constexpr auto N = 1024;
	vector<std_complex_t> x(N);
	for (int i=0;i<N;i++)
	{
		x[i].re = sin((2*M_PI /N)*i);
		x[i].im = 0;

	}
	
	vector<std_complex_t> res = fast_transform(x);

	for (auto y : res)
	{
		y.print();
		cout << endl;
	}



	system("pause");
	return 0;
}