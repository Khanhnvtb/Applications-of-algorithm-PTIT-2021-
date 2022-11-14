//
// Created by khanh on 10/14/2021.
//

/*
BÀI 19. BỘI SỐ LỚN NHẤT CỦA 3
Cho dãy số A[] có N phần tử là các chữ số từ 0 đến 9. Nhiệm vụ của bạn là hãy chọn lấy một tổ hợp các phần tử và sắp xếp chúng sao cho thu được số lớn nhất chia hết cho 3.

Nếu không tìm được số nào, in ra -1.

Input:

Dòng đầu tiên là số lượng bộ test T (1 <= N <= 50).

Mỗi test bắt đầu bởi số nguyên N (1 <= N <= 100 000).

Dòng tiếp theo gồm N số nguyên A[i] (0 <= A[i] <= 9).

Output: 

Với mỗi test, in ra đáp án tìm được trên một dòng.

Test ví dụ:

Input

3

3

8 1 9

5

8 1 7 6 0

Output

2

5 2

 

981

8760

-1
*/

#include <bits/stdc++.h>
using namespace std;

int n, sum, check, a[100005];

void init() {
    cin >> n;
    sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i]; //tỉnh tổng các chữ số
    }
}

void solve() {
    sort (a, a + n);
    if (sum % 3 == 0) {
        if (a[n - 1] == 0) cout << "0" << endl; //nếu mảng toàn số 0 đưa ra 0
        else for (int i = n - 1; i >= 0; i--) cout << a[i]; //nếu không đưa ra số theo thứ tự giảm dần của chữ số
    } else {
        queue <int> div1; //hàng đợi chưa các số chia 3 dư 1
        queue <int> div2; //hàng đợi chưa các số chia 3 dư 2
        for (int i = 0; i < n; i++) {
            if (div1.size () < 2 && a[i] % 3 == 1) { //thêm vào số chua cho 3 dư 1
                div1.push (a[i]);
                a[i] = -1; //đánh dấu loại bỏ phần tử đó
            } else if (div2.size () < 2 && a[i] % 3 == 2) { //thêm vào số chua cho 3 dư 2
                div2.push (a[i]);
                a[i] = -1; //đánh dấu loại bỏ phần tử đó
            } else if (div1.size () == 2 && div2.size () == 2) break; //nếu tìm đủ 2 số thì dừng lại
        }
        priority_queue <int, vector <int>, less <int> > q;
        for (int i = 0; i < n; i++)
            if (a[i] != -1) q.push (a[i]); //thêm các chữ số còn lại vào hàng đợi
        if (sum % 3 == 1) { //nếu tổng chia cho 3 dư 1
            if (div1.empty () && div2.size () != 2) cout << "-1"; //nếu không thể tạo đưa ra -1 ((1-4)%3=0 && (1-1)%3=0)
            else {
                if (!div1.empty ()) { //nếu có số chia 3 dư 1
                    div1.pop (); //loại bỏ số nhỏ nhất
                    q.push (div1.front ()); //thêm số còn lại nếu có vào hàng đợi
                    while (!div2.empty ()) { //thêm các số còn lại của vào hàng đợi
                        q.push (div2.front ());
                        div2.pop ();
                    }
                }
            }
        } else if (sum % 3 == 2) { //nếu tổng chia 3 dư 2
            if (div1.size () != 2 && div2.empty ()) cout << "-1"; //không thể tạo đưa ra -1 ((2-2)%3==0 && (2-1-1)%3=0)
            else if (!div2.empty ()) { //nếu có số chia 3 dư 2
                div2.pop (); //loại bỏ số nhỏ nhất
                q.push (div2.front ()); //thêm số còn lại nếu có vào hàng đợi
                while (!div1.empty ()) { //thêm các số còn lại của vào hàng đợi
                    q.push (div1.front ());
                    div1.pop ();
                }
            }
        }
        if (q.empty ()) cout << "-1"; //nếu không thể tạo đưa ra -1
        else //đưa ra kết quả
            while (!q.empty ()) {
                cout << q.top ();
                q.pop ();
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
