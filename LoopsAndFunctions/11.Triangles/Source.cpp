#include <iostream>

using namespace std;

bool isValidTriangle(double a, double b, double c)
{
	bool arePositive = a > 0 && b > 0 && c > 0;

	return arePositive && a + b > c && a + c > b && b + c > a;
}

double getArea(double a, double b, double c)
{
	double p = (a + b + c) / 2;

	return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main()
{
	int n;
	double a, b, c;
	cin >> n;
	double max = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		
		if (isValidTriangle(a, b, c))
		{
			double area = getArea(a, b, c);

			if (area > max)
			{
				max = area;
			}
		}
		else
		{
			cout << "Invalid triangle" << endl;
		}
	}

	cout << max << endl;

	return 0;
}