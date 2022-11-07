//
// Created by khanhnvtb on 11/7/2022.
//

/*
GIÁ TRỊ LỚN NHẤT

Cho dãy số gồm N phần tử có giá trị ban đầu bằng 0.
Có M phép biến đổi, mỗi phép có dạng (u, v, k): tăng mỗi phần tử từ u tới v lên k đơn vị.
Cho Q câu hỏi, mỗi câu hỏi có dạng (u, v): yêu cầu tìm phần tử lớn nhất trong đoạn [u, v].

Input
Dòng đầu tiên gồm 2 số nguyên N và M (1 <= N, M <= 100 000).
M dòng tiếp theo, mỗi dòng gồm 3 số u, v, k (1 <= k <= 10 000).
Dòng tiếp theo là số nguyên Q (1 <= Q <= 100 000).
Q dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v.
Output
Với mỗi truy vấn, hãy in ra đáp án trên một dòng.
Test ví dụ:

Input

6 2

1 3 2

4 6 3

1

3 4

Output

3
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val, lazy;
};

int n, m;
Node st[4 * 100005];

void down(int id) {
    int k = st[id].lazy;
    st[id * 2].val += k;
    st[id * 2].lazy += k;
    st[id * 2 + 1].val += k;
    st[id * 2 + 1].lazy += k;
    st[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, int k) {
    if (u > r || v < l) return;
    if (u <= l && v >= r) {
        st[id].val += k;
        st[id].lazy += k;
        return;
    }
    down(id);
    int m = (l + r) / 2;
    update(id * 2, l, m, u, v, k);
    update(id * 2 + 1, m + 1, r, u, v, k);
    st[id].val = max(st[id * 2].val, st[id * 2 + 1].val);
}

int get(int id, int l, int r, int u, int v) {
    if (u > r || v < l) return INT_MIN;
    if (u <= l && v >= r) return st[id].val;
    down(id);
    int m = (l + r) / 2;
    return max(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}

int main() {
    scanf("%d %d", &n, &m);
    int u, v, k;
    while (m--) {
        scanf("%d %d %d", &u, &v, &k);
        update(1, 1, n, u, v, k);
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &u, &v);
        printf("%d\n", get(1, 1, n, u, v));
    }
    return 0;
}