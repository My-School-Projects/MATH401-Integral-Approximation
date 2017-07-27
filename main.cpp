#include <iostream>
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
	cout << "Midpoint:  " << midpointRule(2) << endl;
	cout << "Trapezoid: " << trapezoidRule(2) << endl;
	cout << "Simpson's: " << simpsonsRule(2) << endl;

	while (true);
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
