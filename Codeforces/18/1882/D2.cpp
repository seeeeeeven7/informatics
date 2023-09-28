#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> &a, vector<vector<int>> &e, vector<int> &f, vector<long long> &ans, vector<long long> &size, int fa, int edge) {
	if (size[edge] == 0) {
		int i = f[edge];
		size[edge] = 1;
		ans[edge] = 0;
		for (int j : e[i]) if (f[j] != fa) {
			dfs(a, e, f, ans, size, i, j);
			size[edge] += size[j];
			ans[edge] += (size[j] * (a[i] ^ a[f[j]])) + ans[j];
		}
	}
}

int main() {
//	freopen("D.in", "r", stdin);
	int tasks; cin >> tasks;
	while (tasks --) {
		int n; cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) cin >> a[i];
		vector<vector<int>> e(n + 1);
		vector<int> f;
		for (int i = 1; i <= n; i++) {
			f.push_back(i); e[0].push_back(f.size() - 1);
		}
		for (int i = 1; i < n; i++) {
			int p, q; cin >> p >> q;
			f.push_back(q); e[p].push_back(f.size() - 1);
			f.push_back(p); e[q].push_back(f.size() - 1);
		}
		vector<long long> ans(f.size()), size(f.size(), 0);
		for (int j : e[0]) dfs(a, e, f, ans, size, 0, j);
		for (int i = 0; i < n; i++) cout << ans[i] << ' '; cout << endl;
	}
}
			