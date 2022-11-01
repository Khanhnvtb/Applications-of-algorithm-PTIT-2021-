//
// Created by khanh on 10/9/2021.
//

/*
MẠNG XÃ HỘI

Bài làm tốt nhất
Tý đang xây dựng một mạng xã hội và mời các bạn của mình dùng thử. Bạn của bạn cũng là bạn. Vì vậy, Tý muốn mạng xã hội của mình là hoàn hảo, tức với mọi bộ ba X, Y, Z, nếu X kết bạn với Y, Y kết bạn với Z thì X và Z cũng phải là bạn bè của nhau trên mạng xã hội.

Các bạn hãy xác định xem mạng xã hội hiện tại của Tý có là hoàn hảo hay không? Nếu có hãy in ra “YES”, “NO” trong trường hợp ngược lại.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test bắt đầu bởi 2 số nguyên N và M (N, M ≤ 100 000).
M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v (u #v) cho biết u và v là kết bạn với nhau trên mạng xã hội của Tý.
Output: 

Với mỗi test, in ra đáp án tìm được trên một dòng.
Ví dụ:

Input:

3

4 3

1 3

3 4

1 4

4 4

3 1

2 3

3 4

1 2

10 4

4 3

5 10

8 9

1 2

Output

YES

NO

YES
*/

#include<bits/stdc++.h>

using namespace std;

int v, e, vs[100005];
long cntEdge;
vector<int> adj[100005];

void input() {
    cin >> v >> e;
    int i, j;
    for (int k = 0; k < e; k++) {
        cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    int cnt = 1;
    vs[u] = 1;
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
    cntEdge += cnt * (cnt - 1) / 2;
}

void solve() {
    cntEdge = 0;
    for (int i = 1; i <= v; i++) vs[i] = 0;
    for (int i = 1; i <= v; i++)
        if (!vs[i]) bfs(i);
    if (cntEdge != e) printf("NO\n");
    else printf("YES\n");
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
