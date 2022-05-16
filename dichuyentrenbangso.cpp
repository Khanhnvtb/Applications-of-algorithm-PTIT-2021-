//
// Created by Nguyen Van Khanh on 11/6/2021.
//

#include <bits/stdc++.h>
using namespace std;

int n, m, a[505][505], d[505][505];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool check(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return false;
    return true;
}

void init() { //hàm khởi tạo
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
}

void solve() { //hàm xử lý
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            d[i][j] = INT_MAX; //đánh dấu chưa có đường đi
    d[0][0] = a[0][0]; //khởi tạo giá trị ban đầu
    queue <pair <int, int> > q;
    q.push ({0, 0}); //đưa điểm đầu vào hàng đợi
    while (!q.empty ()) {
        int i = q.front ().first;
        int j = q.front ().second;
        q.pop ();
        for (int k = 0; k < 4; k++) { //thử với 4 hướng
            int x = i + dx[k];
            int y = j + dy[k];
            if (check (x, y) && d[i][j] + a[x][y] < d[x][y]) {
                d[x][y] = d[i][j] + a[x][y]; //cập nhật kết quả
                q.push ({x, y}); //đưa điểm hiện tại vào hàng đợi
            }
        }
    }
    cout << d[n - 1][m - 1] << endl; //đưa ra kết quả
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