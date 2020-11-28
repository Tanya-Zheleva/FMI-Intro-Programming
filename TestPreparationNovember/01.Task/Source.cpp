#include <iostream>
#include <cmath>

using namespace std;

double getDistanceBetweenPoints(double x1, double y1, double x2, double y2)
{
	double distance = pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2);

	return sqrt(distance);
}

bool isValidTriangle(double a, double b, double c)
{
	return a < b + c && b < a + c && c < a + b;
}

bool hasTwoEqualSides(double a, double b, double c)
{
	return a == b || b == c || c == a;
}

int main()
{
	double xA, yA, xB, yB, xC, yC;
	cin >> xA >> yA >> xB >> yB >> xC >> yC;

	double sideAB = getDistanceBetweenPoints(xA, yA, xB, yB);
	double sideBC = getDistanceBetweenPoints(xB, yB, xC, yC);
	double sideAC = getDistanceBetweenPoints(xA, yA, xC, yC);

	if (isValidTriangle(sideAB, sideBC, sideAC))
	{
		if (hasTwoEqualSides(sideAB, sideBC, sideAC))
		{
			cout << "Valid, has 2 equal sides" << endl;
		}
		else
		{
			cout << "Valid" << endl;
		}
	}
	else
	{
		cout << "Invalid" << endl;
	}

	return 0;
}