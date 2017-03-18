/*
	AC
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

#define ios ios_base::sync_with_stdio(false)

int main() {	
//    freopen("input.txt", "r", stdin);
    ios;
    long long n, m, a;
	while (cin >> n >> m >> a) {
		cout << ((n + a - 1) / a) * ((m + a - 1) / a) << endl;
	}
    return 0;
}
