#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
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

vector<int> sort_m(vector<int> m) { //сортировка чет-нечет
	int n = m.size();
	for (int i = 0; i < n; i++) { //сортируем строку
		if (i % 2 == 0) { //если i четное то начиная со 2 элемента сравниваем "четные" элементы
			for (int j = 2; j < n; j += 2) {
				if (m[j - 1] > m[j]) swap(m[j - 1], m[j]); //меняем местами 
			}
		}
		else { //если i нечетное то начиная со 1 элемента сравниваем "нечетные" элементы
			for (int j = 1; j < n; j += 2) {
				if (m[j - 1] > m[j]) swap(m[j - 1], m[j]); //меняем местами 
			}
		}
	}
	return m;
}


int** sort_mm(int** m, int n) { //получаем двумерный массив
	vector<int>x; //доп вектор
	for (int k = 0; k < n-1; k++) {
		for (int i = 0; i < n; i++) if (i + k < n)	x.push_back(m[i][i + k]); //записываем параллельную главной и выше нее диагональ в вектор
		x = sort_m(x); //сортируем чет-нечет сортировкой вектор
		int r = 0;
		for (int i = 0; i < n; i++) { //возвращем отсортированные элементы обратно в диагональ массива
			if (i + k < n) 
				m[i][i + k] = x[r];
			r++;
		}
		x.clear(); //очищаем вектор, чтобы потом ввести новую диагональ
	}
	for (int k = 0; k < n - 1; k++) { //производим те же самые действия что и в первом for, только для "нижних" диагоналей 
		for (int i = 0; i < n; i++) if (i + k < n)	x.push_back(m[i+k][i]);
		x = sort_m(x);
		int r = 0;
		for (int i = 0; i < n; i++) {
			if (i + k < n)
				m[i+k][i] = x[r];
			r++;
		}
		x.clear();
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
	a = sort_mm(a, n); //сортируем
	print_m(a, n); //выводим
	return 0;
}

