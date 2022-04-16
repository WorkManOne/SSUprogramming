#include <iostream>
#include <math.h>
#include <vector> //подключение библиотеки вектора
#include <algorithm>
using namespace std;

bool nch(int x) {
	return x % 2 != 0;
}

int main() {
	setlocale(LC_ALL, "rus");
	vector<int> v; //объявление вектора
	int n = 10; //размер контейнера
	int x; //вспомогателльная для пушбэка
	cout << "Введите число(а): ";
	for (int i = 0; i < n; i++) {
		cin >> x; //вводим число в переменную
		v.push_back(x); //записываем значение переменной в вектор
	}
	replace_if(v.begin(), v.end(), nch, 0);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " "; //выводим все элементы вектора
	}
	return 0;
}
