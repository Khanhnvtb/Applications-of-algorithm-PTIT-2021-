//
// Created by Khanh Nguyen Van on 10/15/2021.
//

/*
KIỂM TRA NODE LÁ
Cho cây nhị phân, nhiệm vụ của bạn là kiểm tra xem tất cả các node lá của cây có cùng một mức hay không? Ví dụ với cây dưới đây sẽ cho ta kết quả là Yes.

 

spiral_order

      Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được viết cách nhau một vài khoảng trống.
T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;
Output:

Đưa ra kết quả mỗi test theo từng dòng.
      Ví dụ:

Input

2

2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

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
