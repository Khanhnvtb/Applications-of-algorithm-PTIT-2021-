//
// Created by Khanh Nguyen Van on 10/17/2021.
//

//
// Created by Khanh Nguyen Van on 10/17/2021.
//

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