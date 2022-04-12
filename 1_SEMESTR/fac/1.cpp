#include <iostream>
using namespace std;

int fac(int m) {
	if ((m == 0) || (m == 1)) return 1; //если факториал 0 или 1 то возвращаем единицу
	else return m * fac(m - 1); //иначе возвращаем число умноженое на подфункцию факториала числа на 1 меньше
}

int fac2(int m) { //нерекурсивная функция
	int p = 1;
	for (int i = 1; i <= m; i++) p *= i; //постепенное умножение на послед. числа
	return p;
}

int main() {
	setlocale(LC_ALL, "rus"); //русская консоль
	int n; //n
	cout << "Введите число n: ";
	cin >> n;
	cout << fac(n) << endl;
	cout << fac2(n);
	return 0;
}