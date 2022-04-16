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

people people_in(string sub){
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

vector<people> fsort(vector <people> man, int l, int r) {
	int i = l;
	int j = r;
	int mid = man[(r + l) / 2].paym;
	while (i <= j) {
		while (man[i].paym < mid) {
			i++;
		}
		while (man[j].paym > mid) {
			j--;
		}
		if (i <= j) {
			swap(man[i], man[j]);
			i++;
			j--;
		}
	}
	if (j - l > 1) man = fsort(man,l, j);
	if (r - i > 1) man = fsort(man,i, r);
	return man;
}

int main() {
	setlocale(LC_ALL, "rus");
	ifstream in("data2.txt"); //вводим файл
	ofstream out("datout.txt");
	string str;
	vector<people>p;
	int c = -1;
	while (in.peek() != EOF) {
		c++;
		getline(in, str);
		p.push_back(people_in(str));
	}
	p=fsort(p, 0, c);
	for (vector<people>::iterator it = p.begin(); it != p.end(); it++) {
		print_people(*it);
	}
	return 0;
}

