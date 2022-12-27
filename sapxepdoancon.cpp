//
// Created by Nguyen Van Khanh on 10/31/2021.
//

/*
Cho dãy số nguyên A có N phần tử. Hãy đếm số lượng chỉ số M < N thỏa mãn: nếu sắp xếp đoạn con (A1,…,AM) và (AM+1, …, AN) theo thứ tự tăng dần thì ta được dãy số A tăng dần.

Input

Dòng đầu ghi số bộ test T

Mỗi bộ test gồm 2 dòng:

Dòng đầu ghi số N (2 ≤ N ≤ 105)
Dòng thứ hai: ghi N số của dãy A (|Ai| ≤ 109).
Output

Với mỗi bộ test:

Dòng đầu ghi ra số K là số lượng chỉ số M tìm được
Dòng thứ 2 ghi ra K giá trị chỉ số thỏa mãn theo thứ tự tăng dần. Nếu K = 0 thì dòng này bỏ trống.
Ví dụ

Input

2

2

2 1

5

2 1 3 5 4

0

Output

2

2 3
*/


#include <bits/stdc++.h>

using namespace std;

int n, a[100005];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
}

void solve() {
    int minVal[n + 1], maxVal[n + 1];
    int pre = INT_MIN;
    for (int i = 1; i <= n; i++) {
        if (a[i] > pre) {
            maxVal[i] = a[i];
            pre = a[i];
        } else maxVal[i] = pre;
    }
    pre = INT_MAX;
    for (int i = n; i >= 0; i--) {
        if (a[i] < pre) {
            minVal[i] = a[i];
            pre = a[i];
        } else minVal[i] = pre;
    }
    int cnt = 0;
    queue<int> q;
    for (int i = 1; i < n; i++)
        if (maxVal[i] <= minVal[i + 1]) {
            cnt++;
            q.push(i);
        }
    if (cnt == 0) printf("%d", cnt);
    else {
        printf("%d\n", cnt);
        while (!q.empty()) {
            printf("%d ", q.front());
            q.pop();
        }
    }
    printf("\n");
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
