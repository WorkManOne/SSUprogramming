#include <iostream>
#include <set> //подключаем сет
using namespace std;

//10 15 141 111 9993 88 71 83 12 5
int main() {
	setlocale(LC_ALL, "rus");
	set<int>c; //set двузначных цифр
	set<int>tro; //set НЕдвузнычных цифр
	int x;
	for (int i = 0; i < 10; i++) {
		cin >> x; //вводим
		if ((x < 100) && (x > 9)) { //смотрим двузначное ли число
			c.insert(x % 10); //если двузначное, то записываем каждую цифру в сет
			c.insert(x / 10);
		}
		else { //иначе записываем цифры числа в сет НЕдвузнычных
			while (x > 0) {
				tro.insert(x % 10);
				x /= 10;
			}
		}
	}
	for (set<int>::iterator it = tro.begin(); it != tro.end(); it++) {
		c.erase(*it); //удаляем из сета двузначных цифр, те цифры которые есть и в НЕдвузнычных
	}

	for (set<int>::iterator it = c.begin(); it != c.end(); it++) {
		cout << *it << endl; //вывод
	}
	cout << endl;
	return 0;
}

