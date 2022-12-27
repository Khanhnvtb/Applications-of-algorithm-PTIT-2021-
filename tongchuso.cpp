//
// Created by Nguyen Van Khanh on 10/30/2021.
//

/*
Cho hai số nguyên dương A và B. Tìm số N nhỏ nhất thỏa mãn: A là tổng các chữ số của N, B là tổng bình phương các chữ số của N. Nếu không tồn tại N thỏa mãn A và B hãy đưa ra -1. Giả thiết N có không quá 100 chữ số.

Ví dụ với A = 18, B = 162 ta tìm được số nhỏ nhất N=99 vì 9+9=18 và 92 + 92 = 162. Với A = 12, B = 9 ta có kết quả  là -1.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là cặp số A, B được viết trên một dòng.
T, A, B thỏa mãn ràng buộc: 1≤T≤100;  1≤A≤100; 1≤B≤10000.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input

2
18  162
12  9

Output

99
-1
*/

#include <bits/stdc++.h>
using namespace std;

int dp[905][8105];
int a,b;

void init() {
    cin >> a >> b;
}

int minDigits(int x, int y) {
    if (x > y || x < 0 || y < 0 || x > 100 || y > 8100) return -1; //không nằm trong khoảng xác định
    if (x == 0 && y == 0) return 0;
    if (dp[x][y] != -1) return dp[x][y]; //nếu số chữ số khác -1 tức là đã có th thoả mãn
    int ans = 101;
    for (int i = 9; i >= 1; i--) {
        int k = minDigits (x - i, y - (i * i)); //tìm số chữ số nhỏ nhất sau khi chọn 1 chữ số
        if (k != -1) ans = min (ans, k + 1); //so sánh số tìm được với giá trị nhỏ nhất hiện tại để cập nhật min
    }
    return dp[x][y] = ans; //trả về số chữ số ít nhất
}

void solve() {
    memset (dp, -1, sizeof (dp));
    dp[0][0] = 0;
    int k = minDigits (a, b);
    if (k == -1 || k > 100) cout << "-1"; //nếu nằm ngoài khoảng xác định thì in -1
    else {
        while (a > 0 && b > 0) //tìm từng chữ số của kết quả
            for (int i = 1; i <= 9; i++)
                if (a >= i && b >= i * i && 1 + dp[a - i][b - i * i] == dp[a][b]) {
                    //nếu chọn chữ số i mà số giá trị của dp[a - i][b - i * i ] bằng dp[a][b] tức là kết quả chứa i
                    cout << i; //in ra chữ số hiện tại đã duyệt đến của kết quả
                    a -= i;
                    b -= i * i;
                    break; //kết thúc để tìm kiếm chữ số sau nó
                }
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
