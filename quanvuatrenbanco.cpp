//
// Created by Khanh Nguyen Van on 10/17/2021.
//

#include <bits/stdc++.h>

using namespace std;

int s1, s2, f1, f2;
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

bool check(int x, int y) {
    if (x == 0 || y == 0 || x > 8 || y > 8) return false;
    return true;
}

void input() {
    scanf("%d %d %d %d", &s1, &s2, &f1, &f2);
}

int bfs() {
    if (s1 == f1 && s2 == f2) return 0;
    queue<pair<pair<int, int>, int>> q;
    q.push({{s1, s2}, 0});
    while (1) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second + 1;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int X = x + dx[i];
            int Y = y + dy[i];
            if (check(X, Y)) {
                if (X == f1 && Y == f2) return cnt;
                else q.push({{X, Y}, cnt});
            }
        }
    }
}

void solve() {
    printf("%d", bfs());
}

int main() {
    input();
    solve();
    return 0;
}
