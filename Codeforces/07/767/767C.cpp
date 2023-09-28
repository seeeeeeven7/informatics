#include <iostream>
#include <vector>
using namespace std;

#define ios ios_base::sync_with_stdio(false)

class Edge {
public:
	int tar;
	Edge *next;
	Edge(int tar_, Edge *next_):tar(tar_), next(next_) {}
};

vector<Edge*> link;
vector<int> v;
vector<int> s;
int root; 

void count(int i) {
	s[i] = v[i];
	for (Edge *p = link[i]; p != NULL; p = p -> next) {
		count(p -> tar);
		s[i] += s[p -> tar];
	}
	//cout << i << ' ' << s[i] << endl;
}

vector<int> dfs(int i) {
	vector<int> ans;
	for (Edge *p = link[i]; p != NULL; p = p -> next) {
		vector<int> ca = dfs(p -> tar);
		if (ca.size() > 1) return ca;
		if (ca.size() > 0) {
			ans.push_back(ca[0]);
			if (s[i] == 2 * s[ca[0]] && i != root) {
				ans.push_back(i);
			}
		}
	}
	if (ans.size() == 0 && s[i] * 3 == s[root]) ans.push_back(i);
	//cout << i << ": " << ans.size() << ' ';
	//for (int j = 0; j < ans.size(); j++) cout << ans[j] << ' ';
	//cout << endl;
	return ans;
}

int main() {
	ios;
	 
	int n;
	while (cin >> n) {
		link = vector<Edge*>(n + 1, NULL);
		v = vector<int>(n + 1, 0);
		s = vector<int>(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			int j;
			cin >> j >> v[i];
			if (j == 0) root = i;
			link[j] = new Edge(i, link[j]);
		}
		count(root);
		vector<int> ans = dfs(root);
		if (ans.size() > 1) cout << ans[0] << ' ' << ans[1] << endl;
		else cout << -1 << endl;
	}
	return 0;	
}
