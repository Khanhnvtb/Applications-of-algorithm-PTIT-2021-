//
// Created by Nguyen Van Khanh on 10/30/2021.
//

/*
Một bản tin M đã mã hóa bí mật thành các con số theo ánh xạ như sau: ‘A’->1, ‘B’->2, .., ‘Z’->26. Hãy cho biết có bao nhiêu cách khác nhau để giải mã bản tin M. Ví dụ với bản mã M=”123” nó có thể được giải mã thành ABC (1 2 3), LC (12 3), AW(1 23).

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu ký tự số M.
T, M thỏa mãn ràng buộc: 1≤T≤100;  1≤length(M)≤40.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input

2
123
2563

Output

3
2

*/

#include <bits/stdc++.h>
using namespace std;

string str;
int n, dp[45]; //mảng dp lưu số cách giải mã của xâu có độ dài i

void init() { //hàm khởi tạo
    cin >> str;
}

void solve() { //hàm xử lý
    n = str.length ();
    if (str[0] == '0') cout << "0"; //trường hợp số 0 ở đầu không thể giải mã
    else {
        dp[0] = 1, dp[1] = 1; //khởi tạo cấu hình ban đầu
        for (int i = 2; i <= n; i++) {
            dp[i] = 0;
            if (str[i - 1] > '0') dp[i] = dp[i - 1]; //trường hợp là chữ số lớn hơn 0 cách giải không đổi
            //trường hợp thuộc khoảng từ 10 đến 26 thì có thêm 1 cách giải mã
            if (str[i - 2] == '1' || str[i - 2] == '2' && str[i - 1] < '7') dp[i] += dp[i - 2];
        }
        cout << dp[n]; //đưa ra kết quả
    }
    cout << endl;
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
