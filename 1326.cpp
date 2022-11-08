//
// Created by khanh on 10/10/2021.
//

/*
DÃY XÂU FIBONACI

Một dãy xâu ký tự G chỉ bao gồm các chữ cái A và B được gọi là dãy xâu Fibonacci nếu thỏa mãn tính chất:    G(1) = A; G(2) = B; G(n) = G(n-2)+G(n-1). Với phép cộng (+) là phép nối hai xâu với nhau.  Bài toán đặt ra là tìm ký tự ở vị trí thứ i (tính từ 1) của xâu Fibonacci thứ n.

Dữ liệu vào: Dòng 1 ghi số bộ test. Mỗi bộ test ghi trên một dòng 2 số nguyên N và i (1<N<93). Số i đảm bảo trong phạm vi của xâu G(N) và không quá 18 chữ số. Kết quả: Ghi ra màn hình kết quả tương ứng với từng bộ test.

Input

2

6 4

8 19

Output

A

B
*/

#include <bits/stdc++.h>

using namespace std;

long long Fibo[93];
int n;
long long k;

void createFiboNumbers() {
    Fibo[0] = 0;
    Fibo[1] = 1;
    for (int i = 2; i < 93; i++) Fibo[i] = Fibo[i - 1] + Fibo[i - 2];
}

void input() {
    scanf("%d %lld", &n, &k);
}

char find(int n, long long k) {
    if (n == 1) return 'A';
    if (n == 2) return 'B';
    if (k <= Fibo[n - 2]) return find(n - 2, k);
    else return find(n - 1, k - Fibo[n - 2]);
}

void solve() {
    printf("%c\n", find(n, k));
}

int main() {
    int t;
    scanf("%d", &t);
    createFiboNumbers();
    while (t--) {
        input();
        solve();
    }
    return 0;
}
