//
// Created by Nguyen Van Khanh on 10/23/2021.
//

#include <bits/stdc++.h>

using namespace std;

int n, m, res = 0, vs[105][105] = {0};
string s;
char c[105][105];

void input() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++)
            c[i][j] = s[j];
    }
}

void dfs(int i, int j) {
    vs[i][j] = 1;
    if (i > 0 && c[i - 1][j] == '#' && vs[i - 1][j] == 0) dfs(i - 1, j);
    if (i < n - 1 && c[i + 1][j] == '#' && vs[i + 1][j] == 0) dfs(i + 1, j);
    if (j > 0 && c[i][j - 1] == '#' && vs[i][j - 1] == 0) dfs(i, j - 1);
    if (j < m - 1 && c[i][j + 1] == '#' && vs[i][j + 1] == 0) dfs(i, j + 1);
}

void solve() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (c[i][j] == '#' && vs[i][j] == 0) {
                res++;
                dfs(i, j);
            }
        }
    printf("%d", res);
}

int main() {
    input();
    solve();
    return 0;
}