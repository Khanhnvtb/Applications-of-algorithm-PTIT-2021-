//
// Created by Khanh Nguyen Van on 10/16/2021.
//

/*
XÂY DỰNG LẠI CÂY NHỊ PHÂN TÌM KIẾM
Cho một mảng là phép duyệt level-order của cây nhị phân tìm kiếm. Nhiệm vụ của bạn là xây dựng lại cây nhị phân tìm kiếm bảo toàn được cấu trúc cây nhị phân ban đầu.

     Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm dòng: dòng đầu tiên đưa vào số N là số lượng node của cây tìm kiếm; dòng tiếp theo đưa vào phép duyệt level-order của cây tìm kiếm; các số được viết cách nhau một vài khoảng trống.
T, N, node thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤node≤104;
Output:

Đưa ra kết quả mỗi test theo từng dòng là phép duyệt Inorder của cây tìm kiếm.
      Ví dụ:

Input

2
9
7 4 12 3 6 8 1 5 10
6
1 3 4 6 7 8

Output

7 4 3 1 6 5 12 8 10
1 3 4 6 7 8
*/

#include <bits/stdc++.h>

using namespace std;

struct Node { //kiểu dữ liệu cây
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

int n, lv[1005];

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &lv[i]);
}

void printPreOrder(Node *node) {
    if (!node) return;
    printf("%d ", node->data);
    printPreOrder(node->left);
    printPreOrder(node->right);
}

Node *levelOrder(Node *node, int data) {
    if (!node) {
        node = new Node(data);
        return node;
    }
    if (data <= node->data) node->left = levelOrder(node->left, data);
    else node->right = levelOrder(node->right, data);
    return node;
}

Node *buildTree(Node *node) {
    for (int i = 0; i < n; i++) node = levelOrder(node, lv[i]);
    return node;
}

void solve() {
    Node *root = NULL;
    root = buildTree(root);
    printPreOrder(root);
    printf("\n");
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
