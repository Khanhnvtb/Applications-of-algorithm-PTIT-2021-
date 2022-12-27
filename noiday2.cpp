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

//Bộ test bài này bị sai

#include <bits/stdc++.h>

using namespace std;

long long res, m = 1e9 + 7;

int n;

struct data {
    long long natural, remainder;

    bool operator()(data x, data y) {
        if (x.natural > y.natural) return true;
        if (x.natural == y.natural && x.remainder > y.remainder) return true;
        return false;
    }
};

priority_queue<data, vector<data>, data> q;

void input() {
    scanf("%d", &n);
    long long x;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);
        data tmp;
        tmp.natural = x / m;
        tmp.remainder = x % m;
        q.push(tmp);
    }
}

void solve() {
    res = 0;
    while (q.size() > 1) {
        data x = q.top();
        q.pop();
        data y = q.top();
        q.pop();
        data z;
        z.natural = x.natural + y.natural + (x.remainder + y.remainder) / m;
        z.remainder = (x.remainder + y.remainder) % m;
        q.push(z);
        res = (res + z.remainder) % m;
    }
    printf("%lld", res);
}

int main() {
    input();
    solve();
    return 0;
}
