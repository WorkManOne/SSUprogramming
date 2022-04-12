﻿#include <iostream>
using namespace std;

int pr(int n, int m) { //вводим в функцию количество звездочек и пробелов
	if (n > 0) { //до тех пор пока количество звездочек положит.
		for (int j = 0; j < m; ++j) cout << " "; //печатаем пробелы
		for (int j = 0; j < n; ++j) cout << "*"; //печатаем звездочки
		cout << endl; //новая строка
		return pr(n - 2, m + 1); //эта же функция но с одним дополнительным пробелом и -2 зведочками 
	}
}

int main() {
	setlocale(LC_ALL, "rus"); //русская консоль
	int n; //n
	cout << "Введите число n: ";
	cin >> n;
	int p = n - 1; //число пробелов отступа
	for (int i = 1; i <= n; ++i) { //количество блоков
		pr(2 * i +1, p); //функция с построеня блока начиная с нечетного кол-ва звезд
		--p; //каждый последующщий блок на 1 отступ ближе к левой части
	}
	return 0;
}