#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus"); //Русская раскладка в консоли
	int n,st,en; //n диапазон(нач кон) макс
	cout << "Введите N start end: ";
	cin >> n >> st >> en;
	int *m = new int [n]; //дин. массив
	srand(time(0)); //обнуление рандоизатора
	for (int i = 0; i < n; ++i) {
		m[i] = rand() % (en - st + 1) + st;
		cout << m[i] << " "; //присваивание и вывод элементов
	}
	cout << endl;
	if (n % 2 == 0) {
		swap(m[n / 2], m[n / 2 - 1]); //если количество элементов массива четное, то меняем два средних
	}
	else {
		swap(m[0], m[n / 2]); //иначе меняем первый и средний
	}
	cout << "DONE!" << endl; //ДОКЛАДЫВАЕМ О ГОТОВНОСТИ!
	for (int i = 0; i < n; ++i) cout << m[i] << " "; //выводим измененный массив
	delete [] m; //чистим память
	return 0;
}