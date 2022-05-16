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

void makeNode(Node *node, int b, int c) {
    if (c == 'L') node->left = new Node(b);
    else node->right = new Node(b);
}

void findNode(Node *node, int a, int b, int c) {
    if (node == NULL) return;
    if (node->data == a) makeNode(node, b, c);
    else {
        findNode(node->left, a, b, c);
        findNode(node->right, a, b, c);
    }
}

int isSameLevel(Node *root) {
    if(!root) return 1;
    queue<pair<Node *, int> > q;
    q.push({root, 1});
    int res = INT_MAX;
    while (!q.empty()) {
        Node *tmp = q.front().first;
        int level = q.front().second;
        q.pop();
        if (!tmp->left && !tmp->right) {
            if (res == INT_MAX) res = level;
            else if (level != res) return 0;
        }
        if (tmp->left) q.push({tmp->left, level + 1});
        if (tmp->right) q.push({tmp->right, level + 1});
    }
    return 1;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        Node *root = NULL;
        int a, b;
        char c;
        scanf("%d", &n);
        while (n--) {
            scanf("%d %d %c", &a, &b, &c);
            if (!root) {
                root = new Node(a);
                makeNode(root, b, c);
            } else findNode(root, a, b, c);
        }
        printf("%d\n", isSameLevel(root));
    }
    return 0;
}