//
// Created by Khanh Nguyen Van on 10/15/2021.
//

/*
CÂY NHỊ PHÂN ĐỦ

Cho cây nhị phân, nhiệm vụ của bạn là kiểm tra xem cây nhị phân có phải là một cây đủ hay không (full binary tree)? Một cây nhị phân được gọi là cây đủ nếu tất cả các node trung gian của nó đều có hai node con.

      Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được viết cách nhau một vài khoảng trống.
T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;
Output:

Đưa ra kết quả mỗi test theo từng dòng.
     Ví dụ:

Input

2
4
1 2 L 1 3 R 2 4 L 2 5 R
3
1 2 L 1 3 R 2 4 L

Output

1
0
*/

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
