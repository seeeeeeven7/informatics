#include <iostream>
#include <vector>
using namespace std;

long long ans1, ans2 = -1;
void update(long long i, long long j) {
	if (j < ans2 || ans2 == -1) {
		ans1 = i;
		ans2 = j;
	}
}

int main() {
	long long ts, tf, t;
	cin >> ts >> tf >> t;
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	long long l = ts;
	for (int j = 0; j < n; j++) {
		if (a[j] > l) {
			if (tf - l >= t) update(l, 0); 
			l = a[j] + t;
		}
		else { // a[j] <= l 
			if (tf - l >= t) update(a[j] - 1, l - a[j] + 1);
			l = l + t;
		}
		//cout << j << ' ' << l << endl; 
	}
	if (tf - l >= t) update(l, 0);
	//if (tf - ans1 < t) ans1 = -1;
	cout << ans1 << endl;
}
