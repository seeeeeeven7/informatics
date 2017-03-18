/*
	一种思路应该是dp
	通过对dp的模拟，可以看出来，在最底层的几种情况中，可以根据a1和a2的差分为0/3和1/2两种。 
	1 WA: a1 = 1, a2 = 1
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
    int a1, a2;
	while (cin >> a1 >> a2) {
		cout << max(a1 + a2 - 2 - (abs(a1 - a2) % 3 == 0), 0) << endl;
	}
    return 0;
}
