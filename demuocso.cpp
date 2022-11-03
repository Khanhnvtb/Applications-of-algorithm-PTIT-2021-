//
// Created by Nguyen Van Khanh on 10/31/2021.
//

/*
ĐẾM ƯỚC SỐ

Bài làm tốt nhất
Cho hai số nguyên dương n và k. Hãy đếm số ước số khác nhau của tổ hợp chập k của n phần tử.

Input:

Dữ liệu vào gồm nhiều dòng, mỗi dòng ghi hai số nguyên dương n và k (0 ≤ k ≤ n ≤ 431). (chú ý: không có dòng ghi số bộ test, cần tự đọc đến hết các dòng của luồng vào).

Output:

Ghi ra kết quả trên một dòng. Dữ liệu vào đảm bảo kết quả không vượt quá 263 – 1.

Ví dụ:

Input

5 1

6 3

10 4

Output

2

6

16
*/

// s = a^n * b^m * ... * k^z có số ước là (n + 1) * (m + 1) * ... * (z + 1)

#include <bits/stdc++.h>

using namespace std;

int n, k, divide[435];
int P[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101,
           103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
           211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317,
           331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431};

void addFactorize(int i) {
    int inDex = 0;
    while (i > 1) {
        if (i % P[inDex] == 0) {
            i /= P[inDex];
            divide[P[inDex]]++;
        } else inDex++;
    }
}

void subFactorize(int i) {
    int inDex = 0;
    while (i > 1) {
        if (i % P[inDex] == 0) {
            i /= P[inDex];
            divide[P[inDex]]--;
        } else inDex++;
    }
}

void solve() {
    memset(divide, 0, sizeof(divide));
    for (int i = k + 1; i <= n; i++) addFactorize(i);
    for (int i = 2; i <= n - k; i++) subFactorize(i);
    long long ans = 1;
    for (int i = 2; i < 435; i++) {
        if (divide[i] > 0) ans *= (divide[i] + 1);
    }
    printf("%lld\n", ans);
}

void input() {
    while (cin >> n >> k) {
        solve();
    }
}

int main() {
    input();
    return 0;
}
