//
// Created by Nguyen Van Khanh on 11/2/2021.
//

#include <bits/stdc++.h>
using namespace std;

int n, a[1005];

void init() { //hàm khởi tạo
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}

void printPreorder(int start, int end) { //hàm in theo preorder
    if (start > end) return; //nếu đã in hết cây hiện tại thì dừng lại
    int size = end - start + 1; //tìm độ động của mảng cây hiện tại
    int preIndex = start + size / 2; //tìm phần tử ở giữa của cây
    if (size % 2 == 0) preIndex--;
    cout << a[preIndex] << " ";
    printPreorder (start, preIndex - 1); //in cây con bên trái
    printPreorder (preIndex + 1, end); //in cây con bên phải
}

void solve() { //hàm xử lý
    sort (a, a + n); //đưa về mảng duyệt inorder
    printPreorder (0, n - 1); //đưa ra kết quả
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init ();
        solve ();
    }
    return 0;
}