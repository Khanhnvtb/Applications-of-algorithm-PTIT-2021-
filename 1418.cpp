//
// Created by Khanh Nguyen Van on 10/15/2021.
//

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

int n;

void makeNode(Node *node, int b, char c) {
    if (c == 'L') node->left = new Node(b);
    else node->right = new Node(b);
}

void findNode(Node *node, int a, int b, int c) {
    if (!node) return;
    if (node->data == a) makeNode(node, b, c);
    else {
        findNode(node->left, a, b, c);
        findNode(node->right, a, b, c);
    }
}

int isFullBinaryTree(Node *node) {
    if (!node) return 1;
    queue<Node *> q;
    q.push(node);
    while (!q.empty()) {
        Node *tmp = q.front();
        q.pop();
        if (tmp->left && !tmp->right) return 0;
        if (tmp->right && !tmp->left) return 0;
        if (tmp->left && tmp->right) {
            q.push(tmp->left);
            q.push(tmp->right);
        }
    }
    return 1;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int a, b;
        char c;
        Node *root = NULL;
        while (n--) {
            scanf("%d %d %c", &a, &b, &c);
            if (!root) {
                root = new Node(a);
                makeNode(root, b, c);
            } else findNode(root, a, b, c);
        }
        cout << isFullBinaryTree(root) << endl;
    }
}