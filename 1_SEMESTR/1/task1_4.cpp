#include <iostream>
#include <math.h>
using namespace std;

int main() {
	float x, y;
	cin >> x >> y;
	float f;
	f = (1.0 / 3) * sqrt((exp(x * x + y * y) + 5 * x) / cos((x + y) * (x + y))) + x / y;
	cout << f;
	return 0;
}