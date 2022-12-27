//
// Created by Nguyen Van Khanh on 10/23/2021.
//

/*
Cho N sợi dây với độ dài khác nhau được lưu trong mảng A[]. Nhiệm vụ của bạn là nối N sợi dây thành một sợi sao cho tổng chi phí nối dây là nhỏ nhất. Biết chi phí nối sợi dây thứ i và sợi dây thứ j là tổng độ dài hai sợi dây A[i] và A[j].

Input

Dòng đầu ghi số bộ test T (T<10). Mỗi bộ test gồm 2 dòng. Dòng đầu tiên là số nguyên N (N ≤ 2*106).

Dòng tiếp theo gồm N số nguyên dương c[i] ( 1 ≤ A[i] ≤ 109).

Output

In ra đáp án của bộ test trên từng dòng, theo modulo 109+7.

Ví dụ:

Input:

7

2 4 1 2 10 2 3

Output

59
*/

#include <bits/stdc++.h>

using namespace std;

long n, res, m = 1e9 + 7;
priority_queue<long, vector<long>, greater<long> > q;

void input() {
    scanf("%ld", &n);
    long x;
    for (long i = 0; i < n; i++) {
        scanf("%ld", &x);
        q.push(x);
    }
}

void solve() {
    res = 0;
    while (q.size() > 1) {
        long x = q.top();
        q.pop();
        long y = q.top();
        q.pop();
        long z = x + y;
        q.push(z % m);
        res = (res + z) % m;
    }
    printf("%ld", res);
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
