//
// Created by khanh on 10/8/2021.
//

/*
HOÁN VỊ NGƯỢC

Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả các hoán vị của 1, 2, .., N theo thứ tự ngược. Ví dụ với N = 3 ta có kết quả: 321, 312, 231, 213, 132, 123.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng.
T, n thỏa mãn ràng buộc: 1≤T, N≤10.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input

2

2

3

Output

21 12 

321 312 231 213 132 123       
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[15], used[15];

void print() {
    for (int i = 1; i <= n; i++) printf("%d", a[i]);
    printf(" ");
}

void Try(int i) {
    for (int j = n; j > 0; j--) {
        if (!used[j]) {
            a[i] = j;
            used[j] = 1;
            if (i == n) print();
            else Try(i + 1);
            used[j] = 0;
        }
    }
}

void input() {
    scanf("%d", &n);
}

void solve() {
    Try(1);
    printf("\n");
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
