#include <iostream>
using namespace std;

int main() {
	freopen("B1.in", "w", stdout);
	cout << 20 << endl;
	for (int t = 0; t < 20; t++) {
		int n = rand() % 50 + 1;
		int m = rand() % 50 + 1;
		int k = rand() % 10 * 100000000 + rand() % 10000 * 10000 + rand() % 10000;
		cout << n << ' ' << m << ' ' << k << endl;
		for (int i = 0; i < n; i++) cout << rand() % 10 * 100000000 + rand() % 10000 * 10000 + rand() % 10000 << ' '; cout << endl;
		for (int i = 0; i < m; i++) cout << rand() % 10 * 100000000 + rand() % 10000 * 10000 + rand() % 10000 << ' '; cout << endl;

	}
}