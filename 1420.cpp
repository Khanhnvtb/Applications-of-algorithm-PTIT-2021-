//
// Created by Khanh Nguyen Van on 10/15/2021.
//

/*
TỔNG LỚN NHẤT
Cho cây nhị phân có giá trị mỗi node là một số, nhiệm vụ của bạn là tìm tổng lớn nhất từ một node lá này sang một node lá khác? Ví dụ với cây dưới đây ta có tổng lớn nhất là 27.

tree

     Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được viết cách nhau một vài khoảng trống.
T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;
Output:

Đưa ra kết quả mỗi test theo từng dòng.
      Ví dụ:

Input

1
12
-15 5 L -15 6 R 5 -8 L 5 1 R -8 2 L -8 -3 R 6 3 L 6 9 R 9 0 R 0 4 L 0 -1 R -1 10 L

Output

27
*/

#include <bits/stdc++.h>
using namespace std;

int n;

struct Node { //kiểu dữ liệu cây
    int data;
    Node *left, *right;

    Node (int x) {
        data = x;
        left = right = NULL;
    }
};

void makeNode(Node* root, int b, int c) { //hàm tạo cây
    if (c == 'L') root->left = new Node (b);
    else root->right = new Node (b);
}

void findNode(Node* root, int a, int b, int c) { //hàm tìm cây con
    if (!root) return;
    if (root->data == a) makeNode (root, b, c);
    else {
        findNode (root->left, a, b, c);
        findNode (root->right, a, b, c);
    }
}

long long maxPath(Node *root, long long &res) { //hàm tính đường đi
    if (!root) return 0;
    if (!root->left && !root->right) return root->data;
    long long ls = maxPath (root->left, res); //tìm tổng từ lá của cây con bến trái đến gốc
    long long rs = maxPath (root->right, res); //tìm tổng từ lá của cây con bên phải đến gốc
    if (root->left && root->right) { //nếu có cả 2 cây con
        res = max (ls + rs + root->data, res); //cập nhật kết quả
        return max (ls, rs) + root->data; //trả về max của 1 bên lá cộng với gốc
    }
    if (!root->left) return rs + root->data; //nếu cây chỉ có cây bên phải trả về tồng của cây bên phải và gốc
    return ls + root->data; //nếu cây chỉ có cây bên trái trả về tồng của cây bên trái và gốc
}

long long maxPathSum(Node *root) { //hàm tìm tổng đường đi lớn nhất
    long long res = LONG_LONG_MIN; //khởi tạo kết quả
    maxPath (root, res); //cập nhật kết quả
    return res; //trả về kết quả
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
            if (!root) { //tạo cây
                root = new Node (a);
                makeNode (root, b, c);
            } else findNode (root, a, b, c);
        }
        printf("%lld\n", maxPathSum(root)); //đưa ra kết quả
    }
    return 0;
}
