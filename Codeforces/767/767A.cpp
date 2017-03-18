#include <vector>
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1, 0);
	for (int i = 0, l = n; i < n; i++) {
		int j;
		cin >> j;
		a[j] = 1;
		int first = true;
		while (a[l]) {
			if (!first) cout << ' ';
			else first = false;
			cout << l--;
		}
		cout << endl;
	}
	return 0;
}
