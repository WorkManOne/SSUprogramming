#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream in("datac.txt"); //вводим файл
ofstream out("datout.txt"); //вывод в файл

void print_m(int** m, int n) { //функция вывода массива
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			out << m[i][j] << " ";
		}
		out << endl;
	}
}

int** input_m(int n) { //функция ввода массива
	string str;
	string line;
	string s;
	int j = 0;
	int** m;
	m = new int* [n];
	for (int i = 0; i < n; i++) m[i] = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			in >> m[i][j];
		}
	}
	return m;
}

int** sort_m(int** m, int n) { //сортировка подсчетом
	
	int c;
	int mn;
	int mx;
	int size;
	for (int i = 0; i < n; i++) { //определяем макс и мин, 
		mx = m[i][0];
		mn = m[i][0];
		for (int j = 0; j < n; j++) {
			if (m[i][j] < mn) mn = m[i][j];
		}
		for (int j = 0; j < n; j++) {
			if (m[i][j] > mx) mx = m[i][j];
		}
		size = mx - mn + 1;
		int* v = new int[size]; //и создаем доп массив рэнжа от мин до макс количества подобных элементов
		for (int j = 0; j < size; j++) {
			v[j] = 0;
		}
		for (int j = 0; j < n; j++) {
			v[m[i][j]-mn]++; //заполняем количеством(считаем)
		}
		c = 0;
		for (int j = 0; j < size;) { //выводим элементы в основной массив(пересобираем его отсортированным)
			if (v[j] == 0) {
				j++;
				continue;
			}
			else {
				for (int l = 0; l < v[j]; l++) {
					m[i][c] = j+mn;
					c++;
				}
				j++;
			}
		}
	}
	
	return m;
}

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	string str;
	getline(in, str);
	n = stoi(str); //считываем размерность массива
	int** a; //объявляем массив
	a = input_m(n); //вводим
	a = sort_m(a, n); //сортируем
	print_m(a, n); //выводим
	return 0;
}

