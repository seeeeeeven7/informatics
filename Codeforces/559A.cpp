/*
	WA: 结果没有转整数
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
    double a1, a2, a3, a4, a5, a6;
    while (cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6) {
        double ans = (a3 / 2 + a5 / 2 + a4) * (a2 + a3) * 2;
        ans -= (a2 * a2 + a3 * a3 + a5 * a5 + a6 * a6) / 2;
        cout << (int)ans << endl;
    }
    return 0;
}