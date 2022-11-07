//
// Created by khanh on 10/10/2021.
//

/*
HOÁN VỊ KẾ TIẾP
Cho số tự nhiên N và một hoán vị X[] của 1, 2, .., N. Nhiệm vụ của bạn là đưa ra hoán vị tiếp theo của X[]. Ví dụ N=5, X[] = {1, 2, 3, 4, 5} thì hoán vị tiếp theo của X[] là {1, 2, 3, 5, 4}.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là số N; dòng tiếp theo đưa vào hoán vị X[] của 1, 2, .., N.
T, N, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤ N≤103.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Input

2

5 

1  2  3  4  5

5

5  4  3  2  1

Output

1 2  3  5  4

1 2  3  4  5
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[1005];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
}

void solve() {
    int i;
    for (i = n; i > 1; i--) {
        if (a[i - 1] < a[i]) {
            for (int j = n; j >= i; j--) {
                if (a[j] > a[i - 1]) {
                    swap(a[i - 1], a[j]);
                    int l = i;
                    int r = n;
                    while (l < r) swap(a[l++], a[r--]);
                    break;
                }
            }
            break;
        }
    }
    if (i == 1) for (i = 1; i <= n; i++) printf("%d ", i);
    else for (i = 1; i <= n; i++) printf("%d ", a[i]);
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
