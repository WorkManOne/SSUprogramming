#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <string>
using namespace std;



int main() {
	setlocale(LC_ALL, "rus");
	ifstream in("data.txt"); //вводим файл
	string str;
	multiset<string>cha; //мультисет 
	getline(in, str);
	cout << "Считано: " << str;
	string s;
	int d = 0; //чисельная длина
	int l = 0; //длина
	int c = -1; //проверка числа на "первость"
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ') {
			if (isdigit(str[i])) d++;
			l++;
			s = s + str[i];
		}
		else {
			if ((d == l) && (c==-1)) {
				c = stoi(s);
			}
			else {
				cha.insert(s);
			}
			l = 0;
			d = 0;
			s = "";
		}
	}
	cout << endl << endl << "Слово встречается " << c << " раз " << endl;
	for (multiset<string>::iterator it = cha.begin(); it != cha.end(); it++) {
		if (c == cha.count(*it)) cout << *it <<endl;
	}
	cout << endl;
	return 0;
}

