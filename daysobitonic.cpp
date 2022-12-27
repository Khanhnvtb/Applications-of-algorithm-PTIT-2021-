//
// Created by Nguyen Van Khanh on 10/30/2021.
//

/*
Một dãy số được gọi là Bi-tonic nếu nó được chia thành hai dãy đầu tăng dần và dãy tiếp theo giảm dần. Nhiệm vụ của bạn là tìm tổng lớn nhất dãy con Bi-tonic của dãy số A[]. Ví dụ với dãy A[] = {1, 15, 51, 45, 33, 100, 12, 18, 9} ta có kết quả là 194 tương ứng với dãy Bi-tonic {1, 15, 51, 100, 18, 9}.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào N là số phần tử của dãy A[]; dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng trống.
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤100; 0≤A[i] ≤100.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input

2
6
80 60 30 40 20 10
9
1 15 51 45 33 100 12 18 9

Output

210
194
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[105], sum_first[105], sum_last[105];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void solve() {
    sum_first[0] = a[0], sum_last[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++) {
        sum_first[i] = a[i];
        for (int j = 0; j < i; j++)
            if (a[i] > a[j]) sum_first[i] = max(sum_first[i], sum_first[j] + a[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        sum_last[i] = a[i];
        for (int j = n - 1; j > i; j--)
            if (a[i] > a[j]) sum_last[i] = max(sum_last[i], sum_last[j] + a[i]);
    }
    int res = 0;
    for (int i = 0; i < n; i++) res = max(sum_first[i] + sum_last[i] - a[i], res);
    printf("%d\n", res);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        input();
        solve();
    }
    return 0;
}
