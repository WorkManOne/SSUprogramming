#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите n: ";
	cin >> n; //ввод n
	int* a = new int[n + 1]; //массив n+1
	for (int i = 0; i <= n; ++i) {
		cin >> a[i]; //ввод элементов массива (коэффициенты многочлена)
	}
	cout << endl;
	for (int i = 0; i <= n; ++i) {
		if ((n - i) * a[i] != 0) cout << (n - i) * a[i] << " "; //получение производной из элемента и его пор. номера
		else cout << ""; //вывод производной
	}
	return 0;
}