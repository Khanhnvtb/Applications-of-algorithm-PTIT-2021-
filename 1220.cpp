//
// Created by khanh on 10/9/2021.
//

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