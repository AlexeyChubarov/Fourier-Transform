#pragma once
#include <vector>
using namespace std;
using namespace complex_num;

namespace Fourier_transform 
{
	//Fast Fourier Transform
	vector<std_complex_t> fast_transform(vector<std_complex_t>& input);
}