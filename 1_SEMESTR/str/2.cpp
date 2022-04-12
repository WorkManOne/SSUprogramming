#include <iostream>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int f, mst = 0; //флаг и старт макс слова
	int l = 0;
	int m = 0;
	string sep = " .,!?:-"; //строка со знаками перпинания
	string s;
	getline(cin, s); //ввод строки
	for (int i = 0; i < s.length(); ++i) { //проверяем все предложение
		f = 0; //флаг
		for (int j = 0; j < sep.length(); ++j) { 
			if (s[i] == sep[j]) { //если знак препинания, то поднимаем флаг
				f = 1;
				break;
			}
		}
		if (f == 1) { //если встретили сепаратор
			if (l > m) {  // проверяем длину слова
				m = l; //если макс то запоминаем длину и старт слова
				mst = i - m;
			}
			l = 0; //обнуляем длину и считаем по новой

		}
		else l++;
	}
	cout << s.substr(mst,m); //выводим самое длинное слово
	return 0;
}