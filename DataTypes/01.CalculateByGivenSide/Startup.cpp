#include <iostream>

using namespace std;

int main()
{
	int a = 0;
	cin >> a;

	int squarePerimeter = 4 * a;
	int squareArea = a * a;

	double circleCircumference = 2 * 3.14 * a;

	int trianglePerimeter = 3 * a;
	double triangleArea = 1.73 * a * a / 4;

	cout << "square: p=" << squarePerimeter << " s=" << squareArea << endl;
	cout << "circle: p=" << circleCircumference << endl;
	cout << "triangle: p=" << trianglePerimeter << " s=" << triangleArea << endl;

	return 0;
}