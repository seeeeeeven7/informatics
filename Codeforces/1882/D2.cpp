#include <iostream>
using namespace std;

void dfs(vector<int> &a, vector<vector<int>> &e, vector<int> &f, vector<int> &ans, vector<int> &size, int fa, int edge) {
	if (size[edge] == 0) {
		int i = f[edge];
		
		for (int j : e[i]) if (f[j] != fa) {
			
		}
	}
}

int main() {
	int tasks; cin >> tasks;
	while (tasks --) {
		int n; cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) cin >> a[i];
		vector<vector<int>> e(n + 1);
		vector<int> f;
		for (int i = 0; i < n - 1; i++) {
			int p, q; cin >> p >> q;
			e[p].push_back(i * 2); f.push_back(q);
			e[q].push_back(i * 2 + 1); f.push_back(p);
		}
		vector<int> ans(f.size()), size(f.size(), 0);
		for (int j : e[0]) dfs(a, e, f, ans, size, 0, j);
		for (int i = 0; i < n; i++) cout << ans[i] << ' '; cout << endl;
	}
}
			