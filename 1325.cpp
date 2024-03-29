//
// Created by khanh on 10/11/2021.
//

/*
GẤP ĐÔI DÃY SỐ
Một dãy số tự nhiên bắt đầu bởi con số 1 và được thực hiện N-1 phép biến đổi “gấp đôi” dãy số như sau:

Với dãy số A hiện tại, dãy số mới có dạng A, x, A trong đó x là số tự nhiên bé nhất chưa xuất hiện trong A.

Ví dụ với 2 bước biến đổi, ta có [1] à [1 2 1] à [1 2 1 3 1 2 1].

Các bạn hãy xác định số thứ K trong dãy số cuối cùng là bao nhiêu?

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test gồm số nguyên dương N và K (1 ≤ N ≤ 50, 1 ≤ K ≤ 2N - 1).

Output: 

Với mỗi test, in ra đáp án trên một dòng.

Ví dụ:

Input

2

3 2

4 8


Output

2

4

Giải thích test 1: Dãy số thu được là [1, 2, 1, 3, 1, 2, 1].

Giải thích test 2: Dãy số thu được là [1, 2, 1, 3, 1, 2, 1, 4, 1, 2, 1, 3, 1, 2, 1].
*/

#include <bits/stdc++.h>

using namespace std;

int n;
long long k;

void input() {
    scanf("%d %lld", &n, &k);
}

long long find(int n, long long k) {
    if (k == pow(2, n - 1)) return n;
    if (k > pow(2, n - 1)) return find(n - 1, k - pow(2, n - 1));
    return find(n - 1, k);
}

void solve() {
    printf("%lld\n", find(n, k));
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
