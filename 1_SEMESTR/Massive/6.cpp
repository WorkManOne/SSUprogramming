#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus"); //Русская раскладка в консоли
	int n, st, en, x, s = 0; //n диапазон (нач кон) х сумма
	cout << "Введите N start end x: ";
	cin >> n >> st >> en >> x;
	int *m = new int [n]; //дин. массив
	srand(time(0)); //обнуление рандома
	for (int i = 0; i < n; ++i) { 
		m[i] = rand() % (en - st + 1) + st;
		cout << m[i] << " "; //заполнение элементов массива и их вывод на экран
	}
	cout << endl; 
	for (int i = 0; i < n; ++i) {
		if ((m[i] % x == 0) && (m[i] != 0)) { //если делится на х то выводим порядковый номер в массиве
			cout << i << " ";
			s += 1; //и считаем что такое число есть
		}
	}
	if (s == 0) cout << "таких элементов нет"; //если нет дел на х то выводим...
	delete[] m;
	return 0;
}