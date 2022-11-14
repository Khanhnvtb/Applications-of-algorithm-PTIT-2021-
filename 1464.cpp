//
// Created by khanh on 10/12/2021.
//

/*
BÀI 15. BÀI TOÁN CÁI TÚI KHÔNG NGUYÊN

Bài làm tốt nhất
Một trong những bài toán kinh điển của lý thuyết tổ hợp là Bài toán cái túi. Bài toán được phát biểu như sau: Một nhà thám hiểm cần đem theo một cái túi trọng lượng không quá W. Có N đồ vật cần đem theo. Đồ vật thứ i có trọng lượng A[i], có giá trị sử dụng C[i]. Nhiệm vụ của bạn là hãy tìm cách đưa đồ vật vào túi cho nhà thám hiểm sao cho tổng giá trị sử dụng các đồ vật trong túi là lớn nhất. Giả thiết với mỗi vật dụng, ta có thể chia nhỏ chúng ra thành nhiều phần khác nhau (Fraction Knapsack).

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào hai số N, W tương ứng với số lượng đồ vật và trọng lượng túi; phần thứ 2 đưa vào 2*N số tương ứng với trọng lượng đồ vật A[i] và giá trị sử dụng C[i] của mỗi đồ vật.
T, N, W, A[i], C[i]  thỏa mãn ràng buộc: 1≤T≤100;  1≤N, W≤100; 1≤A[i], C[i]≤100.
Output:

Đưa ra kết quả mỗi test theo từng dòng, in ra 2 chữ số sau dấu phảy.
Ví dụ:

Input

2
3 50
60 10

100 20

120 30
2 50
60 10

100 20

Output

240.00
160.00
*/

#include <bits/stdc++.h>

using namespace std;

struct data {
    int w, c;
};

int n;
float w;
data a[105];

int cmp(data x, data y) {
    return ((float) x.c / x.w > (float) y.c / y.w);
}

void input() {
    scanf("%d %f", &n, &w);
    for (int i = 0; i < n; i++) scanf("%d %d", &a[i].c, &a[i].w);
}

void solve() {
    sort(a, a + n, cmp);
    float ans = 0;
    for (int i = 0; i < n; i++) {
        if (w >= a[i].w) {
            ans += a[i].c;
            w -= a[i].w;
        } else {
            ans += a[i].c * w / a[i].w;
            break;
        }
    }
    printf("%.2f\n", ans);
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
