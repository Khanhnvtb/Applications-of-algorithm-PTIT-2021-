//
// Created by khanh on 10/9/2021.
//

/*
LIỆT KÊ CẠNH CẦU

Bài làm tốt nhất
Cho đồ thị vô hướng liên thông G= được biểu diễn dưới dạng danh sách cạnh. Sử dụng thuật toán DFS hoặc BFS, hãy đưa ra tất cả các cạnh cầu của đồ thị?

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh và số cạnh; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra danh sách các cạch cầu của mỗi test theo từng dòng. In ra đáp án theo thứ tự từ điển, theo dạng “a b …” với a < b.
Ví dụ:

Input:

1

5 5

1 2 1 3 2 3 2 5 3 4

Output:

2 5 3 4
*/
#include <bits/stdc++.h>

using namespace std;

int v, e, vs[1005];
vector<int> adj[1005];
vector<pair<int, int>> edge;
vector<int>::iterator i1, i2;

void input() {
    scanf("%d %d", &v, &e);
    int i, j;
    while (e--) {
        scanf("%d %d", &i, &j);
        adj[i].push_back(j);
        adj[j].push_back(i);
        edge.push_back({i, j});
    }
}

int bfs() {
    int u, cnt = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int tmp = adj[u][i];
            if (!vs[tmp]) {
                cnt++;
                vs[tmp] = 1;
                q.push(tmp);
            }
        }
    }
    return cnt;
}

void solve() {
    vs[1] = 1;
    for (int i = 0; i < edge.size(); i++) {
        int x = edge[i].first, y = edge[i].second;
        i1 = find(adj[x].begin(), adj[x].end(), y);
        i2 = find(adj[y].begin(), adj[y].end(), x);
        adj[x].erase(i1);
        adj[y].erase(i2);
        for (int j = 2; j <= v; j++) vs[j] = 0;
        if (bfs() != v) printf("%d %d ", x, y);
        adj[x].insert(i1, y);
        adj[y].insert(i2, x);
    }
    printf("\n");
    for (int i = 1; i <= v; i++) adj[i].clear();
    edge.clear();
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
