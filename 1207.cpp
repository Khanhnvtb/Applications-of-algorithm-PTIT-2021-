//
// Created by khanh on 10/9/2021.
//

/*
ĐỒ THỊ HAI PHÍA

Bài làm tốt nhất
Đồ thị hai phía là một đồ thị đặc biệt, trong đó tập các đỉnh có thể được chia thành hai tập không giao nhau thỏa mãn điều kiện không có cạnh nối hai đỉnh bất kỳ thuộc cùng một tập. Cho đồ thị N đỉnh và M cạnh, bạn hãy kiểm tra đồ thị đã cho có phải là một đồ thị hai phía hay không?

 

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤  20).
Mỗi test bắt đầu bởi số nguyên N và M (1 ≤  N, M ≤  1000).
M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết có cạnh nối giữa đỉnh u và v.
Output: 

Với mỗi test, in ra “YES” nếu đồ thị đã cho là một đồ thị hai phía, in ra “NO” trong trường hợp ngược lại.
Ví dụ:

Input:

2

5 4

1 5

1 3

2 3

4 5

3 3

1 2

1 3

2 3

Output

YES

NO
*/
#include <bits/stdc++.h>

using namespace std;

int v, e, vs[1005];
vector<int> adj[1005];

void input() {
    scanf("%d %d", &v, &e);
    int i, j;
    while (e--) {
        scanf("%d %d", &i, &j);
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
}

bool isTwoSideGraph(int u) {
    queue<int> q;
    q.push(u);
    vs[u] = 1;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int tmp = adj[u][i];
            if (vs[tmp] == 0) {
                vs[tmp] = -vs[u];
                q.push(tmp);
            } else {
                if (vs[tmp] == vs[u]) return false;
            }
        }
    }
    return true;
}

void solve() {
    int state = 1;
    for (int i = 1; i <= v; i++) vs[i] = 0;
    for (int i = 1; i <= v; i++) {
        if (vs[i] == 0)
            if (!isTwoSideGraph(i)) {
                state = 0;
                break;
            }
    }
    if (state) printf("YES\n");
    else printf("NO\n");
    for (int i = 1; i <= v; i++) adj[i].clear();
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
