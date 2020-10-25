#include <iostream>

using namespace std;

int main()
{
	double x1 = 0, y1 = 0, x2 = 0, y2 = 0, x = 0, y = 0;
	cin >> x1 >> y1 >> x2 >> y2 >> x >> y;

	if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
	{
		cout << "Point in rectangle" << endl;
	}
	else
	{
		cout << "Point outside rectangle" << endl;
	}

	return 0;
}