#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus"); //Поддержка русского языка в консольке вместо кракозябр
	int a, an, x, y;
	cout << "Ввод A X Y: ";
	cin >> a >> x >> y;
	if ((a >= 10) && (a <= 99) && (x >= 1) && (x <= 9) && (y >= 1) && (y <= 9)) { //Проверка на двузначность числа А и однозначность x y (считается ли 0 однозначным поскольку по условию "сумма цифра КРАТНА x или y", но на 0 делить нельзя)
		if (((a / 10 + a % 10) % x == 0) && (a / 10 < y)) { //Условие 1 задачи
			an = abs(a / 10 - 5) * 10 + abs(a % 10 - 5); //Формирование нового ЧИСЛА
		}
		else if (((a / 10 + a % 10) % x == 0) && (a / 10 > y)) { //Условие 2 задачи
			an = ((a / 10 + 5) % 10) * 10 + ((a % 10 + 5) % 10); //Формирование нового ЧИСЛА
		}
		else if (((a / 10 + a % 10) % x != 0) && (a / 10 < y)) { //Условие 3 задачи
			an = abs(a / 10 - 4) * 10 + abs(a % 10 - 4); //Формирование нового ЧИСЛА
		}
		else if (((a / 10 + a % 10) % x != 0) && (a / 10 > y)) { //Условие 4 задачи
			an = ((a / 10 + 4) % 10) * 10 + ((a % 10 + 4) % 10); //Формирование нового ЧИСЛА
		}
		else { //в остальных случаях...
			an = ((a / 10 + 2) % 10) * 10 + ((a % 10 + 2) % 10); //Формирование нового ЧИСЛА
		}
		cout << "Вывод: " << an; //готовое новое ЧИСЛО
	}
	else cout << "некорректный ввод"; //если число не двузначное или хотя бы 1 из 2-х чисел не однозначное
	return 0;
}