//
// Created by Khanh Nguyen Van on 10/15/2021.
//

/*
BIẾN ĐỔI SANG CÂY NHỊ PHÂN TÌM KIẾM

Cho cây nhị phân, nhiệm vụ của bạn là dịch chuyển cây nhị phân thành cây nhị phân tìm kiếm. Phép dịch chuyển phải bảo toàn được cấu trúc cây nhị phân ban đầu. 

    Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được viết cách nhau một vài khoảng trống.
T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;
Output:

Đưa ra kết quả mỗi test theo từng dòng là phép duyệt Inorder của cây tìm kiếm.
     Ví dụ:

Input

2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output

1 2 3
10 20 30 40 60
*/

#include <bits/stdc++.h>

using namespace std;

int n;
set<int> s;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int b, c;
        char d;
        scanf("%d %d %c", &b, &c, &d);
        s.insert(b);
        s.insert(c);
    }
}

void solve() {
    for (int i: s) printf("%d ", i);
    printf("\n");
    s.clear();
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
