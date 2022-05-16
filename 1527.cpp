//
// Created by khanh on 10/14/2021.
//

#include <bits/stdc++.h>
using namespace std;

int l, r;
vector <long> a;

int test(string s) { //hàm kiểm tra số k
    int used[6] = {0};
    for (int i = 0; i < s.length (); i++) {
        int tmp = s[i] - 48;
        if (used[tmp] == 0) used[tmp] = 1; //nếu tìm được 1 chữ số chưa sử dụng đánh dấu nó đã sử dụng
        else return 0; //nếu gặp chữ số đã sử dụng rồi trả về 0
    }
    return 1;
}

void solve(){
    queue <string> q;
    q.push ("1"); //đẩy 5 số k đầu tiên vào hàng đợi
    q.push ("2");
    q.push ("3");
    q.push ("4");
    q.push ("5");
    while (!q.empty ()) {
        string tmp = q.front ();
        q.pop ();
        if (tmp.length () > 5) break;
        int y = 0;
        for (int i = 0; i < tmp.length (); i++) y = y * 10 + (tmp[i] - 48);
        a.push_back (y); //thêm số k vào mảng a
        for (int i = 0; i <= 5; i++) {
            char x = i + 48;
            if (test (tmp + x) == 1) q.push (tmp + x); //nếu tạo ra được 1 số k thì thêm nó vào hàng đợi
        }
    }
}

void init() { //hàm khởi tạo
    cin >> l >> r;
}

void print(){
    int x = 0, y = a.size () - 1;
    while (a[x] < l && x < a.size ()) x++; //tìm chỉ mục bắt đầu
    while (a[y] > r && y > 0) y--; //tìm chỉ mục kết thúc
    cout << y - x + 1 << endl; //đưa ra kết quả
}
int main() {
    int t;
    cin >> t;
    solve ();
    while (t--) {
        init ();
        print ();
    }
    return 0;
}