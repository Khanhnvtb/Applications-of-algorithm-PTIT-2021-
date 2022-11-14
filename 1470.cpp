//
// Created by khanh on 10/14/2021.
//

/*
HÌNH VUÔNG LỚN NHẤT
Cho một bảng số N hàng, M cột chỉ gồm 0 và 1. Bạn hãy tìm hình vuông có kích thước lớn nhất, sao cho các số trong hình vuông toàn là số 1.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
Mỗi test bắt đầu bởi 2 số nguyên N, M (1 ≤ N, M ≤ 500).
N dòng tiếp theo, mỗi dòng gồm M số mô tả một hàng của bảng.
Output: 

Với mỗi test, in ra đáp án là kích thước của hình vuông lớn nhất tìm được trên một dòng.
Ví dụ:

Input:

2

6 5

0 1 1 0 1

1 1 0 1 0

0 1 1 1 0

1 1 1 1 0

1 1 1 1 1

0 0 0 0 0

2 2

0 0

0 0


Output

3

0
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, a[505][505], d[505][505];

void init() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            d[i][j] = a[i][j];
        }
}

void solve() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != 0) {
                if (a[i][j] == a[i - 1][j - 1] && a[i][j] == a[i][j - 1] && a[i][j] == a[i - 1][j]) {
                    d[i][j] = min (d[i - 1][j - 1], d[i - 1][j]);
                    d[i][j] = min (d[i][j], d[i][j - 1]) + 1;
                }
                res = max (res, d[i][j]);
            }
        }
    }
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init ();
        solve ();
    }
    return 0;
}
