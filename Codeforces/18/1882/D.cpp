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
int s[maxn], size[maxn];
long long ans[maxn];

long long dfs(vector<vector<int>> &a, int fa, int i) {
	long long score = 0;
	size[i] = 1;
	for (int j : a[i]) if (j != fa) {
		score += dfs(a, i, j) + 1LL * size[j] * (s[i] ^ s[j]);
		size[i] += size[j];
	}	
	// cout << fa << ' ' << i << ' ' << score << ' ' << size[i] << endl;
	return score;
}

void dfs1(vector<vector<int>> &a, int fa, int i, long long score, int ss) {
	ans[i] = score;
	for (int j : a[i]) if (j != fa) {
		dfs1(a, i, j, score + 1LL * (size[i] - size[j] * 2 + ss) * (s[i] ^ s[j]), ss + size[i] - size[j]);
	}
}

int main() {
 	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("D1.in", "r", stdin);
	freopen("D.out", "w", stdout);
#endif
	int tasks; cin >> tasks;
	while (tasks --) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) cin >> s[i];
		vector<vector<int>> a(n + 1);
		for (int i = 1; i < n; i++) {
			int p, q; cin >> p >> q;
			a[p].push_back(q);
			a[q].push_back(p);
		}
		dfs1(a, 0, 1, dfs(a, 0, 1), 0);
		for (int i = 1; i <= n; i++) cout << ans[i] << ' '; 
		cout << endl;
	}
 	
	return 0;
}
