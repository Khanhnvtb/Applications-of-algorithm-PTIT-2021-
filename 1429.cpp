//
// Created by Nguyen Van Khanh on 11/2/2021.
//

/*
CÂY NHỊ PHÂN TÌM KIẾM CÂN BẰNG 2
Hãy xây dựng một cây nhị phân tìm kiếm cân bằng từ dãy số A[] =(a0, a1, .., an-1}. Đưa ra phép duyệt theo thứ tự trước (preorder) của cây tìm kiếm cân bằng.  Ví dụ với dãy A[]={40, 28, 45, 38, 33, 15, 25, 20, 23, 35, 30} ta sẽ có phép duyệt theo thứ tự trước của cây nhị phân tìm kiếm cân bằng với node gốc là 33 : 33, 25, 20, 15, 23, 28, 30, 40, 38, 35, 45.

     Input:

Dòng đầu tiên đưa vào số lượng bộ test T (T≤100).
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất là số tự nhiên N (N≤106). Dòng tiếp theo là N số của mảng A[].
     Output:

Đưa ra kết quả mỗi test theo từng dòng.
     Ví dụ:

Input

2

11

40  28  45 38  33  15  25  20  23  35  30

10

1  2  3  4  5  6  7  8  9  10

Output

30 23 15 20 25 28 38 33 35 40 45

5 2 1 3 4 8 6 7 9 10
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[1005];

void init() { //hàm khởi tạo
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}

void printPreorder(int start, int end) { //hàm in theo preorder
    if (start > end) return; //nếu đã in hết cây hiện tại thì dừng lại
    int size = end - start + 1; //tìm độ động của mảng cây hiện tại
    int preIndex = start + size / 2; //tìm phần tử ở giữa của cây
    if (size % 2 == 0) preIndex--;
    printf("%d ", a[preIndex]);
    printPreorder(start, preIndex - 1); //in cây con bên trái
    printPreorder(preIndex + 1, end); //in cây con bên phải
}

void solve() { //hàm xử lý
    sort(a, a + n); //đưa về mảng duyệt inorder
    printPreorder(0, n - 1); //đưa ra kết quả
    cout << endl;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        init();
        solve();
    }
    return 0;
}
