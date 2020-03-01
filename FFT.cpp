#define _USE_MATH_DEFINES

#include "_complex.h"
#include "FFT.h"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
using namespace Fourier_transform;
using namespace complex_num;

vector<std_complex_t> Fourier_transform::fast_transform(vector<std_complex_t>& input)
{
	//Addin the vector to the desired size
	vector<std_complex_t> _input(input);
	int input_n = (_input).size();
	while ((bool)((input_n - 1)&input_n) || (input_n <= 1))
	{
		static std_complex_t id(0, 0);
		(_input).push_back(id);
		input_n++;
	}
	//__________________________________________
	//Fast Fourier Transform algorithm
	vector<std_complex_t> _result(input_n);
	
	if (input_n==2)
	{
	_result[0] = _input[0] + _input[1];
	_result[1] = _input[0] - _input[1];
	}
	else
	{
		int m = input_n >> 1;

		vector<std_complex_t> _even(m);
		vector<std_complex_t>_odd(m);
		for (int i = 0; i < m; i++)
		{
			static int q;
			q = i << 1;
			_even[i] = _input[q];
			_odd[i] = _input[q + 1];
		}

		vector<std_complex_t> even = fast_transform(_even);
		vector<std_complex_t> odd = fast_transform(_odd);
		std_complex_t W;
		for (int k = 0; k < m; k++)
		{
			W.re = cos(-(2 * M_PI / input_n)*k);
			W.im = sin(-(2 * M_PI / input_n)*k);
				_result[k] = even[k] + W*odd[k];
				_result[k+m] = even[k] - W*odd[k];
		}
	}
	return _result;
}
