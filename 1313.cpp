//
// Created by khanh on 10/10/2021.
//

/*
TẬP CON LIỀN KỀ PHÍA TRƯỚC
Cho hai số N, K và một tập con K phần tử X[] =(X1, X2,.., XK) của 1, 2, .., N. Nhiệm vụ của bạn là hãy đưa ra tập con K phần tử trước đó của X[]. Ví dụ N=5, K=3, X[] ={2, 3, 5} thì tập con trước đó của X[] là {2, 3, 4}. Chú ý nếu tập con trong input là đầu tiên thì trước đó là tập con cuối cùng.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là hai số N và K; dòng tiếp theo đưa vào K phần tử của X[] là một tập con K phần tử của 1, 2, .., N.
T, K, N, X[] thỏa mãn ràng buộc: 1≤T≤100; 1≤K≤N≤103.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input

2

5  3

2  3  5

5  3

1  2  3

Output

2 3 4

3 4 5
*/

#include <bits/stdc++.h>

using namespace std;

int n, k, a[1005];

void init() { //hàm khởi tạo
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) scanf("%d", &a[i]);
}

void solve() {
    int check = 0;
    for (int i = k; i > 1; i--)
        if (a[i] > a[i - 1] + 1) { //nếu phần tử hiện tại lớn hơn phần tử trước nó + 1
            a[i]--; //giảm phần tử hiện tại
            check = 1; //đánh dấu tìm được cấu hình
            for (int j = i + 1; j <= k; j++) a[j] = n - k + j; //gán các phần tử sau nó đến trần
            break;
        }
    if (check == 0) { //nếu không tìm được phần tử thoả mãn
        if (a[1] == 1) { //nếu là cấu hình đầu tiên
            for (int i = 1; i <= k; i++) printf("%d ", n - k + i); //đưa ra cấu hình cuối cùng
            printf("\n");
        } else { //nếu không phải cấu hình đầu tiên
            a[1]--; //giảm phần tử đầu tiên đi 1
            printf("%d ", a[1]);
            for (int i = 2; i <= k; i++) printf("%d ", n - k + i); //gán các phần tử sau đến trần
            printf("\n");
        }
    } else {
        for (int i = 1; i <= k; i++) printf("%d ", a[i]); //đưa ra kết quả
        printf("\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        init();
        solve();
    }
    return 0;
}
