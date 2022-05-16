//
// Created by Khanh Nguyen Van on 10/17/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, used[100] = {0};
vector<string> v;
char a[10], c[10];

void print() {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < n; j++) cout << c[j];
        cout << v[i] << endl;
    }
}

void TryA(int i) {
    for (int j = '1'; j <= n + 48; j++) {
        a[i] = j;
        if (i == n - 1) {
            string s = "";
            for (int k = 0; k < n; k++)
                s += a[k];
            v.push_back(s);
        } else TryA(i + 1);
    }
}

void TryC(int i) {
    for (int j = 'A'; j < n + 65; j++) {
        if (used[j] == 0) {
            used[j] = 1;
            c[i] = j;
            if (i == n - 1) {
                print();
            } else TryC(i + 1);
            used[j] = 0;
        }
    }
}

int main() {
    scanf("%d", &n);
    TryA(0);
    TryC(0);
    return 0;
}