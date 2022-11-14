//
// Created by Nguyen Van Khanh on 10/22/2021.
//

/*
BÀI 13. KHOẢNG CÁCH XÂU KÝ TỰ
Cho tập n xâu ký tự S và hai xâu s, t Î S. Ta giả thiết các xâu ký tự S[i] Î S có độ dài bằng nhau.  Hãy tìm khoảng cách đường đi ngắn nhất từ s đến t. Biết từ một xâu ký tự bất kỳ ta chỉ được phép dịch chuyển đến xâu khác với nó duy nhất 1 ký tự. Ví dụ ta có tập các từ S = { POON, TOON, PLEE, SAME, POIE, PLEA, PLIE, POIN }, s = TOON, t = PLEA ta có độ dài đường đi ngắn nhất là 7 tương ứng với các phép dịch chuyển : TOON -> POON –> POIN –> POIE –> PLIE –> PLEE –> PLEA.

Input:

Dòng đầu tiên đưa vào số lượng test T (T≤100).
Mỗi test được tổ chức thành 2 dòng. Dòng thứ nhất ghi lại n là số từ trong S và hai từ s, t.  Dòng thứ 2 đưa vào n xâu xâu ký tự của S; các xâu ký tự được viết cách nhau một vài khoảng trống, có độ dài không vượt quá 10 kí tự.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input

1

8 TOON  PLEA

POON TOON PLEE SAME  POIE  PLEA  PLIE  POIN

Output

7
*/

#include <bits/stdc++.h>
using namespace std;

int n;
string start, target;
set <string> s;
set <string> ::iterator it;

void init() { //hàm khởi tạo
    cin >> n;
    s.clear();
    cin.ignore();
    cin >> start >> target;
    for (int i = 0; i < n; i ++) {
        cin.ignore();
        string str;
        cin >> str;
        s.insert(str);
    }
}

int bfs() { //hàm bfs
    if (start == target) return 0; //nếu bắt đầu bằng kết thúc thì trả về 0
    map <string, vector <string>> umap; //map dùng để lưu các chuỗi kề nhau (khác nhau 1 ký tự)
    for (it = s.begin(); it != s.end(); it ++) {
        string word = *it;
        for (int j = 0; j < word.size(); j ++) {
            string str = word.substr(0, j) + "*" + word.substr(j + 1); //xoá đi 1 ký tự đặt nó bằng *
            umap[str].push_back(word); //tạo ma trận kề
        }
    }
    queue <pair <string, int>> q;
    map <string, int> vs; //map dùng để đánh dấu các chuỗi đã được duyệt qua
    q.push({start, 1}); //thêm chuỗi bắt đầu vào hàng đợi
    vs[start] = 1;
    while (! q.empty()) {
        string word = q.front().first;
        int dist = q.front().second;
        q.pop();
        if (word == target) return dist; //nếu tìm được xâu cuối cùng trả về kết quả
        for (int i = 0; i < word.size(); i ++) {
            string str = word.substr(0, i) + "*" + word.substr(i + 1);
            vector <string> v = umap[str];
            for (int j = 0; j < v.size(); j ++) { //tìm tất cả những từ mà word có thể duyệt tới
                if (vs[v[j]] == 0) { //nếu tìm thấy
                    vs[v[j]] = 1; //đánh dấu đã thăm
                    q.push({v[j], dist + 1}); //thêm từ đó vào hàng đợi
                }
            }
        }
    }
    return 0;
}

void solve() { //hàm xử lý
    cout << bfs () << endl; //đưa ra kết quả
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init ();
        solve ();
    }
    return 0;
}
