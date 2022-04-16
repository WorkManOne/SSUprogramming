#include <iostream>
#include <math.h>
#include <vector> //подключение библиотеки списка
#include <list>
#include <algorithm>
using namespace std;
int q, e;
int x;

bool kr(int f) { //функция кратности числу
	return (f%x==0);
}

bool mej(int f) { //функция принадлежности интервалу
	return ((f >= q) && (f<=e));
}

int main() {
	setlocale(LC_ALL, "rus");
	list<int>a;
	list<int>b;
	int n = 10;
	int r; //вспомогательная ввода пушбэком
	int y;
	cout << "Введите элементы первой последовательности: ";
	for (int i = 0; i < n; i++) {
		cin >> r;
		a.push_back(r);
	}
	cout << endl;
	cout << "Введите элементы второй последовательности: ";
	for (int i = 0; i < n; i++) {
		cin >> r;
		b.push_back(r);
	}
	cout << endl;
	cout << "Действия с 1 последовательностью" << endl << "Введите x: ";
	cin >> x;
	list<int>::iterator it = remove_if(a.begin(), a.end(), kr); //удаляем элементы кратные x
	a.erase(it, a.end()); //окончательно удаляем
	cout << "Удалены кратные x: ";
	for (list<int>::iterator it = a.begin(); it != a.end(); it++) {
		cout << *it << " "; //выводим список
	}
	cout << endl;
	cout << "Действия с 2 последовательностью" << endl << "Введите интервал a b: ";
	cin >> q >> e; //вводим интервал
	cout << "Введите y: ";
	cin >> y; //вводим число на которое будем заменять
	replace_if(b.begin(), b.end(), mej, y); //заменяем
	cout << "Заменены 'y' входящие в интервал a b: ";
	for (list<int>::iterator it = b.begin(); it != b.end(); it++) {
		cout << *it << " "; //выводим список
	}
	cout << endl;
	a.sort(); //сортируем
	b.sort(); //сортируем
	a.merge(b); //переводим в один контейнер 
	cout << "Переведены в один контейнер: ";
	for (list<int>::iterator it = a.begin(); it != a.end(); it++) { //выводим контейнер с двумя списками
		cout << *it << " ";
	}
	return 0;
}

