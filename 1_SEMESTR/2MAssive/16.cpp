#include <iostream>
using namespace std;

int** input_arr(int n) { //функция ввода массива
	int **arr = new int* [n];
	for (int i = 0; i < n; ++i)
		arr[i] = new int[n];
	int c = n*n-1, m;
	if (n%2!=0) //проверенно практикой, с какой стороны надо начинать при каком n
		for (int i = 0; i < n; ++i) {
			if (i % 2 == 0) //если строка четная то вводим слева направо, иначе справа налево
				for (int j = 0; j < n; ++j) {
					arr[i][j] = c;
					--c;
				}
			else 
				for (int j = n-1; j > -1; --j) {
					arr[i][j] = c;
					--c;
				}
		}
	else
		for (int i = 0; i < n; ++i) {
			if (i % 2 == 0) //если строка четная то вводим справа налево, иначе слева направо (проверенно)
				for (int j = n - 1; j > -1; --j) {
					arr[i][j] = c;
					--c;
				}
			else
				for (int j = 0; j < n; ++j) {
					arr[i][j] = c;
					--c;
				}
		}
	return arr;
}

void output_arr(int** arr, int n) { //функция вывода массива
	for (int i = 0; i < n; ++i, cout << endl)
		for (int j = 0; j < n; ++j)
			cout << arr[i][j] << " ";
}
int main() {
	setlocale(LC_ALL, "rus"); //Русская раскладка в консоли
	int **a = input_arr(9); //объявление массива
	output_arr(a, 9); //вывод
	return 0;
}