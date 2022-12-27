//
// Created by Nguyen Van Khanh on 10/31/2021.
//
/*
Một robot xuất phát từ vị trí (0,0) mặt quay về hướng Bắc. Mỗi lần chỉ có một trong 4 lệnh chuyển động là G, L, R, B tương ứng là tiến về phía trước, tiến sang trái, tiến sang phải, lùi về phía sau một đơn vị.

Cho dãy lệnh chuyển động. Hãy tính xem vị trí cuối cùng của robot là vị trí nào?

Input

Dòng đầu tiên ghi n (n≤100) là số lệnh robot cần thực hiện.
Dòng thứ hai là dãy n ký tự mô tả dãy lệnh robot thực hiện
Output

Ghi ra hai số nguyên là tọa độ (x,y) của vị trí cuối cùng robot

Ví dụ

Input

5

GLLRB

Output

-1 0

Input

2

RG

Output

2 0
*/

#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
};

int n;
string s;
int a[4][4] = {{0, 1, 2, 3},
               {1, 2, 3, 0},
               {2, 3, 0, 1},
               {3, 0, 1, 2}};

void input() {
    scanf("%d", &n);
    cin >> s;
}

int change(char c) {
    if (c == 'G') return 0;
    else if (c == 'L') return 1;
    else if (c == 'R') return 3;
    return 2;
}

Point find(Point res, int pre) {
    if (pre == 0) return {res.x, res.y + 1};
    else if (pre == 1) return {res.x - 1, res.y};
    else if (pre == 2) return {res.x, res.y - 1};
    return {res.x + 1, res.y};
}

void solve() {
    Point res = {0, 0};
    int pre = 0;
    for (int i = 0; i < n; i++) {
        pre = a[pre][change(s[i])];
        res = find(res, pre);
    }
    printf("%d %d", res.x, res.y);
}

int main() {
    input();
    solve();
    return 0;
}
