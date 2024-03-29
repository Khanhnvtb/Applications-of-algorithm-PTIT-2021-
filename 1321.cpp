//
// Created by khanh on 10/11/2021.
//

/*
SẮP XẾP CÔNG VIỆC

Cho hệ gồm N hành động. Mỗi hành động được biểu diễn như một bộ đôi <Si, Fi> tương ứng với thời gian bắt đầu và thời gian kết thúc của mỗi hành động. Hãy tìm phương án thực hiện nhiều nhất các hành động được thực hiện bởi một máy hoặc một người sao cho hệ không xảy ra mâu thuẫn.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng thứ nhất đưa vào số lượng hành động N; dòng tiếp theo đưa vào N số Si tương ứng với thời gian bắt đầu mỗi hành động; dòng cuối cùng đưa vào N số Fi tương ứng với thời gian kết thúc mỗi hành động; các số được viết cách nhau một vài khoảng trống.
T, N, Si, Fi thỏa mãn ràng buộc: 1≤T≤100;  1≤N, Fi, Si≤1000.
Output:

Đưa số lượng lớn nhất các hành động có thể được thực thi bởi một máy hoặc một người.
Ví dụ:

Input

1

6

1  3  0  5  8  5

2  4  6  7  9  9

Output

4
*/

#include <bits/stdc++.h>

using namespace std;

struct data {
    int s, e;
};

int n;
data a[1005];

int cmp(data x, data y) {
    if (x.e < y.e) return 1;
    if (x.e == y.e && x.s < y.s) return 1;
    return 0;
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i].s);
    for (int i = 0; i < n; i++) scanf("%d", &a[i].e);
}

void solve() {
    sort(a, a + n, cmp);
    int res = 1, prev = a[0].e;
    for (int i = 1; i < n; i++)
        if (a[i].s >= prev) {
            res++;
            prev = a[i].e;
        }
    printf("%d\n", res);
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
