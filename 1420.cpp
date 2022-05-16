
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
    cin >> t;
    while (t--) {
        cin >> n;
        int a, b;
        char c;
        Node *root = NULL;
        while (n--) {
            cin >> a >> b >> c;
            if (!root) { //tạo cây
                root = new Node (a);
                makeNode (root, b, c);
            } else findNode (root, a, b, c);
        }
        cout << maxPathSum (root) << endl; //đưa ra kết quả
    }
    return 0;
}