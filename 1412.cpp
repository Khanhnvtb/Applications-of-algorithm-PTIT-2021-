//
// Created by Nguyen Van Khanh on 10/29/2021.
//

/*
DUYỆT CÂY 3

Cho cây nhị phân, nhiệm vụ của bạn là duyệt cây theo Level-order. Phép duyệt level-order trên cây là phép thăm node theo từng mức của cây. Ví dụ với cây dưới đây sẽ cho ta kết quả của phép duyệt level-order: 20  8  22  4  12  10  14.

 

https://media.geeksforgeeks.org/wp-content/cdn-uploads/BinaryTree4.png

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được viết cách nhau một vài khoảng trống.
T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;
Output:

Đưa ra kết quả phép duyệt level-order theo từng dòng.
     Ví dụ:

Input

2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output

1 3 2

10 0 30 40 60
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

void findNode(Node *node, int a, int b, char c) {
    if (!node) return;
    if (node->data == a) makeNode(node, b, c);
    else {
        findNode(node->left, a, b, c);
        findNode(node->right, a, b, c);
    }
}

void LevelOrder(Node *node) {
    if (!node) return;
    queue<Node *> q;
    stack<int> s;
    q.push(node);
    while (!q.empty()) {
        Node *tmp = q.front();
        printf("%d ", tmp->data);
        q.pop();
        if (tmp->left) q.push(tmp->left);
        if (tmp->right) q.push(tmp->right);
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
        LevelOrder(root);
    }
    return 0;
}
