#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

ifstream in("datac.txt"); //вводим файл
ofstream out("datout.txt");

void print_m(int** m, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			out << m[i][j] << " ";
		}
		out << endl;
	}
}

int** input_m(int n) {
	string str;
	string line;
	string s;
	int j = 0;
	int** m;
	m = new int* [n];
	for (int i = 0; i < n; i++) m[i] = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			in >> m[i][j];
		}
	}
	return m;
}

int* sort_m(int* m, int l, int r, int md) {
	if ((l >= r) || (md < l) || (md > r)) return m;
	if ((sizeof(m) == 2) && (m[0] > m[1])) {
		swap(m[0], m[1]);
		return m;
	}
	int* mbuf = new int[r - l + 1];
	int i = l;
	int j = md + 1;
	int c = 0;
	while (r - l + 1 != c) {
		if (i > md) {
			for (int k = j; k <= r; k++) {
				mbuf[c] = m[k];
				c++;
			}
		}
		else if (j > r) {
			for (int k = i; k <= md; k++) {
				mbuf[c] = m[k];
				c++;
			}
		}
		else if (m[i] > m[j]) {
			mbuf[c] = m[j];
			c++;
			j++;
		}
		else {
			mbuf[c] = m[i];
			c++;
			i++;
		}
	}
	for (int k = l; k < l + sizeof(mbuf); k++) {
		m[k] = mbuf[k - l];
	}
	for (int i = 0; i<r+1; i++) {
		cout << m[i] << " ";
	}
	cout << endl;
	return m;
}

int* sort_mmerge(int* m, int l, int r) {
	if (l >= r) {
		return m;
	}
	int md = (l + r) / 2;
	sort_mmerge(m, l, md);
	sort_mmerge(m, md + 1, r);
	sort_m(m, l, r, md);
	return m;
}

int** sort_mm(int** m, int n) {
	for (int i = 0; i < n; i++) {
		m[i] = sort_mmerge(m[i], 0, n - 1);
	}
	return m;
}

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	string str;
	getline(in, str);
	n = stoi(str);
	int** a;
	a = input_m(n);
	a = sort_mm(a, n);
	print_m(a, n);
	return 0;
}

