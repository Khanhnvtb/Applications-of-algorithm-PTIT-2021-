//
// Created by Nguyen Van Khanh on 11/13/2021.
//

#include <bits/stdc++.h>
using namespace std;
int v, e, cnt, start, vs[1005];
vector <int> a[1005];
vector <int> res;

void bfs(int u) { //hàm bfs
    vs[u] = 1; //đánh dấu đã thăm
    queue <int> q;
    q.push (u);
    while (!q.empty ()) {
        u = q.front (); //gán u là đỉnh ở đầu hàng đợi
        cnt++; //tăng số đỉnh đã thăm
        q.pop ();
        for (int i = 0; i < a[u].size (); i++) { //tìm tất cả các đỉnh chưa thăm kề với đỉnh u
            int tmp = a[u][i];
            if (!vs[tmp]) {
                vs[tmp] = 1; //đánh dấu là đã thăm
                q.push (tmp); //đưa đỉnh đó vào hàng đợi
                res.push_back (u); //cập nhật kết quả
                res.push_back (tmp);
            }
        }
    }
}

void init() { //hàm khởi tạo
    res.clear ();
    cin >> v >> e >> start;
    while (e--) {
        int x, y;
        cin >> x >> y;
        a[x].push_back (y); //tạo ma trận kề
        a[y].push_back (x);
    }
}

void solve() { //hàm xử lý
    cnt = 0;
    memset (vs, 0, sizeof (vs));
    bfs (start);
    if (cnt == v)
        for (int i = 0; i < res.size (); i += 2) cout << res[i] << " " << res[i + 1] << endl; //đưa ra kết quả
    else cout << "-1" << endl;
    for (int i = 1; i <= v; i++) a[i].clear (); //làm mới ma trận kề
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