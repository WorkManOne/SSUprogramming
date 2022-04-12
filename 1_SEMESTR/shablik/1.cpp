#include <iostream>
#include <time.h>
using namespace std;

template <typename T, typename T1> //шаблон
T** input_arr(T c, T1 n, T1 m) { //функция на ввод массива с типом размерности и типом массива
	T** arr = new T* [n];
	for (int i = 0; i < n; ++i)
		arr[i] = new T[m];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j]; //ввод элементов
	return arr;
}

template <typename T, typename T1> //шаблон
void output_arr(T** arr, T1 n, T1 m) { //функция на вывод массива
	for (int i = 0; i < n; ++i, cout << endl)
		for (int j = 0; j < m; ++j)
			cout << arr[i][j] << " ";
}

template <typename T, typename T1>//шаблон
T **swap_arr(T** arr, T1 n) { //функция на смену строк массива с типом размерности и типом массива
	for (int i = 0; i < (n / 2); ++i) {
		swap(arr[i], arr[n - i - 1]); //меняем 1 строку с последней и т. д.
	}
	return arr;
}


int main() {
	setlocale(LC_ALL, "rus"); //Русская раскладка в консоли
	int c,n, m; //с - идентификатор типа массива n,m - размерности
	cout << "Введите размерность: ";
	cin >> n >> m; //ввод размерности
	cout << endl << "Введите тип (1 - int, 2 - double, 3 - char): ";
	cin >> c; //ввод типа, для каждого типа создастся свой массив и выполнится свап строк
	if (c == 1) {
		int** a = input_arr(c, n, m);
		output_arr(a, n, m); //вывод
		a = swap_arr(a, n);
		cout << "DONE!" << endl;
		output_arr(a, n, m); //выводим измененный массив
	}

	if (c == 2) {
		double d = 1;
		double** a = input_arr(d, n, m); //объявление массива
		output_arr(a, n, m); //вывод
		a = swap_arr(a, n);
		cout << "DONE!" << endl;
		output_arr(a, n, m); //выводим измененный массив
	}
	if (c == 3) {
		char d = 'a';
		char** a = input_arr(d, n, m); //объявление массива
		output_arr(a, n, m); //вывод
		a = swap_arr(a, n);
		cout << "DONE!" << endl;
		output_arr(a, n, m); //выводим измененный массив
	}
	
	return 0;
}