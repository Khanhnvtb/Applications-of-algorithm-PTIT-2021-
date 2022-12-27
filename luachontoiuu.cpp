//
// Created by Nguyen Van Khanh on 10/23/2021.
//

/*
Bạn được giao cho N công việc, công việc thứ i có thời gian bắt đầu là A[i] và kết thúc tại B[i]. Tại một thời điểm, bạn chỉ có thể làm một công việc.

Bạn hãy lựa chọn các công việc một cách tối ưu sao cho số công việc làm được là nhiều nhất.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

Mỗi test gồm 1 số nguyên N ( 1 ≤ N ≤ 100 000).

N dòng tiếp theo, mỗi dòng gồm 2 số A[i] và B[i] (0 ≤ A[i] < B[i] ≤ 106).

Output:  Với mỗi test, in ra đáp án trên một dòng.

Ví dụ:

Input

1

6

5 9

1 2

3 4

0 6

5 7

8 9

Output

4

Giải thích test: Lựa chọn công việc 2, 3, 5, 6.
*/

#include <bits/stdc++.h>

using namespace std;

struct job {
    int start, end;
};

int n;
job a[100005];

int cmp(job x, job y) {
    if (x.end < y.end) return 1;
    if (x.end == y.end && x.start < y.start) return 1;
    return 0;
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d %d", &a[i].start, &a[i].end);
}

void solve() {
    sort(a, a + n, cmp);
    int ans = 1, prev = a[0].end;
    for (int i = 1; i < n; i++) {
        if (a[i].start >= prev) {
            ans++;
            prev = a[i].end;
        }
    }
    printf("%d\n", ans);
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
