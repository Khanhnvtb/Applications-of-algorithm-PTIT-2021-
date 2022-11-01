//
// Created by khanh on 10/8/2021.
//

Cho đồ thị vô hướng G= được biểu diễn dưới dạng danh sách cạnh. Hãy viết thuật toán duyệt theo chiều sâu bắt đầu tại đỉnh uÎV (DFS(u)=?)

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm |E| +1 dòng: dòng đầu tiên đưa vào ba số |V|, |E| tương ứng với số đỉnh và số cạnh của đồ thị, và u là đỉnh xuất phát; |E| dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤200; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra danh sách các đỉnh được duyệt theo thuật toán DFS(u) của mỗi test theo khuôn dạng của ví dụ dưới đây.
      Ví dụ:

Input:
1

6 9 5

1 2

1 3

2 3

2 4

3 4

3 5

4 5

4 6

5 6

Output:

5 3 1 2 4 6
    
#include<bits/stdc++.h>

using namespace std;

int v, e, first, vs[1005];
vector<int> adj[1005];

void input() {
    cin >> v >> e >> first;
    int i, j;
    while (e--) {
        cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
}

void dfs(int u) {
    cout << u << " ";
    vs[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int tmp = adj[u][i];
        if (!vs[tmp]) dfs(tmp);
    }
}

void solve() {
    for (int i = 1; i <= v; i++) vs[i] = 0;
    dfs(first);
    cout << endl;
    for (int i = 1; i <= v; i++) adj[i].clear();
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
