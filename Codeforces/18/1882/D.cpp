#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <set>
#include <queue>
using namespace std;

/* Code starts here */

const int maxn = 200000 + 10;
int a[maxn], b[3 * maxn], c[3 * maxn];
int top = 0;
int s[maxn];
long long f[3 * maxn], g[3 * maxn];

void dfs(int p, int e) {
	if (g[e] == -1LL) {
//		cout << p << ' ' << e << endl;
		f[e] = 0LL; g[e] = 1LL;
		for (int j = a[b[e]]; j; j = c[j]) if (b[j] != p) {
			dfs(b[e], j);
			f[e] += 1LL * g[j] * (s[b[e]] ^ s[b[j]]) + f[j];
			g[e] += g[j];
		}	
//		cout << p << ' ' << e << ' ' << f[e] << ' ' << g[e] << endl;
	}
}

int main() {
	 	
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
//    freopen("D1.out", "w", stdout);
#endif
	int tasks; cin >> tasks;
	while (tasks --) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> s[i];
		for (int i = 0; i <= n; i++) a[i] = 0;
		top = 1;
		for (int i = 1; i <= n; i++) {
			b[top] = i; c[top] = a[0]; g[top] = -1; a[0] = top; top ++;
		}
		for (int i = 1; i < n; i++) {
			int p, q; cin >> p >> q;
			b[top] = q; c[top] = a[p]; g[top] = -1; a[p] = top; top ++;
			b[top] = p; c[top] = a[q]; g[top] = -1; a[q] = top; top ++;
		}
		for (int j = a[0]; j; j = c[j]) dfs(0, j);
		for (int i = 1; i <= n; i++) {
			if (i < n) cout << f[i] << ' ';
			else cout << f[i] << endl;
		}
	}
 	
	return 0;
}
