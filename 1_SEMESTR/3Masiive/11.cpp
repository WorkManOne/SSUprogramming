#include <iostream>

using namespace std;

int** arr_input(int n) { //функция ввода двумерного массивуги
	int** arr = new int* [n];
	for (int i = 0; i < n; ++i) {
		arr[i] = new int[i + 1];
	}
	return arr;
}

void arr_output(int** arr, int n) { //функция вывода двумерного массивуги
	for (int i = 0; i < n; ++i, cout << endl)
		for (int j = 0; j < i + 1; ++j)
			cout << arr[i][j] << " ";
}

int main() {
	setlocale(LC_ALL, "rus"); //руссиано
	int n;
	cout << "Введите n: "; //степень многочлена n
	cin >> n;
	cout << endl << "Треугольник Паскаля: " << endl; //построение треугольника паскаля
	int** a = arr_input(15 + 1);
	for (int i = 0; i <= 15; ++i) //все как в реальной математике
		for (int j = 0; j < i + 1; ++j) {
			if ((j == 0) || (j == i)) a[i][j] = 1; //первое и последнее по 1
			else {
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j]; //остальные получаем из тех, которые сверху предыдущего и надстоящего
			}
		}
	arr_output(a, 15 + 1); //вывод треугольника
	cout << endl << "коэффициенты многочлена (1 + x)^" << n << ": "; 
	for (int j = 0; j <= n; ++j) cout << a[n][j] << " "; //вывод n строки
	return 0;
}