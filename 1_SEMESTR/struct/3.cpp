#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct drob{ //структура дроби
	int a, b;
};

drob indrob() {
	drob dr;
	cout << "Введите числитель и знаменатель (Z N): ";
	cin >> dr.a >> dr.b;
	while (dr.b == 0) {
		cout << "Значение знаменателя не должно быть нулевым!"<<endl;
		cout << "Введите числитель и знаменатель (Z N): ";
		cin >> dr.a >> dr.b;
	}
	return dr;
}

void print_st(drob dr) {
	cout << dr.a << "/" << dr.b<< endl;
}

void print_dt(drob dr) {
	cout << dr.a/(dr.b*1.0f) <<endl;
}

void print_rt(drob dr) {
	int c = 0;
	while (dr.a >= dr.b) {
		++c;
		dr.a -= dr.b;
	}
	if (dr.a == 0) cout << c <<endl;
	else cout << c << "+" << dr.a << "/" << dr.b <<endl;
}

drob drob_krat(drob dr1) { //функция сокращения
	drob fin; //дробь результата
	for (int i = 2; i <= min(dr1.b, dr1.a); ++i) { //перебираем все значения делителей от 2 до минимального числа из числителя и знаментеля
	//(нельзя делить на число больше чем меньшее, минимум который может получиться в числ или знам = 1)
		if ((dr1.b % i == 0) && (dr1.a % i == 0)) { //если и числ и знам делятся на делитель то сокращаем
			while ((dr1.b % i == 0) && (dr1.a % i == 0)) {
			dr1.b /= i;
			dr1.a /= i;
			}
		}
	}
	fin = dr1;
	return fin; //возвращаем результат
}

drob drob_mn(drob dr1, drob dr2) {
	drob fin; //дробь результата
	dr1 = drob_krat(dr1); //приводим обе дроби к красивому, сокращенному виду
	dr2 = drob_krat(dr2);
	fin.a = dr1.a * dr2.a; //умножаем первую дробь на вторую(числ)
	fin.b = dr1.b * dr2.b; //(знам)
	fin = drob_krat(fin); //сокращаем если есть что
	return fin; //возвращаем результат
}

drob drob_del(drob dr1, drob dr2) {
	drob fin; //дробь результата
	dr1 = drob_krat(dr1); //приводим обе дроби к красивому, сокращенному виду
	dr2 = drob_krat(dr2);
	fin.a = dr1.a * dr2.b; //умножаем дробь на перевернутую вторую(числ)
	fin.b = dr1.b * dr2.a; //(знам)
	fin = drob_krat(fin); //сокращаем если есть что
	return fin; //возвращаем результат
}

drob drob_plus(drob dr1, drob dr2) {
	drob fin; //дробь результата
	dr1 = drob_krat(dr1); //приводим обе дроби к красивому, сокращенному виду
	dr2 = drob_krat(dr2);
	fin.a = dr1.a*dr2.b + dr2.a*dr1.b; //домножаем дроби на знаменатели и складываем числители
	fin.b = dr1.b * dr2.b;
	fin = drob_krat(fin); //сокращаем если есть что
	return fin; //возвращаем результат
}

drob drob_minus(drob dr1, drob dr2) {
	drob fin; //дробь результата
	dr1 = drob_krat(dr1); //приводим обе дроби к красивому, сокращенному виду
	dr2 = drob_krat(dr2);
	fin.a = dr1.a * dr2.b - dr2.a * dr1.b; //домножаем дроби на знаменатели и вычитаем числители
	fin.b = dr1.b * dr2.b;
	fin = drob_krat(fin); //сокращаем если есть что
	return fin; //возвращаем результат
}

int main() {
	setlocale(LC_ALL, "rus");
	drob z = indrob(); //вводим дробь
	drob r = indrob(); //вводим дробь
	cout << "Вывод обычной дроби "; //далее понятно, что будем выводить и какие действия с дробями делать.
	print_st(z);
	cout << "Вывод десятичной дроби ";
	print_dt(z);
	cout << "Вывод правильной дроби ";
	print_rt(z);
	cout << "Сокращение ";
	print_st(drob_krat(z));
	cout << "Умножение ";
	print_st(drob_mn(z, r));
	cout << "Деление ";
	print_st(drob_del(z, r));
	cout << "Сложение ";
	print_st(drob_plus(z, r));
	cout << "Вычитание ";
	print_st(drob_minus(z, r));
	return 0;
}