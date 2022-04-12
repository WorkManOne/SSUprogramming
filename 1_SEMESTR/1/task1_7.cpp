#include <iostream>
#include <math.h>
using namespace std;

int main() {
	float f, x, y;
	cin >> x >> y;
	f = exp(sqrt(log((x * x + y * y) / (cos(x) * cos(x) + cos(x * x)))));
	cout << f;
	return 0;
}