//
// Created by Nguyen Van Khanh on 10/30/2021.
//

/*
Cho mảng A[] gồm n phần tử. Hãy tìm dãy con liên tục của mảng A[R], .., A[L] sao cho khi sắp xếp lại dãy con ta nhận được một mảng được sắp xếp. Ví dụ với A[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60} ta chỉ cần sắp xếp lại dãy con từ A[4],.., A[9]: {30, 25, 40, 32, 31, 35} để có mảng được sắp.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n là số phần tử của mảng A[]; dòng tiếp theo là n số A [i] của mảng A []các số được viết cách nhau một vài khoảng trống.
T, n, A[i] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n ≤106; 0≤ A[i] ≤107.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
 Ví dụ:

Input:

2
11
10 12 20 30 25 40 32 31 35 50 60
9
0 1 15 25 6 7 30 40 50

Output:

4 9
3 6
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[1000005];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void solve() {
    int l = 0, r = n - 1;
    while (a[l] <= a[l + 1] && l < n - 1) l++;
    while (a[r] >= a[r - 1] && r > 0) r--;
    long min = a[l], max = a[l];
    for (long i = l + 1; i <= r; i++) {
        if (a[i] < min)min = a[i];
        if (a[i] > max) max = a[i];
    }
    for (long i = 0; i <= l; i++)
        if (a[i] > min) {
            l = i + 1;
            break;
        }
    for (long i = n - 1; i >= r; i--)
        if (a[i] < max) {
            r = i + 1;
            break;
        }
    cout << l << " " << r << endl;
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
