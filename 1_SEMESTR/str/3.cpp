#include <iostream>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int f, r = 0;
	int l = 0;
	string rus = "ABCEHKMOPTXYacekmopuxy"; //строка околорусских букв
	string sep = " .,!?:-"; //строка знаков препинания
	string s;
	getline(cin, s); //ввод строки
	for (int i = 0; i < s.length(); ++i) {
		f = 0;
		for (int j = 0; j < sep.length(); ++j) {
			if (s[i] == sep[j]) { //если знак препинания ставим флаг
				f = 1;
				break;
			}
		}
		for (int j = 0; j < rus.length(); ++j) {
			if (s[i] == rus[j]) { //на протяжении всего слова считаем русские буквы, если буква русская то ++ счетчик русских букв
				r++;
				break;
			}
		}
		if (f == 1) { //если слово закончилось проверяем на русскость
			if ((l == r) && (l!=0)) cout << s.substr(i-l, l) << " "; //если все слово русское(длина слова = длине русских букв), все ок!
			r = 0;
			l = 0;
		}
		else {
			l++;	
		}
	}
	return 0;
}