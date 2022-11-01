//
// Created by khanh on 10/9/2021.
//

/*
CHU TRÌNH ÂM

Bài làm tốt nhất
Cho đồ thị có trọng số G= được biểu diễn dưới dạng danh sách cạnh trọng số âm hoặc dương. Hãy viết chương trình xác định xem đồ thị có chu trình âm hay không.

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm |E|+1 dòng: dòng đầu tiên đưa vào hai số |V|, |E| tương ứng với số đỉnh và số cạnh của đồ thị; |E| dòng tiếp theo mỗi dòng đưa vào bộ ba uÎV, vÎV, w tương ứng với một cạnh cùng với trọng số canh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra 1 hoặc 0 theo từng dòng của mỗi test tương ứng với đồ thị có hoặc không có chu trình âm.
     Ví dụ:

Input:

2

3  3

1  2 -1

2  3  4

3  1 -2

3  3

1  2 -1

2  3  2

3  1 -2

Output:

0

1
*/

#include <bits/stdc++.h>

using namespace std;

int v, e, d[1005][1005];

void input() { //hàm khởi tạo
    scanf("%d %d", &v, &e);
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++) {
            if (i == j) d[i][j] = 0; //chi phí đi từ i đế chính nó bằng 0
            else d[i][j] = INT_MAX; //khởi tạo không có đường đi từ i đến j
        }
    int i, j, k;
    while (e--) {
        scanf("%d %d %d", &i, &j, &k);
        d[i][j] = k;
    }
}

int isNegativeCycle() {
    for (int k = 1; k <= v; k++) //sử dụng thuật toán Floyd tính đường đi nhỏ nhất giữa các đỉnh
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++) {
                if (d[i][k] != INT_MAX && d[k][j] != INT_MAX && d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
                if (i == j && d[i][j] < 0) return 1;
            }
    return 0;
}

void solve() { //hàm xử lý
    printf("%d\n", isNegativeCycle()); //đưa ra kết quả
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        input();
        solve();
    }
    return 0;
}
