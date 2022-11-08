//
// Created by Khanh Nguyen Van on 10/18/2021.
//

/*
SỐ FIBONACCI THỨ N

Dãy số Fibonacci được xác định bằng công thức như sau:

F[0] = 0, F[1] = 1;

F[n] = F[n-1] + F[n-2] với mọi n >= 2.

Các phần tử đầu tiên của dãy số là 0, 1, 1, 2, 3, 5, 8, ...

Nhiệm vụ của bạn là hãy xác định số Fibonaci thứ n. Do đáp số có thể rất lớn, in ra kết quả theo modulo 109+7.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 1000).

Mỗi test bắt gồm một số nguyên N (1 ≤ N ≤ 109).

Output: 

Với mỗi test, in ra đáp án trên một dòng.

Ví dụ:

Input:

3

2

6

20

Output

1

8

6765
*/

#include <bits/stdc++.h>

using namespace std;

long m = 1e9 + 7;

void multiply(long F[2][2], long M[2][2]) {
    long x = (F[0][0] % m * M[0][0] % m + F[0][1] % m * M[1][0] % m) % m;
    long y = (F[0][0] % m * M[0][1] % m + F[0][1] % m * M[1][1] % m) % m;
    long z = (F[1][0] % m * M[0][0] % m + F[1][1] % m * M[1][0] % m) % m;
    long w = (F[1][0] % m * M[0][1] % m + F[1][1] % m * M[1][1] % m) % m;
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(long F[2][2], long n) {
    if (n == 0 || n == 1) return;
    long M[2][2] = {{1, 1},
                    {1, 0}};
    power(F, n / 2);
    multiply(F, F);
    if (n % 2 != 0) multiply(F, M);
}

long fib(long n) {
    long F[2][2] = {{1, 1},
                    {1, 0}};
    if (n == 0) return 0;
    power(F, n - 1);
    return F[0][0] % m;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long n;
        scanf("%ld", &n);
        printf("%ld\n", fib(n));
    }
    return 0;
}
