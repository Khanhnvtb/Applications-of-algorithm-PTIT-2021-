//
// Created by khanh on 10/12/2021.
//

/*Một chiếc cầu thang có N bậc. Mỗi bước, bạn được phép bước lên trên tối đa K bước. Hỏi có tất cả bao nhiêu cách bước
để đi hết cầu thang? (Tổng số bước đúng bằng N).
Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
Mỗi test gồm hai số nguyên dương N và K(1 ≤ N ≤ 100000, 1 ≤ K ≤ 100).
Output:
Với mỗi test, in ra đáp án tìm được trên một dòng theo modulo 10^9+7.
Input                 Output
2
2 2                   2
4 2                   5
*/

#include <bits/stdc++.h>

using namespace std;

long n, k, m = 1e9 + 7, a[100005];

void init() { //hàm khởi tạo
    scanf("%d %d", &n, &k);
}

void solve() { //hàm xử lý
    a[0] = 1, a[1] = 1; //khởi tạo giá trị ban đầu
    for (int i = 2; i <= n; i++) {
        a[i] = 0; //gán số cách bước bằng 0
        for (int j = 1; j <= k; j++) { //tìm các cách bước đến bậc trước nó
            if (j <= i) {
                a[i] += a[i - j] % m; //cập nhật số cách bước
            }
        }
    }
    printf("%ld\n", a[n] % m); //đưa ra kết quả
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        solve();
    }
    return 0;
}