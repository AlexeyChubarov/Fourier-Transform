#define _USE_MATH_DEFINES

#include <cmath>
#include "_complex.h"

#include <iostream>

#define eps 1e-6

using namespace complex_num;
complex_num::trig_complex_t::trig_complex_t(double Abs, double Arg)
{
	this->abs = Abs;
	this->arg = Arg;
}

complex_num::trig_complex_t::trig_complex_t(trig_complex_t * a)
{
	this->abs = a->abs;
	this->arg = a->arg;
}

trig_complex_t & complex_num::trig_complex_t::operator=(trig_complex_t  a)
{
	this->abs = a.abs;
	this->arg = a.arg;
	return *this;
}

complex_num::trig_complex_t::operator std_complex_t()
{
	std_complex_t a;
	a.re = this->abs*cos(this->arg);
	a.im = this->abs*sin(this->arg);
	return a;
}


void complex_num::trig_complex_t::scan()
{
	std::cin >> abs >> arg;
}

void complex_num::trig_complex_t::print()
{
	std::cout << (!(::abs(this->abs)<eps)? this->abs:0) << "*exp(i*(" << arg << "))";
}

complex_num::std_complex_t::std_complex_t(double Re, double Im)
{
	re = Re;
	im = Im;
}

complex_num::std_complex_t::std_complex_t(std_complex_t* a)
{
	re = a->re;
	im = a->im;

}


std_complex_t& complex_num::std_complex_t::operator=(std_complex_t a)
{
	re = a.re;
	im = a.im;
	return *this;
}


std_complex_t complex_num::operator!(std_complex_t a)
{
	return {a.re,-a.im};
}

std_complex_t complex_num::operator+(std_complex_t left, std_complex_t right)
{
	return { left.re + right.re ,left.im + right.im };
}

std_complex_t complex_num::operator-(std_complex_t  left, std_complex_t  right)
{
	return { left.re - right.re ,left.im - right.im };
}

std_complex_t complex_num::operator*(std_complex_t  left, std_complex_t  right)
{
	return  {left.re*right.re - left.im*right.im,left.im*right.re + left.re*right.im};
}

std_complex_t complex_num::operator/(std_complex_t  left, std_complex_t  right)
{
	return { (left.re*right.re + left.im*right.im) / (right.re*right.re + right.im*right.im),
		(right.re*left.im - right.im*left.re) / (right.re*right.re + right.im*right.im) };
}

trig_complex_t complex_num::operator!(trig_complex_t a)
{
	trig_complex_t b = { a.abs,-a.arg };
	return b;
}

trig_complex_t complex_num::operator+(trig_complex_t  left, trig_complex_t  right)
{
	
	return trig_complex_t((std_complex_t)left + (std_complex_t)right);
}

trig_complex_t complex_num::operator-(trig_complex_t left, trig_complex_t right)
{
	return trig_complex_t((std_complex_t)left + (std_complex_t)right);
}

trig_complex_t complex_num::operator*(trig_complex_t  left, trig_complex_t right)
{
	return { left.abs*right.abs,left.arg + right.arg };
}

trig_complex_t complex_num::operator/(trig_complex_t left, trig_complex_t right)
{
	return {left.abs / right.abs,left.arg - right.arg };
}

complex_num::std_complex_t::operator trig_complex_t()
{

	trig_complex_t a;
	a.abs = pow(this->re*this->re + this->im*this->im,0.5);
	a.arg =(abs(re)<eps && abs(im)<eps )?(0):((re > 0) ? (atan(im / re)) : (((re < 0) && (im >= 0)) ? (atan(im / re) + M_PI) : (atan(im / re) - M_PI)));
	return a;
}

void complex_num::std_complex_t::scan()
{
	std::cin >> this->re >> this->im;
}

void complex_num::std_complex_t::print()
{
	std::cout << (!(abs(this->re) < eps) ? this->re:0) << "+i*(" << (!(abs(this->im) < eps) ? this->im : 0)<<')';
}


