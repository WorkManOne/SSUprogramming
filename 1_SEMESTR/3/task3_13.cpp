#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus"); //Русская раскладка в консоли
	float a, b, h; //объявление a,b,h
	cout << "Ввод a b h: ";
	cin >> a >> b >> h; //ввод
	for (float i = a; i <= b; i += h) { //цикл с шагом и включая b
		if (abs(i - 2)< 0.0001 ) cout << i << " " << "Деление на ноль" << endl; //условие для деление на ноль...
		else if ((i * i - 1) <= 0) cout << i << " " << "Логарифм из неположительного числа" << endl; //условие для...
		else cout << i << " " << log(i * i - 1) / sqrt(i * i - 4 * i + 4) << endl; //если делить и вычислять логарифм можно, то решаем f!
	}
	return 0;
}