#include <iostream>
#include <time.h>
using namespace std;

int** input_arr(int n, int m) { //функция ввода массива
	int **arr = new int* [n];
	for (int i = 0; i < n; ++i)
		arr[i] = new int[m];
	srand(time(0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			arr[i][j] = rand()% 10; //заполнение случайными элементами от 0 до 10
	return arr;
}

void output_arr(int** arr, int n, int m) { //функция вывода массива
	for (int i = 0; i < n; ++i, cout << endl)
		for (int j = 0; j < m; ++j)
			cout << arr[i][j] << " ";
}
int main() {
	setlocale(LC_ALL, "rus"); //Русская раскладка в консоли
	int n, m, nem, mx = 0, mn, mxi = 0, mxj = 0, f = 0; //размерности, спец.счетчик не m,макс, мин, строка максимального, столбик максимального, флаг замены.
	cin >> n >> m;
	nem = m; //nem используется для выбора нужных элементов из матрицы
	int **a = input_arr(n, m); //ввод массива
	mn = a[1][m-1]; //пусть будет так
	output_arr(a, n, m); //вывод массива
	cout << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < nem; ++j) 
			if (a[i][j] > mx) {
				mx = a[i][j];
				mxi = i;
				mxj = j; //находим максимальный, запоминаем его расположение
			}
		nem -= 1;
	}
	nem = m;
	for (int i = 0; i < n; ++i) {
		for (int j = nem; j < m; ++j)
			if (a[i][j] < mn) {
				mn = a[i][j]; //находим мин и запоминаем его значение
			}
		nem -= 1;
	}
	nem = m;
	for (int i = 0; i < n; ++i) {
		for (int j = nem; j < m; ++j) {
			if (a[i][j] == mn) {
				swap(a[i][j], a[mxi][mxj]); //т.к нужен первый минимальный, то если находим значение равное то меняем его местами с максимальным и прерываем перебор.
				f = 1; //флаг для прерывания 2 цикла
				break;
			}
		}
		if (f == 1) break; //прерывание 2 цикла
		nem -= 1;
	}
	output_arr(a, n, m); //вывод измененного массива
	return 0;
}