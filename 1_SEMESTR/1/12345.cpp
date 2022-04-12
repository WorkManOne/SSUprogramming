#include <iostream>
using namespace std;

int main() {
	int i, n;
	cout << "BIT : ";
	cin >> i;
	cout << "NUMBER : ";
	cin >> n;
	cout << "1: " << (1 << i) << endl;
	cout << "2: " << ((1 << i) | n) << endl;
	cout << "3: " << (~(1 << i) & n) << endl;
	cout << "4: " << ((1 << i) ^ n) << endl;
	if ((n & 1) == 0)
		cout << "5: YES";
	else
		cout << "5: NO";
	return 0;
}