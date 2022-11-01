//
// Created by khanhnvtb on 11/1/2022.
//

/*
KIỂM TRA ĐƯỜNG ĐI

Bài làm tốt nhất
Cho đồ thị vô hướng có N đỉnh và M cạnh. Có Q truy vấn, mỗi truy vấn yêu cầu trả lời câu hỏi giữa 2 đỉnh x và y có tồn tại đường đi tới nhau hay không?

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm 2 số nguyên N, M (1 ≤ N, M ≤ 1000).
M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết có cạnh nối giữa đỉnh u và v.
Dòng tiếp là số lượng truy vấn Q (1 ≤ Q ≤ 1000).
Q dòng tiếp theo, mỗi dòng gồm 2 số nguyên x và y.
Output:  Với mỗi truy vấn, in ra “YES” nếu có đường đi từ x tới y, in ra “NO” nếu ngược lại.

Ví dụ:

Input:

1

5 5

1 2

2 3

3 4

1 4

5 6

2

1 5

2 4

Output:

NO

YES
*/

#include <bits/stdc++.h>

using namespace std;

int vs[1005];

int n, m;
vector<int> a[1005];

void input() {
    scanf("%d %d", &n, &m);
    int i, j;
    while (m--) {
        scanf("%d %d", &i, &j);
        a[i].push_back(j);
        a[j].push_back(i);
    }
}

void dfs(int u, int cnt) {
    vs[u] = cnt;
    for (int v: a[u])
        if (!vs[v]) dfs(v, cnt);
}

void solve() {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!vs[i]) {
            cnt++;
            dfs(i, cnt);
        }
    int q, i, j;
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &i, &j);
        if (vs[i] == vs[j]) printf("YES\n");
        else printf("NO\n");
    }
    for (i = 1; i <= n; i++) {
        a[i].clear();
        vs[i] = 0;
    }
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