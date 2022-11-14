/*
BÀI 25. SO SÁNH XÂU CON

Cho một xâu S và Q truy vấn. Mỗi truy vấn có dạng a b c d yêu cầu bạn so sánh 2 xâu con từ vị trí aà b và cà d. In ra “YES” nếu bạn có thể sắp xếp lại các kí tự của 2 xâu con sao cho 2 xâu mới thu được giống nhau, in ra “NO” trong trường hợp ngược lại.

Input: Dòng đầu tiên là số nguyên N (1 ≤ N ≤ 50 000). 

Dòng tiếp theo là số lượng truy vấn Q (1 ≤ Q ≤ 50 000).

Q dòng tiếp theo, mỗi dòng gồm 4 số nguyên a b c d.

Output: Với mỗi truy vấn in ra đáp án tìm được trên một dòng.

Ví dụ:

Test 1

Test 2

Input:

abbbabba

2

3 5 2 4

1 2 6 7

Output:

NO
NO

Input:

acmptit

2

1 2 5 6

5 5 7 7

Output:

NO
YES

Giải thích test 1: Truy vấn 1: bba – bbb. Truy vấn 2: ab – bb
*/

#include <bits/stdc++.h>

using namespace std;

string s;
int q, a, b, c, d, cnt[50005][150];

void solve() {
    s = " " + s;
    for (int i = 1; i < s.length(); i++) {
        for(int j = 'a'; j <= 'z'; j++)
            cnt[i][j] = cnt[i - 1][j];
        cnt[i][s[i]]++;
    }
}

string result() {
    for (int i = 'a'; i <= 'z'; i++) {
        if (cnt[b][i] - cnt[a - 1][i] != cnt[d][i] - cnt[c - 1][i]) return "NO";
    }
    return "YES";
}

void input() {
    cin >> s;
    solve();
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        cout << result() << endl;
    }
}

int main() {
    input();
    return 0;
}
