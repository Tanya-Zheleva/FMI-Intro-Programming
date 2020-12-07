#include <iostream>

using namespace std;

int main() 
{
	int a = 5, b = 4;
	int* pa = &a, * pb = &b, *p;
	
	cout << *pa << " " << *pb << endl;

	p = pa;
	pa = pb;
	pb = p;

	cout << *pa << " " << *pb << endl;

	return 0;
}