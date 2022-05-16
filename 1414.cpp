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

void spiralOrder(Node *node) {
    if (!node) return;
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(node);
    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            Node *tmp = s1.top();
            s1.pop();
            printf("%d ", tmp->data);
            if (tmp->right) s2.push(tmp->right);
            if (tmp->left) s2.push(tmp->left);
        }
        while (!s2.empty()) {
            Node *tmp = s2.top();
            s2.pop();
            printf("%d ", tmp->data);
            if (tmp->left) s1.push(tmp->left);
            if (tmp->right) s1.push(tmp->right);
        }
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
        spiralOrder(root);
    }
    return 0;
}