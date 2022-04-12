#include <iostream>
using namespace std;

int pol(int x, int n) { //функция с условиями
	if (n == 0) return 1;
	if (n == 1) return 2 * x;
	if ((n != 0) && (n != 1)) return 2 * x * pol(x, n - 1) - 2 * (n - 1) * pol(x, n - 2);
}

int pol2(int x, int n) {
	int h0 = 1;
	int h1 = 2 * x;
	int h;
	if (n == 0) return 1;
	if (n == 1) return 2*x;
	else {
		for (int i = 2; i <= n; ++i) {
			h = 2 * x * h1 - 2 * (i-1) * h0;
			h0 = h1; 
			h1 = h;	
		}
		return h;
	}
}

int main() {
	setlocale(LC_ALL, "rus"); //русская консоль
	int m, r; //вводим х и n
	cout << "Введите число x n: ";
	cin >> r >> m;
	cout << pol(r, m) << endl; //выводим полиному
	cout << pol2(r, m);
	return 0;
}