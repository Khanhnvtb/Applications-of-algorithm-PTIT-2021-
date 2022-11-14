//
// Created by khanh on 10/13/2021.
//

/*
BÀI 15. QUAY HÌNH VUÔNG
Có một chiếc bảng hình chữ nhật với 6 miếng ghép, trên mỗi miếng ghép được điền một số nguyên trong khoảng từ 1 đến 6. Tại mỗi bước, chọn một hình vuông (bên trái hoặc bên phải), rồi quay theo chiều kim đồng hồ.

Yêu cầu: Cho một trạng thái của bảng, hãy tính số phép biến đổi ít nhất để đưa bảng đến trạng thái đích.

Input:

Dòng đầu ghi số bộ test (không quá 10). Mỗi bộ test gồm hai dòng:
Dòng đầu tiên chứa 6 số là trạng thái bảng ban đầu (thứ tự từ trái qua phải, dòng 1 tới dòng 2).
Dòng thứ hai chứa 6 số là trạng thái bảng đích (thứ tự từ trái qua phải, dòng 1 tới dòng 2).
Output: 

Với mỗi test, in ra một số nguyên là đáp số của bài toán.
Ví dụ:

Input

1

1 2 3 4 5 6

4 1 2 6 5 3

Output

2
*/

#include <bits/stdc++.h>

using namespace std;

string s1, s2;

void input() {
    s1 = "", s2 = "";
    for (int i = 0; i < 6; i++) {
        char c;
        cin >> c;
        s1 += c;
    }
    for (int i = 0; i < 6; i++) {
        char c;
        cin >> c;
        s2 += c;
    }
}

int bfs() {
    if (s1 == s2) return 0;
    queue<pair<string, int> > q;
    q.push({s1, 0});
    while (1) {
        s1 = q.front().first;
        int cnt = q.front().second + 1;
        q.pop();
        string tmp = "";
        tmp += s1[3];
        tmp += s1[0];
        tmp += s1[2];
        tmp += s1[4];
        tmp += s1[1];
        tmp += s1[5];
        if (tmp == s2) return cnt;
        else q.push({tmp, cnt});
        tmp = "";
        tmp += s1[0];
        tmp += s1[4];
        tmp += s1[1];
        tmp += s1[3];
        tmp += s1[5];
        tmp += s1[2];
        if (tmp == s2) return cnt;
        else q.push({tmp, cnt});
    }
}

void solve() {
    printf("%d\n", bfs());
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
