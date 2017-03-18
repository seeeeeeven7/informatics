/*
    AC
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

#define ios ios_base::sync_with_stdio(false)

string a, b;

string s_sort(string s) {
    //cout << s << endl;
    if (s.length() % 2 != 0) return s;
    string l = s_sort(s.substr(0, s.length() / 2));
    string r = s_sort(s.substr(s.length() / 2, s.length() / 2));
    if (l < r) return l + r;
    else return r + l;
}

int main() {
//    freopen("input.txt", "r", stdin);
    ios;
    while (cin >> a >> b) {
        a = s_sort(a);
        b = s_sort(b);
        if (a == b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}