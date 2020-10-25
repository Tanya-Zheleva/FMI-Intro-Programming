#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x = 0, y = 0;
	cin >> x1 >> y1 >> x2 >> y2 >> x >> y;

	int distance = 0;

	if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
	{
		cout << "distance=" << distance << endl;
	}
	else
	{
		if (x > x1 && x < x2 && y < y1) //Bottom
		{
			distance = abs(y1 - y);
		}
		else if (x > x1 && x < x2 && y > y2) //Top
		{
			distance = abs(y - y2);
		}
		else if (y > y1 && y < y2 && x < x1) //Left
		{
			distance = abs(x1 - x);
		}
		else if (y > y1 && y < y2 && x > x2) //Right
		{
			distance = abs(x - x2);
		}
		else if (x < x1 && y > y2) //Top left
		{
			distance = abs(x1 - x) * abs(x1 - x) + abs(y - y2) * abs(y - y2);
		}
		else if (x > x2 && y > y2) //Top right
		{
			distance = abs(x - x2) * abs(x - x2) + abs(y - y2) * abs(y - y2);
		}
		else if (x < x1 && y < y1) //Bottom left
		{
			distance = abs(x1 - x) * abs(x1 - x) + abs(y1 - y) * abs(y1 - y);
		}
		else if (x > x2 && y < y1) //Bottom right
		{
			distance = abs(x - x2) * abs(x - x2) + abs(y1 - y) * abs(y1 - y);
		}

		cout << "distance=" << distance << endl;
	}

	return 0;
}