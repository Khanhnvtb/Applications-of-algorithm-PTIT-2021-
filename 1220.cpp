//
// Created by khanh on 10/9/2021.
//

/*
ĐƯỜNG ĐI NGẮN NHẤT

Bài làm tốt nhất
Cho đơn đồ thị vô hướng liên thông G = (V, E) gồm N đỉnh và M cạnh, các đỉnh được đánh số từ 1 tới N và các cạnh được đánh số từ 1 tới M.

Có Q truy vấn, mỗi truy vấn yêu cầu bạn tìm đường đi ngắn nhất giữa đỉnh X[i] tới Y[i].

Input:

Dòng đầu tiên hai số nguyên N và M (1 ≤ N ≤ 100, 1 ≤ M ≤ N*(N-1)/2).
M dòng tiếp theo, mỗi dòng gồm 3 số nguyên u, v, c cho biết có cạnh nối giữa đỉnh u và v có độ dài bằng c (1 ≤ c ≤ 1000).
Tiếp theo là số lượng truy vấn Q (1 ≤ Q ≤ 100 000).
Q dòng tiếp theo, mỗi dòng gồm 2 số nguyên X[i], Y[i].
Output: 

Với mỗi truy vấn, in ra đáp án là độ dài đường đi ngắn nhất tìm được.
Ví dụ:

Input:

5 6

1 2 6

1 3 7

2 4 8

3 4 9

3 5 1

4 5 2

3

1 5

2 5

4 3

Output

8

10

3
*/
#include <bits/stdc++.h>

using namespace std;

int v, e, d[1005][1005];


void input() {
    scanf("%d %d", &v, &e);
    int i, j, k;
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INT_MAX;
        }
    while (e--) {
        scanf("%d %d %d", &i, &j, &k);
        d[i][j] = k;
        d[j][i] = k;
    }
}

void solve() {
    int q;
    scanf("%d", &q);
    for (int k = 1; k <= v; k++)
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                if (d[i][k] != INT_MAX && d[k][j] != INT_MAX && d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
    while (q--) {
        int start, end;
        scanf("%d %d", &start, &end);
        printf("%d\n", d[start][end]);
    }
}

int main() {
    input();
    solve();
    return 0;
}
