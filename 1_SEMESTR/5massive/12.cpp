#include <iostream>
#include <time.h>
using namespace std;

int** arr_input(int n, int m) { //функция ввода массива
	int** arr = new int* [n];
	for (int i = 0; i < n; ++i) {
		arr[i] = new int[m];
	}
	return arr;
}

void arr_output(int** arr, int n, int m) { //функция вывода массива
	for (int i = 0; i < n; ++i, cout << endl) {
		for (int j = 0; j < m; ++j) {
			cout << arr[i][j] << " ";
		}
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "rus"); //русская консоль
	int n; //размерность массива
	cin >> n;
	int m = n; //для удобства вывода и обработки(ну без нее не получается)
	int** a = arr_input(n, m);
	srand(time(0)); //обнуление рандомизатора
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[i][j] = rand() % 19 - 9; //присваиваем случайные значения элементам матрицы
		}
	}
	arr_output(a, n, m); //показываем массив
	for (int i = 0; i < n; ++i) { //анализируем построчно
		int f = 1; //флаг
		for (int j = 0; j < m; ++j) {
			if (a[i][j] < 0) { //если в строке хотя бы 1 элемент отрицательный, опускаем флаг
				f = 0;
				break;
			}
		}
		if (f == 1) { //если все элементы положительные, начинаем "перетяжку" строк на эту строку
			for (int j = i; j < n; ++j) {
				a[j] = a[j + 1];
			}
			--i; //перепроверяем смещенную строку
			--n; //т.к. сместили строки на 1 вверх, то и анализировать надо до n-1 
		}

	}
	arr_output(a, n, m); //вывод конечного массива
	return 0;
}