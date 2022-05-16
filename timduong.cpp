//
// Created by Nguyen Van Khanh on 11/14/2021.
//

//
// Created by khanh on 02/06/2021.
//

#include <bits/stdc++.h>
using namespace std;
int n, m, start_row, start_col, dest_row, dest_col, vs[505][505];
char a[505][505];
void init() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                start_row = i;
                start_col = j;
            } else if (a[i][j] == 'T') {
                dest_row = i;
                dest_col = j;
            }
        }
    }
}
int bfs() {
    queue <pair <int, int> > q;
    q.push({start_row, start_col});
    while (! q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        if (vs[row][col] == 4) {
            return vs[row][col];
        }
        q.pop();
        for (int i = row - 1; i >= 0; i --) {
            if (a[i][col] == '*') {
                break;
            } else {
                if (vs[i][col] == 0) {
                    vs[i][col] = vs[row][col] + 1;
                    q.push({i, col});
                }
            }
        }
        for (int i = row + 1; i < n; i ++) {
            if (a[i][col] == '*') {
                break;
            } else {
                if (vs[i][col] == 0) {
                    vs[i][col] = vs[row][col] + 1;
                    q.push({i, col});
                }
            }
        }
        for (int i = col - 1; i >= 0; i --) {
            if (a[row][i] == '*') {
                break;
            } else {
                if (vs[row][i] == 0) {
                    vs[row][i] = vs[row][col] + 1;
                    q.push({row, i});
                }
            }
        }
        for (int i = col + 1; i < m; i ++) {
            if (a[row][i] == '*') {
                break;
            } else {
                if (vs[row][i] == 0) {
                    vs[row][i] = vs[row][col] + 1;
                    q.push({row, i});
                }
            }
        }
        if (vs[dest_row][dest_col] != 0) {
            return vs[dest_row][dest_col] - 1;
        }
    }
    return 4;
}
void solve() {
    memset(vs, 0, sizeof(vs));
    vs[start_row][start_col] = 1;
    if (bfs() <= 3) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        init();
        solve();
    }
    return 0;
}