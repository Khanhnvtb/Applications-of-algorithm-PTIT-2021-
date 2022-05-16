#include <bits/stdc++.h>

using namespace std;

int k, n, m, vs[1005];
vector<int> edge[1005];
vector<int> a;
set<int> res;
set<int>::iterator it;

void init() { //hàm khởi tạo
    cin >> k >> n >> m;
    while (k--) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int i, j;
    while (m--) {
        cin >> i >> j;
        edge[i].push_back(j);  //tạo ma trận kề
    }
}

void bfs(int u) { //hàm bfs
    set<int> s;
    for (it = res.begin(); it != res.end(); it++) s.insert(*it); //thêm các đia điểm còn có thể đến vào s
    res.clear(); //làm mới kết quả
    res.insert(u); //thêm địa điểm hiện tại vào kết quả
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < edge[u].size(); i++) { //tìm tất cả các địa điểm mà từ u có thể đi tới
            int tmp = edge[u][i];
            if (!vs[tmp] && s.find(tmp) != s.end()) { //nếu địa điểm đó có thể đến được
                res.insert(tmp); //thêm địa điểm đó vào kết quả
                q.push(tmp);
                vs[tmp] = 1; //đánh dấu nó đã đi qua
            }
        }
    }
}

void solve() { //hàm xử lý
    for (int i = 1; i <= n; i++) res.insert(i); //thêm tất cả địa điểm vào kết quả
    for (int i = 0; i < a.size(); i++) {
        for (int j = 1; j <= n; j++) vs[j] = 0; //đánh dấu chưa thăm địa điểm nào
        bfs(a[i]); //thực hiện bfs tại điểm đó
    }
    cout << res.size() << endl; //đưa ra kết quả
    res.clear(); //làm mới kết quả
}

int main() {
    init();
    solve();
    return 0;
}