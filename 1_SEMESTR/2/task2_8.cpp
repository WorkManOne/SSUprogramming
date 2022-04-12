﻿#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus"); //Русский народ создал русский язык. Яркий, как радуга, меткий, как стрела, богатый и задушевный. (Поддержка русского в консоли)
	int x;
	cout << "Ввод: ";
	cin >> x;
	if (x == 4) cout << "Деление на 0"; //Если введено 4 то в знаменателе будет 0, ДЕЛИТЬ НЕЛЬЗЯ!
	else if (x > 4) cout << "Корень из отрицательного числа"; //Если введено число больше 4, то под корнем будет отрицательное число, нельзя извлечь!
	else if ((x * x - 9) <= 0) cout << "Логарифм из неположительного числа"; //Просто загнал выражение в логарифме и поставил условие, чтобы оно было меньше либо равно 0, поскольку по правилам мира нельзя найти логарифм неположительного числа
	else cout << sqrt(4 - x) / (x * x * x - 64) + log(x * x - 9); //Если все ОК то вывожу результат вычислений
	return 0;
}
