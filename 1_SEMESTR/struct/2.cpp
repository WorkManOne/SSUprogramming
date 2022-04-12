#include <iostream>
using namespace std;

struct dot { //структура точки
	double x, y;
};

dot* indot(int n) {	//ввод множества точек
	dot* toc = new dot[n];
	for (int i = 0; i < n; ++i) {
		cout << "Введите x y : ";
		cin >> toc[i].x >> toc[i].y;
	}
	return toc;
}

int main() {
	setlocale(LC_ALL, "rus");
	cout << "Введите вершины прямоугольника xmin ymin xmax ymax: ";
	double xmn, ymn, xmx, ymx;
	cin >> xmn >> ymn >> xmx >> ymx; //ввводим вершины прямоугольника
	cout << "Введите количество точек: ";
	int n;
	cin >> n; //ввводим количество точек
	dot *ded = indot(n); //создаем множество точек и вводим его
	//для каждой точки проверяем если ее координаты лежат в пределах x и y, то выводим ее
	for (int i = 0; i < n; ++i)	if ((ded[i].x >= xmn) && (ded[i].x <= xmx) && (ded[i].y >= ymn) && (ded[i].y <= ymx)) cout << ded[i].x << " " << ded[i].y << endl;
	return 0;
}
////Введите вершины прямоугольника xmin ymin xmax ymax: 2.02 1 12.5 5.2
//Введите количество точек : 10
//Введите x y : 0 0
//Введите x y : 130 120
//Введите x y : 5 8
//Введите x y : 6.2 9.1
//Введите x y : 12 14
//Введите x y : 2.02 2
//Введите x y : 2.02 5.2
//Введите x y : 2.02 5.3
//Введите x y : 12.6 5.3
//Введите x y : 12.6 5.1