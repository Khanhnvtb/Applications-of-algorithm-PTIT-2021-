//
// Created by Nguyen Van Khanh on 10/29/2021.
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

void findNode(Node *node, int a, int b, char c) {
    if (!node) return;
    if (node->data == a) makeNode(node, b, c);
    else {
        findNode(node->left, a, b, c);
        findNode(node->right, a, b, c);
    }
}

void reveseLevelOrder(Node *node) {
    if (!node) return;
    queue<Node *> q;
    stack<int> s;
    q.push(node);
    while (!q.empty()) {
        Node *tmp = q.front();
        s.push(tmp->data);
        q.pop();
        if (tmp->right) q.push(tmp->right);
        if (tmp->left) q.push(tmp->left);
    }
    while (!s.empty()) {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        Node *root = NULL;
        int a, b;
        char c;
        while (n--) {
            scanf("%d %d %c", &a, &b, &c);
            if (!root) {
                root = new Node(a);
                makeNode(root, b, c);
            } else findNode(root, a, b, c);
        }
        reveseLevelOrder(root);
    }
    return 0;
}