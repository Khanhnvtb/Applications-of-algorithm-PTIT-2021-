//
// Created by Khanh Nguyen Van on 10/16/2021.
//

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