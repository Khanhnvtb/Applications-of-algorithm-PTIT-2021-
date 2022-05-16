//
// Created by khanh on 10/9/2021.
//

#include <bits/stdc++.h>

using namespace std;

int v, e, vs[105], used[105];
vector<int> edge[105];
vector<int> a;

void input() { //hàm khởi tạo
    cin >> v >> e;
    int i, j;
    while (e--) {
        scanf("%d %d", &i, &j);
        edge[i].push_back(j); //tạo ma trận kề
    }
}

float minPath() { //hàm tìm đường đi nhỏ nhất
    float cnt = 0; //đếm độ lượng đường đi
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            if (i != j) { //tìm đường đi của tất cả các đỉnh đến nhau
                memset(used, 0, sizeof(used));
                queue<int> q; //sử dụng bfs để tìm đường đi nhỏ nhất
                q.push(a[i]); //thêm đỉnh bắt đầu vào hàng đợi
                used[a[i]] = 1; //đánh dấu nó đã được đi qua
                while (!q.empty()) {
                    int u = q.front();
                    for (int k = 0; k < edge[u].size(); k++) { //tìm tất cả các đỉnh kề với nó chưa được đi qua
                        int tmp = edge[u][k];
                        if (!used[tmp]) {
                            used[tmp] = used[u] + 1; //đánh dấu nó đã được đi qua
                            q.push(tmp); //thêm nó vào hàng đợi
                        }
                    }
                    if (used[a[j]] != 0) { //nếu đến đích
                        cnt += used[a[j]] - 1; //tăng độ dài đường đi
                        break;
                    }
                    q.pop();
                }
            }
        }
    }
    return cnt / (a.size() * (a.size() - 1)); //trả về đường đi trung bình nhỏ nhất
}

void solve() { //hàm xử lý
    float res = 32767; //khởi tạo kết quả
    for (int i = 1; i <= v; i++) vs[i] = 0; //đánh dấu tất cả đều chưa được đi qua
    for (int i = 1; i <= v; i++) {
        if (!vs[i]) { //nếu đỉnh chưa được đi qua
            vs[i] = 1; //đánh dấu đỉnh được đi qua
            a.clear();
            a.push_back(i); //thêm đỉnh đó vào hàng đợi
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int j = 0; j < edge[u].size(); j++) { //tìm tất cả các đỉnh chưa đi qua kề với đỉnh u
                    int tmp = edge[u][j];
                    if (!vs[tmp]) {
                        vs[tmp] = 1;
                        q.push(tmp); //thêm đỉnh đó vào hàng đợi
                        a.push_back(tmp); //thêm vào mảng các đỉnh đã duyệt
                    }
                }
            }
            if (a.size() > 1) {
                float f = minPath(); //nếu đỉnh hiện tại có đường đi đến đỉnh khác thì tìm đường đi nhỏ nhất
                if (f < res) res = f; //cập nhật kết quả
            }
        }
    }
    printf("%.2f\n", res); //đưa ra kết quả
    for (int i = 1; i <= v; i++) edge[i].clear(); //làm mới ma trận kề
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        input();
        solve();
    }
    return 0;
}