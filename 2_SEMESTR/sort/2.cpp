#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct people {
	string name;
	string work;
	int d, m, y;
	int worky;
	int paym;
};

people people_in(string sub) {
	sub += " ";
	people man;
	string s;
	int cspace = 0;
	for (int i = 0; i < sub.length(); i++) {
		if (sub[i] != ' ') {
			s += sub[i];
		}
		if (sub[i] == ' ') {
			switch (cspace) {
			case 0:
				man.name = s;
				break;
			case 1:
				man.work = s;
				break;
			case 2:
				man.d = stoi(s);
				break;
			case 3:
				man.m = stoi(s);
				break;
			case 4:
				man.y = stoi(s);
				break;
			case 5:
				man.worky = stoi(s);
				break;
			case 6:
				man.paym = stoi(s);
				break;
			}
			cspace += 1;
			s = "";
		}
	}
	return man;
}

void print_people(people man) {
	cout << man.name << " " << man.work << " " << man.d << " " << man.m << " " << man.y << " " << man.worky << " " << man.paym << endl;
}

vector<people> shsort(vector <people> man) {
	int n = man.size();
	int k = 0;
	while (pow(3, k + 1) <= n) {
		k++;
	}
	int d = pow(3, k) - 1;
	int j;
	while (d > 1) {
		for (int i = 0; i < n - d; i++) {
			j = i;
			while ((j >= 0) && (man[j].paym > man[j + d].paym)) {
				swap(man[j], man[j + d]);
				j = j - 1;
			}
		}
		k--;
		d = pow(3, k) - 1;
	}
	d = 1;
	for (int i = 0; i < n - d; i++) {
		int j = i;
		while ((j >= 0) && (man[j].paym > man[j + d].paym))	{
			swap(man[j], man[j + d]);
			j--;
		}
	}
	return man;
}

int main() {
	setlocale(LC_ALL, "rus");
	ifstream in("data2.txt"); //вводим файл
	ofstream out("datout.txt");
	string str;
	vector<people>p;
	while (in.peek() != EOF) {
		getline(in, str);
		p.push_back(people_in(str));
	}
	p = shsort(p);
	for (vector<people>::iterator it = p.begin(); it != p.end(); it++) {
		print_people(*it);
	}
	return 0;
}

