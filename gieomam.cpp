//
// Created by Nguyen Van Khanh on 11/7/2021.
//

#include <bits/stdc++.h>
using namespace std;

int n, m, cnt, res, a[505][505];
queue <pair <int, int> > q;

void init() { //hàm khởi tạo
    while (!q.empty ()) q.pop (); //làm trống hàng đợi
    cin >> n >> m;
    cnt = 0, res = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) cnt++; //tăng số hạt mầm
            else if (a[i][j] == 2) q.push ({i, j}); //thêm cây cây non vào hàng đợi
        }
}

int bfs() { //hàm bfs
    int tmp = q.size(); //khởi tạo số cây non
    while (! q.empty()) {
        tmp --;
        int i = q.front().first; //lấy ra cây ở đầu
        int j = q.front().second;
        q.pop();
        //tìm ở 4 hướng của cây con
        if (i > 0 && a[i - 1][j] == 1) { //nếu tìm thấy hạt mầm
            a[i - 1][j] = 2; //chuyển thành cây con
            cnt --; //giảm số cây con
            q.push({i - 1, j});
        }
        if (j > 0 && a[i][j - 1] == 1) {
            a[i][j - 1] = 2;
            cnt --;
            q.push({i, j - 1});
        }
        if (i < n - 1 && a[i + 1][j] == 1) {
            a[i + 1][j] = 2;
            cnt --;
            q.push({i + 1, j});
        }
        if (j < m - 1 && a[i][j + 1] == 1) {
            a[i][j + 1] = 2;
            cnt --;
            q.push({i, j + 1});
        }
        if (cnt == 0) return res; //nếu tất cả đã nảy mầm thì trả về kết quả
        if (tmp == 0) { //nếu đã lan truyền hết cây con của hàng hôm nay
            tmp = q.size(); //đi đến ngày hôm sau
            res ++; //tăng số ngày lên
        }
    }
    return - 1; //nếu không thể nảy đưa ra -1
}
void solve() {
    cout << bfs() << endl;
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