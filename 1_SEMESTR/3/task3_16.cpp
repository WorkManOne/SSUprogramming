﻿#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus"); //Русская раскладка в консоли
	const int n = 4; //ввод n можно заменить на любое другое, но в задаче требуется таблица до 4
	for (int i = 1; i <= n; ++i) { //цикл для кол-ва ( до 4)
		for (int j = 1; j <= i; ++j) { //цикл для вывода через пробел в одну строку самого числа i
			cout << i << " ";
		}
		cout << "\n"; //перенос на след строку
		for (int j = 1; j <= i; ++j) { //цикл для вывода через пробел в одну строку числа i*2 как требуется по условию задачи
			cout << i*2 << " ";
		}
		cout << "\n"; //перенос на след строку
	}	
	return 0;
}