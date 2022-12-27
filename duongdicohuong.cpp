//
// Created by Nguyen Van Khanh on 11/14/2021.
//

/*
Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh.

Hãy tìm đường đi từ đỉnh u đến đỉnh v trên đồ thị bằng thuật toán BFS.

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm |E|+1 dòng: dòng đầu tiên đưa vào bốn số |V|, |E|, u, v tương ứng với số đỉnh, số cạnh,  đỉnh xuất phát u, đỉnh kết thúc v;
|E| dòng tiếp theo mỗi dòng đưa vào bộ đôi x, y tương ứng với một cạnh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra đường đi từ đỉnh s đến đỉnh t của mỗi test theo thuật toán BFS của mỗi test theo khuôn dạng của ví dụ dưới đây. Nếu không có đáp án, in ra -1.
Ví dụ:

Input

1

6 9 1 6

1 2  

2 5

3 1

3 2

3 5

4 3

5 4

5 6

6 4

Output

1 -> 2 -> 5 -> 6
*/

#include <bits/stdc++.h>

using namespace std;

int v, e, f, l, pre[1005];
vector<int> a[1005];

void input() {
    scanf("%d %d %d %d", &v, &e, &f, &l);
    int i, j;
    while (e--) {
        scanf("%d %d", &i, &j);
        a[i].push_back(j);
    }
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    pre[u] = 0;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < a[u].size(); i++) {
            int tmp = a[u][i];
            if (pre[tmp] == 0) {
                pre[tmp] = u;
                q.push(tmp);
                if (tmp == l) return;
            }
        }
    }
}

void solve() {
    for (int i = 1; i <= v; i++) pre[i] = 0;
    bfs(f);
    vector<int> res;
    while (l != 0) {
        res.push_back(l);
        l = pre[l];
    }
    if (res.size() < 2) printf("-1\n");
    else {
        for (int i = res.size() - 1; i > 0; i--)
            printf("%d -> ", res[i]);
        printf("%d\n", res[0]);
    }
    for (int i = 1; i <= v; i++) a[i].clear();
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        input();
        solve();
    }
    return 0;
}
