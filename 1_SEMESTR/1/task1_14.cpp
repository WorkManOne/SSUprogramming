#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int s, x, y;
	cin >> x;
	s = ((x / 100) * ((x / 10) % 10) * (x % 10)) % ((x / 100) + ((x / 10) % 10) + (x % 10));	
	y = (x / 100) * 100 + (x % 10) * 10 + ((x / 10) % 10);
	cout << "ost = " << s << '\n' << "y = " << y;
	return 0;
}