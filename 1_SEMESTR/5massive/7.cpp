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
	int** a = arr_input(n,m*2);
	srand(time(0)); //обнуление рандомизатора
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[i][j] = rand() % 10 + 1; //присваиваем случайные значения элементам матрицы
		}
	}
	arr_output(a, n, m); //показываем массив
	for (int j = 0; j < m; ++j) { //анализируем постолбично
		int f = 0; //флаг
		for (int i = 0; i < n; ++i) {
			if (a[i][j] % 2 != 0) { //если в столбце хотя бы 1 элемент нечетный, поднимаем флаг
				f = 1;
				break;
			}
		}
		if (f == 0) { //если все элементы четные, то с конца строк начинаем "перетяжку" элементов в каждой строке
			for (int i = 0; i < n; ++i)
				for (int k = m; k > j; --k) {
					a[i][k] = a[i][k-1];
			}
			++j; //пропускаем след столбец поскольку он скопирован и переходим к след.
			++m; //т.к. сместили столбцы на 1 вправо, то и идти надо на m+1 больше
		}
		
	}
	arr_output(a, n, m); //вывод конечного массива
	return 0;
}