//
// Created by Khanh Nguyen Van on 10/16/2021.
//

/*
Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một. Hãy sắp xếp dãy theo thứ tự giảm dần, sau đó liệt kê tất cả các dãy con của A[] có tổng các phần tử là số nguyên tố.

Input

Dòng đầu ghi số bộ test, mỗi test có 2 dòng:

Dòng đầu ghi số N (2 < N <15)
Dòng thứ 2 ghi N số của dãy A[], các số đều nguyên dương, nhỏ hơn 100 và khác nhau từng đôi một.
Output

Với mỗi test, liệt kê tất cả các dãy con có tổng các phần tử là số nguyên tố theo, mỗi dãy con trên một dòng. 

Ví dụ

Input

1

4

3 2 5 4

Output

2

3

3 2

4 3

5

5 2

5 4 2
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[20];
vector<int> v;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void print() {
    if (v.size()) {
        for (int i: v) printf("%d ", i);
        printf("\n");
    }
}

void Try(int i, int s) {
    if (i == -1) {
        if (isPrime(s)) print();
        return;
    }
    Try(i - 1, s);
    v.push_back(a[i]);
    Try(i - 1, s + a[i]);
    v.pop_back();
}

void solve() {
    sort(a, a + n);
    Try(n - 1, 0);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        input();
        solve();
    }
    return 0;
}
