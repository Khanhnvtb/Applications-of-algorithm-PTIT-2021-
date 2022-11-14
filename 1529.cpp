//
// Created by khanh on 10/13/2021.
//

/*
BÀI 16. DI CHUYỂN TRÁNH VẬT CẢN

Cho một bảng kích thước N x N, trong đó có các ô trống ‘.’ và vật cản ‘X’. Các hàng và các cột được đánh số từ 0.

Mỗi bước di chuyển, bạn có thể đi từ ô (x, y) tới ô (u, v) nếu như 2 ô này nằm trên cùng một hàng hoặc một cột, và không có vật cản nào ở giữa.

Cho điểm xuất phát và điểm đích. Bạn hãy tính số bước di chuyển ít nhất?

Input:

Dòng đầu ghi số bộ test (không quá 10). Mỗi test gồm:
Dòng đầu tiên là số nguyên dương N (1 ≤ N ≤ 100).
N dòng tiếp theo, mỗi dòng gồm N kí tự mô tả bảng.
Cuối cùng là 4 số nguyên a, b, c, d với (a, b) là tọa độ điểm xuất phát, (c, d) là tọa độ đích. Dữ liệu đảm bảo hai vị trí này không phải là ô có vật cản.
 
Output: 

Với mỗi test, in ra một số nguyên là đáp số của bài toán.

Ví dụ:


Input

1

3

.X.

.X.

...

0 0 0 2

Output

3
*/

#include <bits/stdc++.h>

using namespace std;

int n, start_row, start_col, dest_row, dest_col, vs[105][105];
char a[105][105];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) a[i][j] = s[j];
    }
    scanf("%d %d %d %d", &start_row, &start_col, &dest_row, &dest_col);
    memset(vs, 0, sizeof(vs));
    vs[start_row][start_col] = 1;
}

int bfs() {
    queue<pair<int, int> > q;
    q.push({start_row, start_col});
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int i = row - 1; i >= 0; i--) {
            if (a[i][col] == 'X') break;
            else {
                if (vs[i][col] == 0) {
                    vs[i][col] = vs[row][col] + 1;
                    q.push({i, col});
                }
            }
        }
        for (int i = row + 1; i < n; i++) {
            if (a[i][col] == 'X') break;
            else {
                if (vs[i][col] == 0) {
                    vs[i][col] = vs[row][col] + 1;
                    q.push({i, col});
                }
            }
        }
        for (int i = col - 1; i >= 0; i--) {
            if (a[row][i] == 'X') break;
            else {
                if (vs[row][i] == 0) {
                    vs[row][i] = vs[row][col] + 1;
                    q.push({row, i});
                }
            }
        }
        for (int i = col + 1; i < n; i++) {
            if (a[row][i] == 'X') break;
            else {
                if (vs[row][i] == 0) {
                    vs[row][i] = vs[row][col] + 1;
                    q.push({row, i});
                }
            }
        }
        if (vs[dest_row][dest_col] != 0) return vs[dest_row][dest_col] - 1;
    }
}

void solve() { //hàm xử lý
    printf("%d\n", bfs());
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
