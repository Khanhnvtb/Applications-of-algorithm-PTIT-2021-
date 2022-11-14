//
// Created by khanh on 10/14/2021.
//

/*
GIẢI MÃ XÂU KÝ TỰ

Cho xâu ký tự mã hóa str. Hãy viết chương trình giải mã xâu ký tự str. Xâu ký tự mã hóa được thực hiện theo số lần lặp các xâu con của str như sau:

Xâu đầu vào: “abbbababbbababbbab ”

Xâu mã hóa : "3[a3[b]1[ab]]"

Input:

Dòng đầu tiên đưa vào số lượng bộ test T;
Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một xâu mã hóa str được viết trên một dòng.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ràng buộc:

T, str thỏa mãn ràng buộc: 1≤T≤100; 1≤length(str)≤100.
Ví dụ:

Input

2
1[b]
3[b2[ca]]

Output

b
bcacabcacabcaca
*/

#include <bits/stdc++.h>
using namespace std;

string str;

void init() { //hàm khởi tạo
    getline (cin, str);
}

void solve() { //hàm xử lý
    int val = 0;
    string tmp = "";
    stack <int> s;
    stack <string> stk;
    string res = "";
    for (int i = 0; i < str.length (); i++) {
        if (isdigit (str[i])) val = val * 10 + (str[i] - 48); //chuyển giá trị sang kiểu int
        else if (isalpha (str[i])) { //nếu gặp chữ cái thêm nó vào xâu trung gian hiện tại
            tmp += str[i];
            if (!isalpha (str[i + 1])) { //khi hết xâu trung gian đẩy xâu đó vào ngăn xếp
                stk.push (tmp);
                tmp = ""; //khởi tạo lại giá trị của xâu trung gian
            }
        } else if (str[i] == '[') {
            if (val != 0) s.push (val); //đẩy giá trị vào ngăn xếp
            else s.push (1); //lưu ý trường hợp không có giá trị trước dấu [ thì ta lấy giá trị là 1
            val = 0; //khởi tạo lại giá trị
        } else if (str[i] == ']') { //nếu gặp dấu ] thực hiện giải mã
            int x = s.top (); //lấy giá trị của xâu hiện tại ra
            while (x--) tmp += stk.top (); //tạo ra x xâu hiện tại
            stk.pop (); //xoá xâu hiện tại khỏi ngăn xếp
            string a = "";
            if (!stk.empty ()) { //nếu ngăn xếp không rỗng lấy ra xâu ở đỉnh
                a += stk.top ();
                stk.pop ();
            }
            a += tmp; //ghép xâu đó với xâu vừa tạo thành
            stk.push (a); //đẩy xâu tạo thành vào ngăn xếp
            s.pop (); //xoá giá trị đã giải mã khỏi ngăn xếp
            tmp = ""; //khởi tạo lại xâu trung gian
            if (s.empty ()) {
                res += stk.top (); //cập nhật kết quả
                stk.pop ();
            }
        }
    }
    cout << res << endl; //đưa ra kết quả
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t --) {
        init();
        solve();
    }
    return 0;
}
