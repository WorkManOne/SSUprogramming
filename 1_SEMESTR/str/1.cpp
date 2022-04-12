#include <iostream>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	string sogl = "bcdfghjklmnprstvwxzBCDFGHJKLMNPRSTVWXZ"; //строка согласных
	string s;
	getline(cin, s); //ввод строки
	for (int i = 0; i < s.length(); ++i) { //до длины строки 
		for (int j = 0; j < sogl.length(); ++j) {
			if (s[i] == sogl[j]) { //проверяем согласность
				s.insert(i+1, "!"); //если согласная вставляем ! и перестаем проверять
				break;
			}
		}
	}
	cout << s; //выводим строку
	return 0;
}