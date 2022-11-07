//
// Created by khanh on 10/9/2021.
//

/*
TẬP CON KẾ TIẾP
Cho hai số N, K và một tập con K phần tử X[] =(X1, X2,.., XK) của 1, 2, .., N. Nhiệm vụ của bạn là hãy đưa ra tập con K phần tử tiếp theo của X[]. Ví dụ N=5, K=3, X[] ={2, 3, 4} thì tập con tiếp theo của X[] là {2, 3, 5}.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là hai số N và K; dòng tiếp theo đưa vào K phần tử của X[] là một tập con K phần tử của 1, 2, .., N.
T, K, N, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤K≤N≤103.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Input

Output

2

5  3

1  4  5

5  3

3  4  5

2  3  4

1  2  3
*/

#include <bits/stdc++.h>

using namespace std;

int n, k, a[1005];

void input() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) scanf("%d", &a[i]);
}

void solve() {
    int i;
    for (i = k; i > 0; i--) {
        if (a[i] != n - k + i) {
            a[i]++;
            for (int j = i + 1; j <= k; j++)
                a[j] = a[i] + j - i;
            break;
        }
    }
    if (i == 0) for (i = 1; i <= k; i++) printf("%d ", i);
    else for (i = 1; i <= k; i++) printf("%d ", a[i]);
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
