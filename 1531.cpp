//
// Created by Khanh Nguyen Van on 10/17/2021.
//

/*
BÀI 18. TÍNH TỔNG

Cho một xâu s. Với mỗi một xâu con X liên tiếp của s có độ dài bằng K, giá trị đặc biệt của nó được tính bằng giá trị của X trong hệ cơ số B modulo M.

Nhiệm vụ của bạn là tính tổng giá trị đặc biệt của tất cả các xâu con của s có độ dài bằng K.

Input:

Dòng đầu tiên gồm xâu S có độ dài không quá 300 000 gồm các kí tự từ 0 – 9.

Dòng tiếp theo là số nguyên K, B và M (1 <= K <= |s|, 2 <= B <= 10, 1 <= M <= 1000).

Output: 

In ra đáp án tìm được.

Test ví dụ:

Test 1

Test 2

Input:

12212

3 3 5

Output:

5

Input:

111101

4 2 15

Output:

27
*/


#include <bits/stdc++.h>

using namespace std;

string s;
int k, b, m;

int power(int x, int y) {
    if (y == 0) return 1;
    if (y == 1) return x;
    int tmp = power(x, y / 2);
    if (y % 2 == 0) return tmp * tmp % m;
    else return tmp * tmp * x % m;
}

void input() {
    cin >> s;
    scanf("%d %d %d", &k, &b, &m);
}

void solve() {
    k -= 1;
    int tmp = 0;
    for (int i = 0; i < k + 1; i++) {
        int dig = s[i] - '0';
        tmp += dig * power(b, k - i);
    }
    tmp %= m;
    int res = tmp;
    int x = power(b, k);
    for (int i = k + 1; i < s.length(); i++) {
        tmp += (m - ((s[i - k - 1] - '0') * x % m));
        tmp *= b;
        tmp += s[i] - '0';
        tmp %= m;
        res += tmp;
    }
    printf("%d", res);
}

int main() {
    input();
    solve();
    return 0;
}
