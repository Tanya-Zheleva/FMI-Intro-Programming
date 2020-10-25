#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double x = 0, y = 0;
	cin >> x >> y;

	bool inRectangle = x >= -6 && x <= -2 && y >= 2 && y <= 5;
	bool inCircle = pow(abs(x - 4), 2) + pow(abs(y - 2), 2) <= 1; //pow(2, 3) => 2 ^ 3

	if (inRectangle)
	{
		cout << "Inside rectangle" << endl;
	}
	else if (inCircle)
	{
		cout << "Inside circle" << endl;
	}
	else
	{
		const double x1 = -2, y1 = -4, x2 = 6, y2 = -2, x3 = 0, y3 = -1;

		//Calculate area of HIG triangle
		double area = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2);

		//Calculate area of PIG triangle, where P is the point with coordinates x, y
		double area1 = abs((x * (y2 - y3) + x2 * (y3 - y) + x3 * (y - y2)) / 2);

		//Calculate area of PHG triangle
		double area2 = abs((x1 * (y - y3) + x * (y3 - y1) + x3 * (y1 - y)) / 2);

		//Calculate area of PHI triangle
		double area3 = abs((x1 * (y2 - y) + x2 * (y - y1) + x * (y1 - y2)) / 2);

		area == area1 + area2 + area3
			? cout << "Inside triangle" << endl
			: cout << "Not part of any figure" << endl;
	}

	return 0;
}