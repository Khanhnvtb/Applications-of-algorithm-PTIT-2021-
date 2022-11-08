//
// Created by Khanh Nguyen Van on 10/15/2021.
//

/*
CÂY NHỊ PHÂN TÌM KIẾM CÂN BẰNG 1

Bài làm tốt nhất
Hãy xây dựng một cây nhị phân tìm kiếm cân bằng từ dãy số A[] =(a0, a1, .., an-1}. Đưa ra nội dung node gốc của cây tìm kiếm cân bằng.  Ví dụ với dãy A[]={40, 28, 45, 38, 33, 15, 25, 20, 23, 35, 30} ta sẽ có cây nhị phân tìm kiếm cân bằng với node gốc là 33.

     Input:

Dòng đầu tiên đưa vào số lượng bộ test T (T≤100).
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất là số tự nhiên N (N≤106). Dòng tiếp theo là N số của mảng A[].
     Output:

Đưa ra kết quả mỗi test theo từng dòng.
     Ví dụ:

Input

2

11

40  28  45 38  33  15  25  20  23  35  30

10

1  2  3  4  5  6  7  8  9  10

Output

30

5
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[1000005];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void solve() {
    sort(a, a + n);
    if (n % 2 == 1) printf("%d\n", a[n / 2]);
    else printf("%d\n", a[n / 2 - 1]);
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
