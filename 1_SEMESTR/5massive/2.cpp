#include <iostream>
#include <time.h>
using namespace std;

int** arr_input(int n,int m) { //функция ввода массива
	int** arr = new int* [n];
	for (int i = 0; i < n; ++i) {
		arr[i] = new int[m];
	}
	return arr;
}

void arr_output(int **arr, int n,int m) { //функция вывода массива
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
	int** a = arr_input(n*2,m);
	srand(time(0)); //обнуление рандомизатора
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[i][j] = rand() % 10 + 1; //присваиваем случайные значения элементам матрицы
		}
	}
	arr_output(a, n, m); //показываем массив
	for (int i = 0; i < n; ++i) { //анализируем построчно
		int f = 0; //флаг
		for (int j = 0; j < m; ++j) {
			if (a[i][j] % 2 == 0) { //если в строке хотя бы 1 элемент четный, поднимаем флаг
				f = 1;
				break;
			}
		}
		if (f == 0) { //если все элементы нечетные, то с конца начинаем "перетяжку" строк
			for (int j = n; j > i; --j) {
				a[j] = a[j - 1];
			}
			++i; //пропускаем след строку поскольку она скопированна и переходим к след.
			++n; //т.к. сместили строки на 1 вниз, то и идти надо на n+1 больше
		}
		
	}
	arr_output(a, n, m); //вывод конечного массива
	return 0;
}