//
// Created by Khanh Nguyen Van on 10/17/2021.
//

/*
Trên bàn cờ vua kích thước 8*8 thì quân vua được phép di chuyển đến cả 8 ô liền kề theo cả đường dọc và đường chéo. Tất nhiên quân vua sẽ không thể di chuyển được ra ngoài bàn cờ.

Cho 2 ô trên bàn cờ gọi là ô bắt đầu và ô kết thúc. Hãy tính xem quân vua cần ít nhất bao nhiêu bước để di chuyển từ ô bắt đầu đến ô kết thúc.

Input

Có 2 cặp số nguyên s1,s2 và f1,f2 lần lượt và vị trí ô bắt đầu và ô kết thúc. Các vị trí đảm bảo nằm trong phạm vi bàn cờ.

Output

Số bước đi ít nhất của quân vua

Ví dụ

Input

4 3 1 6

5 5 5 6

Output
3

1
*/

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
