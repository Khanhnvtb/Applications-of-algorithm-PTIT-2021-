//
// Created by khanh on 10/10/2021.
//

/*
BÀI 17. HEXGAME
HEXGAME là một trò chơi xếp hình gồm 10 miếng ghép hình lục giác đều, trên mỗi miếng ghép được điền một số nguyên, có 8 miếng được điền số  từ 1 đến 8 và có hai miếng điền số 0. Các miếng liên kết với nhau tạo thành lưới tổ ong. Ban đầu các miếng ghép ở vị trí như hình vẽ. Tại mỗi bước, chọn một miếng ghép có đúng 6 miếng ghép kề cạnh làm tâm, rồi xoay một nấc 6 miếng ghép kề cạnh đó theo chiều kim đồng hồ. Như vậy chỉ có hai cách chọn tâm, đó là chọn tâm bên trái và chọn tâm bên phải.

Yêu cầu: Cho một trạng thái của trò chơi (nhận được sau một dãy biến đổi từ trạng thái ban đầu), hãy tính số phép biến đổi ít nhất để đưa về trạng thái ban đầu.

Input:

Dòng đầu ghi số bộ test (không quá 10). Mỗi bộ test gồm:
Dòng đầu tiên chứa 3 số ở 3 miếng ghép dòng thứ nhất (thứ tự từ trái qua phải).
Dòng thứ hai chứa 4 số ở 4 miếng ghép dòng thứ hai (thứ tự từ trái qua phải).
Dòng thứ 3 chứa 3 số ở 3 miếng ghép dòng thứ ba (thứ tự từ trái qua phải).
Output: 

Với mỗi bộ test in ra một số nguyên là số phép biến đổi ít nhất để đưa được về trạng thái ban đầu.
 
Ví dụ:

Input

1

1 0 2

8 6 0 3

7 5 4

Output

5

*/

#include <bits/stdc++.h>

using namespace std;

string start, target;
map<string, int> mm, mE;
int res;

string leftS(string s) { //xoay phải tâm bên trái
    return string({s[3], s[0], s[2], s[7], s[4], s[1], s[6], s[8], s[5], s[9]});
}

string rightS(string s) { //xoay phải tâm bên phải
    return string({s[0], s[4], s[1], s[3], s[8], s[5], s[2], s[7], s[9], s[6]});
}

string leftT(string s) { //xoay trái tâm bên trái
    return string({s[1], s[5], s[2], s[0], s[4], s[8], s[6], s[3], s[7], s[9]});
}

string rightT(string s) { //xoay trái tâm bên phải
    return string({s[0], s[2], s[6], s[3], s[1], s[5], s[9], s[7], s[4], s[8]});
}

void init() { //hàm khơi tạo
    start = "";
    for (int i = 0; i < 10; i++) {
        char x;
        cin >> x;
        start += x;
    }
}

int bfsT() { //hàm bfs cuối
    queue<string> q;
    q.push(target); //thêm điểm cuối vào hàng đợi
    while (!q.empty()) {
        string tmp = q.front();
        q.pop();
        if (mm[tmp] != 0) { //trả về kết quả
            return mm[tmp] + mE[tmp];
        }
        string s1 = leftT(tmp); //xoay
        string s2 = rightT(tmp);
        if (mE[s1] == 0) { //nếu chưa đi qua
            q.push(s1); //thêm nó vào hàng đợi
            mE[s1] = mE[tmp] + 1; //cập nhật kết quả
        }
        if (mE[s2] == 0) { //nếu chưa đi qua
            q.push(s2); //thêm nó vào hàng đợi
            mE[s2] = mE[tmp] + 1; //cập nhật kết quả
        }
        if (mE[q.back()] > 19) break; //nếu không tìm được kết quả dừng lại
    }
    return -1; //trả về -1 nếu k tìm được kết quả
}

int bfsS() { //hàm bfs đầu
    queue<string> q;
    q.push(start); //thêm điểm đầu vào hàng đợi
    while (!q.empty()) {
        string tmp = q.front();
        q.pop();
        string s1 = leftS(tmp); //xoay
        string s2 = rightS(tmp);
        if (mm[s1] == 0) { //nếu chưa đi qua
            q.push(s1); //thêm nó vào hàng đợi
            mm[s1] = mm[tmp] + 1; //cập nhật kết quả
        }
        if (mm[s2] == 0) { //nếu chưa đi qua
            q.push(s2); //thêm nó vào hàng đợi
            mm[s2] = mm[tmp] + 1; //cập nhật kết quả
        }
        if (mm[target] != 0) return mm[target]; //trả về kết quả
        if (mm[q.back()] > 13) break; //nếu không tìm được kết quả dừng lại
    }
    return -1; //trả về -1 nếu k tìm được kết quả
}

void solve() {
    mm.clear();
    mE.clear();
    res = bfsS(); //cập nhật kết quả
    if (res != -1) printf("%d\n", res); //nếu đã có kết quả đưa ra kết quả
    else printf("%d\n", bfsT()); //nếu chưa có kết quả đưa ra kết quả của hàm bfs cuối
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        target = "1238004765";
        init();
        solve();
    }
    return 0;
}
