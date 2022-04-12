#include <iostream>
using namespace std;

int A(int m, int n) { //функция с условиями
	if (m == 0) return n+1;
	if ((n == 0) && (m>0)) return A(m-1, 1);
	if ((n > 0) && (m > 0)) return A(m - 1, A(m, n - 1)); //выражение нового члена, через предыдущие
}

int main() {
	setlocale(LC_ALL, "rus"); //русская консоль
	int a,r; //ввод m и n
	cout << "Введите число m n: ";
	cin >> r >> a;
	cout << A(r,a);
	return 0;
}