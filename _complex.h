#pragma once

namespace complex_num 
{
	//define complex numbers and arithmetic with them
	class std_complex_t;
	class trig_complex_t;

	class std_complex_t
	{
	public:
		double re;
		double im;

		std_complex_t()
		{
			re = 0;
			im = 0;
		}
		std_complex_t(double, double);
		std_complex_t(std_complex_t*);

		std_complex_t& operator=(std_complex_t);
		operator trig_complex_t();
		void scan();
		void print();
	};


	std_complex_t operator!(std_complex_t);

	std_complex_t operator+(std_complex_t left, std_complex_t right);
	std_complex_t operator-(std_complex_t left, std_complex_t right);
	std_complex_t operator*(std_complex_t left, std_complex_t right);
	std_complex_t operator/(std_complex_t left, std_complex_t right);



	class trig_complex_t
	{
	public:
		double abs;
		double arg;

		trig_complex_t()
		{
			abs = 0;
			arg = 0;
		}
		trig_complex_t(double, double);
		trig_complex_t(trig_complex_t*);

		trig_complex_t& operator= (trig_complex_t a);
		operator std_complex_t();

		void scan();
		void print();
	};

	trig_complex_t operator!(trig_complex_t);

	trig_complex_t operator+(trig_complex_t left, trig_complex_t right);
	trig_complex_t operator-(trig_complex_t left, trig_complex_t right);
	trig_complex_t operator*(trig_complex_t left, trig_complex_t right);
	trig_complex_t operator/(trig_complex_t left, trig_complex_t right);

}
