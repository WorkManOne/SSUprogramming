#include <iostream>
#include <string>
#include <fstream>
using namespace std;




int main() {
	setlocale(LC_ALL, "rus");
	ifstream in ("show.txt"); //объявляем вводный поток из файла
	ofstream out; //объявляем выводной поток в файл
	out.open("show_filtered.txt"); //вывод в этот файл
	string str;
	while (in) {
		getline(in, str); //вводим из файла строку
		if ((str[21] == '1') && (str[22] == '8')) { //проверяем время конца, если 18 часов то минут не должно быть 00 (с 18:01)
			if ((str[24] != '0') || (str[25] != '0')) out << str << endl; //выводим в файл
		}
		if ((str[21] == '1') && (str[22] == '9')) { //проверяем время конца
			out << str << endl; //выводим в файл
		}
		if ((str[21] == '2') && (str[22] == '0')) { //проверяем время конца
			out << str << endl; //выводим в файл
		}
		if ((str[21] == '2') && (str[22] == '1')) {
			if ((str[24] == '0') && (str[25] == '0')) out << str << endl; //проверяем время конца, если 21 час то минут должно быть 00 (до 21:00) //выводим в файл
		} 
	}
	out.close(); //закрываем файл
	in.close(); //закрываем файл
	return 0;
}