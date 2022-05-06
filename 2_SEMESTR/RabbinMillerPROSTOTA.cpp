#include <iostream>
#include <time.h>
using namespace std;

unsigned powmod(unsigned base, unsigned exp, unsigned modulo)
{
	unsigned res = 1;

	while (exp != 0)
	{
		if ((exp & 1) != 0)
		{
			res = (1ll * res * base) % modulo;
		}

		base = (1ll * base * base) % modulo;
		exp >>= 1;
	}

	return res;
}

bool check(long int n, int k) {
	if (n == 2 || n == 3) return true;
	if (n < 2 || n % 2) return false;

	long int d = n - 1;
	int s = 0;
	while (d % 2 == 0) {
		d /= 2;
		s++;
	}
	for (int i = 0; i < k; i++) {
		srand(time(0));
		long int a = 2 + rand() % (n - 2);
		long int x = powmod(a, d, n);
		if (x == 1 || x == n - 1) continue;
		for (int r = 1; r < s; r++) {
			x = powmod(x, 2, n);
			if (x == 1) return false;
			if (x == n - 1) break;
		}
		if (x != n - 1) return false;
	}
	return true;
}

int main() {
	cout << check(7, 10);
	return 0;
}