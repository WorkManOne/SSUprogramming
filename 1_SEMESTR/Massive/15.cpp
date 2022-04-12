#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus"); //Русская раскладка в консоли
	int n, st, en, mx = 0; //n диапазон(нач кон) макс
	cout << "Введите N start end: ";
	cin >> n >> st >> en;
	int *m = new int [n]; //дин. массив
	srand(time(0)); //обнуление рандоизатора
	for (int i = 0; i < n; ++i) {
		m[i] = rand() % (en - st + 1) + st;
		cout << m[i] << " "; //присваивание и вывод элементов
		if ((m[i] % 2 == 0) && (m[i] > mx)) mx = m[i]; //если четное и максимальное то макс = элементу 
	}
	cout << endl;
	for (int i = 0; i < n; ++i) {
		if (mx == m[i]) cout << i << " "; //проходим еще раз по массиву и выводим все порядковые номера максимальных четных
	}
	if (mx == 0) cout << "таких элементов нет"; //если четных не нашлось...
	delete[] m; //чистим память 
	return 0;
}