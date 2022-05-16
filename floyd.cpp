//
// Created by Nguyen Van Khanh on 11/14/2021.
//

#include <bits/stdc++.h>

using namespace std;

int v, e, d[105][105];

void input() {
    scanf("%d %d", &v, &e);
    int i, j, k;
    for (i = 1; i <= v; i++)
        for (j = 1; j <= v; j++) {
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
    for (int k = 1; k <= v; k++)
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                if (d[i][k] != INT_MAX && d[k][j] != INT_MAX)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    int q;
    scanf("%d", &q);
    int s, t;
    while (q--) {
        scanf("%d %d", &s, &t);
        printf("%d\n", d[s][t]);
    }
}

int main() {
    input();
    solve();
    return 0;
}
