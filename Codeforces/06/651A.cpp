/*
	һ��˼·Ӧ����dp
	ͨ����dp��ģ�⣬���Կ�����������ײ�ļ�������У����Ը���a1��a2�Ĳ��Ϊ0/3��1/2���֡� 
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
