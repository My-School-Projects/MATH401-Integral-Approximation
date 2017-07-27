#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

float midpointRule(int);
float trapezoidRule(int);
float simpsonsRule(int);
float midpoint(int, int);
float f(float);
float x(int, int);
float deltaX(int);

const float interval_start = 0;
const float interval_end = 2;
const float interval = interval_end - interval_start;

int main()
{
	ofstream fout;
	fout.open("Output.txt");

	fout << left
		<< setw(4) << "n"
		<< setw(15) << "Midpoint Rule"
		<< setw(15) << "Trapezoid Rule"
		<< setw(15) << "Simpson's Rule"
		<< endl;

	for (int n = 2; n <= 20; n += 2)
	{
		fout << left
			<< setw(4) << n
			<< setw(15) << midpointRule(n)
			<< setw(15) << trapezoidRule(n)
			<< setw(15) << simpsonsRule(n) << endl;
	}

	fout.close();
}

float midpointRule(int n)
{
	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += f(midpoint(i, n)) * deltaX(n);
	}
	return sum;
}

float trapezoidRule(int n)
{
	float sum = f(x(0, n));
	for (int i = 1; i < n; i++)
	{
		sum += 2 * f(x(i, n));
	}
	sum += f(x(n, n));
	sum *= interval / (2 * n);
	return sum;
}

float simpsonsRule(int n)
{
	float sum = f(x(0, n));
	for (int i = 1; i < n; i++)
	{
		int coefficient = (i % 2) ? 4 : 2;
		sum += coefficient * f(x(i, n));
	}
	sum += f(x(n, n));
	sum *= interval / (3 * n);
	return sum;
}

float x(int i, int n)
{
	return (interval * i) / n;
}

float deltaX(int n)
{
	return (interval_end - interval_start) / n;
}

float midpoint(int i, int n)
{
	return (interval * (2 * i + 1)) / (2 * n);
}

float f(float x)
{
	return 1 / sqrt(1 + x * x * x);
}
