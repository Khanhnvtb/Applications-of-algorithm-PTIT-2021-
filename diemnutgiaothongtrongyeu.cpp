/*
Một thành phố có N điểm nút giao thông. Các tuyến đường hai chiều được thiết kế giúp cho người dân có thể đi từ một nút bất kỳ đến tất cả các nút còn lại.

Những nút giao thông trọng yếu được định nghĩa là nút giao thông mà nếu các con đường đến nó đều bị chặn thì thành phố sẽ bị chia cắt, tức là khi đó sẽ có những cặp điểm nút không thể đi đến nhau được nữa.

Giả sử các điểm nút giao thông được đánh số từ 1 đến N. Hãy liệt kê các nút giao thông trọng yếu theo thứ tự tăng dần.

Input

Dòng đầu là số bộ test (không quá 100)
Mỗi bộ test bắt đầu với số nút giao thông N (không quá 1000) và số tuyến đường M.
Tiếp theo là một dòng có M cặp số mô tả các tuyến đường hai chiều trong thành phố.
Output

Dòng đầu ghi ra số lượng điểm nút giao thông trọng yếu

Dòng thứ 2 lần lượt liệt kê các nút giao thông trọng yếu theo thứ tự tăng dần

Ví dụ

Input

1

5 5

1 2 1 3 2 3 2 5 3 4

Output

2

2 3
*/

#include <bits/stdc++.h>

using namespace std;
int v, e, res, vs[1005];
vector<int> a[1005];
vector<int> ans;

void reset() {
    for (int i = 1; i <= v; i++) {
        vs[i] = 0;
    }
    vs[res] = 1;
}

void dfs(int u) {
    vs[u] = 1;
    for (int i = 0; i < a[u].size(); i++) {
        int tmp = a[u][i];
        if (!vs[tmp]) {
            dfs(tmp);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> v >> e;
        while (e--) {
            int i, j;
            cin >> i >> j;
            a[i].push_back(j);
            a[j].push_back(i);
        }
        for (res = 1; res <= v; res++) {
            reset();
            int cnt = 1;
            if (res == 1) {
                dfs(2);
            } else {
                dfs(1);
            }
            for (int i = 1; i <= v; i++) {
                if (!vs[i]) {
                    ans.push_back(res);
                    break;
                }
            }
        }
        cout << ans.size() << endl;
        for (int i: ans) cout << i << " ";
        for (int i = 1; i <= v; i++) {
            a[i].clear();
        }
        cout << endl;
        ans.clear();
    }
    return 0;
}
