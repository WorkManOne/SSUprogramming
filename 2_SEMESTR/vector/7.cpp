#include <iostream>
#include <math.h>
#include <algorithm>
#include <deque> //подключение библиотеки дека
using namespace std;

int r;
bool kr(int x) {
	return x % r == 0;
}


bool ch(int x) { //функция четности
	return (x % 2 == 0);
}
//ПРОВЕРКА: 1 2 3 9 21 42 13 21 1 10
int main() {
	setlocale(LC_ALL, "rus");
	deque<int> v; //объявление вектора
	int n = 5; // размер контейнера/2
	int x, y; //вспомогателльная для пушбэка/пушфронта	
	cout << "Введите число(а): ";
	for (int i = 0; i < n; i++) {
		cin >> x; //вводим число в переменную
		cin >> y; //вводим число в переменную
		v.push_back(x); //записываем значение переменной в вектор с конца
		v.push_front(y); //записываем значение переменной в вектор с начала
	}

	deque<int>::iterator it = remove_if(v.begin(), v.end(), ch); //проходим по вектору, перемещаем четные в конец старого вектора
	v.erase(it, v.end()); //удаляем элементы за пределом нового вектора
	cout << "Удалены четные: ";
	for (deque<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " "; //выводим все элементы вектора
	}
	cout << endl;
	int mx = *max_element(v.begin(), v.end());
	int mn = *min_element(v.begin(), v.end());
	cout << "Заменены максимальные на минимальный: ";
	replace(v.begin(), v.end(), mx, mn);
	for (deque<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " "; //выводим все элементы вектора
	}
	cout << endl;
	cout << "Введите число x: ";
	cin >> r;
	cout << "Кратных " << r << ": " << count_if(v.begin(),v.end(),kr);
	return 0;
}

