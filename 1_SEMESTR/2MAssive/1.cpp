#include <iostream>
#include <time.h>
using namespace std;

int** input_arr(int n, int m) { //функция на ввод массива
	int** arr = new int* [n];
	for (int i = 0; i < n; ++i)
		arr[i] = new int[m];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			arr[i][j] = i;
	return arr;
}


void output_arr(int** arr, int n, int m) { //функция на вывод массива
	for (int i = 0; i < n; ++i, cout << endl)
		for (int j = 0; j < m; ++j)
			cout << arr[i][j] << " ";
}


int main() {
	setlocale(LC_ALL, "rus"); //Русская раскладка в консоли
	srand(time(0)); //обнуление рандоизатора
	int n, m;
	cin >> n >> m; //ввод размерности
	int** a = input_arr(n, m); //объявление массива
	output_arr(a, n, m); //вывод
	for (int i = 0; i < (n / 2); ++i) {
		swap(a[i], a[n - i - 1]); //меняем 1 строку с последней и т. д.
	}
	cout << "DONE!" << endl;
	output_arr(a, n, m); //выводим измененный массив
	return 0;
}