//
// Created by Khanh Nguyen Van on 10/15/2021.
//

/*
CÂY NHỊ PHÂN BẰNG NHAU

Cho hai cây nhị phân, nhiệm vụ của bạn là kiểm tra xem cây nhị phân có giống nhau hay không?

    Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái của mỗi cây; u, v, x được viết cách nhau một vài khoảng trống.
T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;
Output:

Đưa ra kết quả mỗi test theo từng dòng.
      Ví dụ:

Input

2
2
1 2 L 1 3 R
2
1 2 L 1 3 R
2
1 2 L 1 3 R
2
1 3 L 1 2 R

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

void findNode(Node *node, int a, int b, char c) {
    if (!node) return;
    if (node->data == a) makeNode(node, b, c);
    else {
        findNode(node->left, a, b, c);
        findNode(node->right, a, b, c);
    }
}

int indenticalTree(Node *T1, Node *T2) {
    if (!T1 && !T2) return 1;
    if (T1 && T2)
        return (T1->data == T2->data && indenticalTree(T1->left, T2->left) && indenticalTree(T1->right, T2->right));
    return 0;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int a, b;
        char c;
        Node *rootA = NULL;
        while (n--) {
            scanf("%d %d %c", &a, &b, &c);
            if (!rootA) {
                rootA = new Node(a);
                makeNode(rootA, b, c);
            } else findNode(rootA, a, b, c);
        }
        scanf("%d", &n);
        Node *rootB = NULL;
        while (n--) {
            scanf("%d %d %c", &a, &b, &c);
            if (!rootB) {
                rootB = new Node(a);
                makeNode(rootB, b, c);
            } else findNode(rootB, a, b, c);
        }
        printf("%d\n", indenticalTree(rootA, rootB));
    }
    return 0;
}
