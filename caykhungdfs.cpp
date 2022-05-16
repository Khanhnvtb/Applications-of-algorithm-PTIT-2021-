//
// Created by Nguyen Van Khanh on 11/13/2021.
//

#include <bits/stdc++.h>
using namespace std;

int v, e, cnt, start, vs[1005];
vector <int> a[1005];
vector <int> res;

void dfs(int u) { //hàm dfs
    vs[u] = 1; //đánh dấu đỉnh được duyệt qua
    cnt++; //tăng số đỉnh được duyệt qua
    for (int i = 0; i < a[u].size (); i++) { //kiểm tra tất cả các đỉnh chưa được duyệt qua kề với đỉnh u
        int tmp = a[u][i];
        if (!vs[tmp]) { //nếu tìm thấy
            vs[tmp] = 1; //đánh dấu đã duyệt qua
            res.push_back (u); //cập nhật kết quả
            res.push_back (tmp);
            dfs (tmp); //gọi lại hàm dfs tại đỉnh đó
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
    dfs (start);
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