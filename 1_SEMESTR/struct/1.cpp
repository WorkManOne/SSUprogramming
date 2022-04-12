﻿#include <iostream>
#include <string>
using namespace std;

/*В поезде едут 3 юзера и 3 программиста.
У юзеров 3 билета, у программистов 1. Заходит контроллер.
Юзеры показывают билеты, программисты прячутся в туалет. Контроллер стучится в туалет, оттуда высовывается рука с билетом. Программисты едут дальше.
На обратном пути. У юзеров 1 билет, у программистов ни одного. Заходит контроллер.
Юзеры прячутся в туалет. Один из программистов стучит, из туалета высовывается рука с билетом. Программисты забирают билет и прячутся в соседний туалет. Юзеров ссаживают с поезда.
Вывод — не всякий алгоритм, доступный программисту, доступен юзеру.*/

struct train { //структура
	int n; //номер поезда
	int sh; //время отправления (часы)
	int sm; //время отправления (минуты)
	int th; //время в пути (час)
	int tm; //время в пути (минуты)
};

train str_train(string str) { //функция перевода строки в формат структуры
	train po;
	//numb
	int k = 0;
	int sh = 0, sm = 0, tm = 0;
	while (str[k] != ' ') { //номер поезда - любое число
		++k;
	}
	string str1 = str.substr(0, k);
	int str1int = stoi(str1);
	po.n = str1int;
	if (po.n == -1) cout << "Неккоректный ввод" << endl; //если номер поезда -1 значит неправильный формат ввода
	//sh
	str1 = str.substr(2 + k - 1, 2);
	str1int = stoi(str1);
	if (str1int > 23) { //время отправления не должно быть больше 23:59, дальше идет 00:00
		sh = 1;
		cout << "Неправильный час отправления" << endl;
	}
	po.sh = str1int;
	//sm
	str1 = str.substr(5 + k - 1, 2);
	str1int = stoi(str1);
	if (str1int > 59) { //время отправления не должно быть больше 23:59, дальше идет 00:00
		sm = 1;
		cout << "Неправильная минута отправления" << endl;
	}
	po.sm = str1int;
	//th
	int i = 8 + k - 1;
	int c = 0;
	while (str[i] != ':') {
		c++;
		i++;
	}
	str1 = str.substr(8 + k - 1, c); //время в пути может быть любое, кроме минут!
	str1int = stoi(str1);
	po.th = str1int;
	//tm
	str1 = str.substr(11 + k - 3 + c, 2);
	str1int = stoi(str1);
	if (str1int > 59) { //минуты в пути не должны превышать 59!, после 59 идет 0
		tm = 1;
		cout << "Неправильная минута времени в пути" << endl;
	}
	po.tm = str1int;
	if ((tm == 1) || (sh == 1) || (sm == 1)) { //если происходит суета в инфе о поезде, то номеру поезда выдается идентификатор ошибки
		po.sh = 0;
		po.sm = 0;
		po.th = 0;
		po.tm = 0;
		po.n = -1;
	}
	return po;
}

train correct(string str) { //проверка строки с инфой о поезде
	int k = 0;
	int f = 0; //флаг что все ок
	while (str[k] != ' ') { //любой номер поезда
		++k;
	}
	int c = 0;
	int i = k + 1;
	while (str[i] != ' ') { // определитель корректности длины времени отправления
		++i;
		++c;
	}
	if (str.substr(2 + k - 1, c).length() != 5) f = 1; //время отправления должно содержать 5 символов (00:00) 12414 233:59 23:00
	if (str.substr(8 + k - 1, 5).length() < 5) f = 1; //время в пути должно содержать от 5 символов (10000:00)
	if ((str.length() - str.rfind(":") - 1 )!= 2) f = 1; //время в пути (минуты) должно содержать 2 знака
	if (f == 0) return str_train(str); //если все ок возвращаем перевод из строки в формат структуры
	else return str_train("-1 00:00 00:00"); //если плохо, то возвращаем перевод из строки в формат структуры, 
	//но придаем номеру поезда отрицательное число(идентификатор ошибки)
}
void print(train po) {
	cout << po.n << " " << po.sh << " " << po.sm << " " << po.th << " " << po.tm << endl;
}
void endtime(train po) { //функция вывод времени прибытия
	if (po.n != -1) { //работает только если ввод корректен и время не нарушено(идентификатор номера поезда != -1)
		if (po.sm + po.tm < 60) { //если сумма минут отправления < 60 то суммируем часы и минуты
			if (((po.sh + po.th) % 24) < 10) cout << "0"; //не забываем выдавать правильный формат и добавлять нули если число однозначное
			cout << (po.sh + po.th) % 24 << ":";
			if (((po.sm + po.tm) % 60) < 10) cout << "0";
			cout << (po.sm + po.tm) % 60 << endl;
		}
		else { //если сумма минут отправления >= 60 то суммируем часы прибавляем еще час потому что сумма минут дает час с лишним
			if ((((po.sh + po.th) % 24 + 1) % 24) < 10) cout << "0"; //не забываем выдавать правильный формат и добавлять нули если число однозначное
			cout << ((po.sh + po.th) % 24 + 1) % 24 << ":";
			if (((po.sm + po.tm) % 60) < 10) cout << "0";
			cout << (po.sm + po.tm) % 60 << endl;
		}
	}
}
int main() {
	setlocale(LC_ALL, "rus");
	int n; //количество поездов
	string stroke; //строка которая преобразуем в инфу о поезде
	cin >> n;
	cin.get(); //перенос на след строку
	train* trains = new train[n]; //массив поездов размера n
	for (int i = 0; i < n; ++i) {
		getline(cin, stroke); //вводим строку и записывем ее в массив инфы о поездах
		trains[i] = correct(stroke);
		endtime(trains[i]); //сразу считаем время прибытия
	}
	return 0;
}