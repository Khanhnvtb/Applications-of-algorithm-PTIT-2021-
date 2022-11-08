//
// Created by Nguyen Van Khanh on 10/29/2021.
//

/*
DUYỆT CÂY NHỊ PHÂN TÌM KIẾM 2
Cho một mảng A[] gồm N phần tử. Nhiệm vụ của bạn là đưa ra 1 nếu mảng A[] biểu diễn phép duyệt inorder của cây nhị phân tìm kiếm, ngược lại đưa ra 0.

      Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào số N là số lượng node của cây tìm kiếm; dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng trống.
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤A[i]≤104;
Output:

Đưa ra kết quả mỗi test theo từng dòng.
     Ví dụ:

Input

3
5
10 20 30 40 50
6
90 80 100 70 40 30
3
1 1 2

Output

1
0
0
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[1005];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void solve() {
    int res = 1;
    for (int i = 1; i < n; i++)
        if (a[i] <= a[i - 1]) {
            res = 0;
            break;
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
