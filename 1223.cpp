//
// Created by khanh on 10/9/2021.
//

/*
ĐƯỜNG ĐI TRUNG BÌNH
Cho một đồ thị có hướng gồm N đỉnh và M cạnh. Nhiệm vụ của bạn là hãy tính khoảng cách trung bình ngắn nhất giữa hai nút bất kì nếu như chúng liên thông với nhau. Input đảm bảo rằng trong một nhóm liên thông, nếu như u đi tới được v thì v cũng đi tới được v với mọi cặp u, v.

Input:Dòng đầu tiên là số lượng bộ test T (T ≤ 20). Mỗi test bắt đầu bởi hai số nguyên N và M (1 ≤ N ≤ 100, M ≤ N*(N-1)/2). M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết có cạnh nối đơn hướng từ u tới v.

Output:  Với mỗi test, in ra đáp án tìm được với độ chính xác 2 chữ số sau dấu phảy.

Ví dụ:

Input:

Output

2

4 5

1 2

2 4

1 3

3 1

4 3

7 5

1 2

1 4

4 2

2 7

7 1

1.83

1.75

Giải thích test 1: Ta có

d(1, 2) = 1, d(1, 3) = 1, d(1, 4) = 2; d (2, 1) = 3, d(2, 3) = 2, d(2, 4) = 1;

d(3, 1) = 1, d(3, 2) = 2, d(3, 4) = 3; d(4, 1) = 2, d(4, 2) = 3, d(4, 3) = 1.

Trung bình bằng 22/12 = 1.83
*/

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
