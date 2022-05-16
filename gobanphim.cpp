//
// Created by Nguyen Van Khanh on 11/7/2021.
//

#include<bits/stdc++.h>
using namespace std;

string str;

void init(){
    cin >> str;
}

void solve(){ //hàm xử lý
    deque <char> q;
    stack <char> s;
    string res = ""; //khởi tạo kết quả
    for (long long i = 0; i < str.length(); i ++) {
        if (str[i] == '-' && ! q.empty()) q.pop_back(); //loại bỏ phần tử ở trước con trỏ
        else if (! q.empty() > 0 && str[i] == '<') { //nếu gặp ký tự đi lùi
            s.push(q.back()); //thêm phần tử bị lùi vào ngăn xếp
            q.pop_back(); //xoá phần tử đó khỏi hàng đợi
        } else if (! s.empty() && str[i] == '>') { //nếu gặp ký tự đi tiến
            q.push_back(s.top()); //thêm phần tử ở ngăn xếp vào hàng đợi
            s.pop();
        } else if (str[i] != '-' && str[i] != '<' && str[i] != '>') q.push_back(str[i]); //gặp ký tự thêm vào hàng đợi
    }
    while (! q.empty()) { //cập nhật kết quả
        res += q.front();
        q.pop_front();
    }
    while (! s.empty()) { //cập nhật kết quả
        res += s.top();
        s.pop();
    }
    cout << res; //đưa ra kết quả
}

int main() {
    init ();
    solve ();
    return 0;
}