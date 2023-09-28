/*
	即尽量少的组成最长上升子序列，这个数量和重复次数最多的数的重复次数是一致的。 
	AC
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int abs(int x) { if (x < 0) return -x; else return x; }

#define ios ios_base::sync_with_stdio(false)

int main() {	
//    freopen("input.txt", "r", stdin);
    ios;
    int n, a[1000];
    while (cin >> n) {
    	for (int i = 0; i < n; i++) cin >> a[i];
    	sort(a, a + n);
    	int s = 0, t = 1; 
    	for (int i = 1; i < n; i++) {
    		if (a[i] == a[i - 1]) {
    			t ++;
    		}
    		else {
    			s = max(s, t);
    			t = 1;
    		}
    	}
    	cout << n - max(s, t) << endl;
	}
    return 0;
}
