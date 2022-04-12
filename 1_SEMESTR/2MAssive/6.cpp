#include <iostream>
#include <time.h>
using namespace std;
int **input_arr(int n, int m) { //функция ввода массива
	int** arr = new int* [n];
	for (int i = 0; i < n; ++i)
		arr[i] = new int[m];
	srand(time(0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			arr[i][j] = rand() % 10;
	return arr;
}
void output_arr(int **arr, int n, int m) { //функция вывода массива
	for (int i = 0; i < n; ++i, cout << endl)
		for (int j = 0; j < m; ++j)
			cout << arr[i][j] << " ";
}
int main() {
	setlocale(LC_ALL, "rus"); //Русская раскладка в консоли
	int n, m, mx, mn, mxi,mni; //размерности, макс, мин, строка максимального, строка минимального
	cin >> n >> m;
	int **a = input_arr(n, m); //ввод массива
	output_arr(a, n, m); //вывод массива
	cout << endl;
	mn = a[0][0]; //пусть будет так, тогда ничего не поменяется, в случае еслии не будет мин и макс
	mx = a[0][0];
	mxi = 0;
	mni = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (a[i][j] > mx) {
				mx = a[i][j];
				mxi = i; //находим макс и запоминаем строку с ним
			}
			if (a[i][j] < mn) {
				mn = a[i][j];
				mni = i; //находим мин и запоминаем строку с ним
			}
		}
	swap(a[mxi], a[mni]); //меняем строки макс и мин
	output_arr(a, n, m); //выводим массив
	return 0;
}