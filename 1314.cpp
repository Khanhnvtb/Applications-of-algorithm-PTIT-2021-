//
// Created by khanh on 10/11/2021.
//

/*
PHÂN TÍCH SỐ
Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả các cách phân tích số tự nhiên N thành tổng các số tự nhiên nhỏ hơn hoặc bằng N. Phép hoán vị của một cách được xem là giống nhau. Ví dụ với N = 5 ta có kết quả là: (5), (4, 1), (3, 2), (3, 1, 1), (2, 2, 1), (2, 1, 1, 1), (1, 1, 1, 1, 1) .

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng.
T, n thỏa mãn ràng buộc: 1≤T, N≤10.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
            Ví dụ:

Input

2

4

5

Output

(4) (3 1) (2 2) (2 1 1) (1 1 1 1)

(5) (4 1) (3 2) (3 1 1) (2 2 1) (2 1 1 1) (1 1 1 1 1)
*/

#include<bits/stdc++.h>

using namespace std;

int n, a[10];

void input() { //hàm khởi tạo
    scanf("%d", &n);
}

void print(int k) { //hàm in
    printf("(");
    for (int i = 0; i < k - 1; i++) printf("%d ", a[i]);
    printf("%d) ", a[k - 1]);
}

void solve() { //hàm xử lý
    a[0] = n; //khởi tạo cấu hình đầu
    int k = 1;
    print(k); //đưa ra cấu hình đầu
    int sum = 0; //khởi tạo biến tính tổng còn lại
    for (int i = k - 1; i >= 0; i--) {
        if (a[i] != 1) { //nếu tìm được số khác 1
            a[i]--; //giảm số đó đi 1
            sum++; //cập nhật tổng còn lại
            int x = sum / a[i]; //kiểm tra xem còn có thể thêm bao nhiêu số a[i] đằng sau nó
            for (int j = i + 1; j <= i + x; j++) a[j] = a[i]; //thêm vào x số a[i]
            k = i + x + 1; //cập nhật độ rộng của cấu hình
            if (sum % a[i] != 0) { //kiểm tra xem tổng đã bằng n chưa
                a[k] = sum % a[i]; //nếu chưa bằng thì bù thêm vào để bằng n
                k++; //cập nhật độ rộng của cấu hình
            }
            print(k); //đưa ra cấu hình tiếp theo
            sum = 0; //trả lại tổng còn lại và i để sinh cấu hình kế tiếp
            i = k;
        } else sum++; //nếu tìm thấy số 1 thì tăng tổng còn lại
    }
    printf("\n");
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        input();
        solve();
    }
    return 0;
}
