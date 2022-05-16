//
// Created by khanh on 10/12/2021.
//

#include <bits/stdc++.h>

using namespace std;

string str;
int n, l, r, res;

void input() { //hàm khởi tạo
    cin >> str;
    n = str.length();
}

void solve() { //hàm xử lý
    res = 1; //xâu đối xứng ngắn nhất luôn là 1
    for (int i = 0; i < n; i++) { //chọn từng chỉ mục là vị trí giữa
        l = i, r = i;
        while (l > 0 && r < n - 1) {
            l--;
            r++;
            if (str[l] != str[r]) { //nếu kết thúc phần đối xứng dừng lại
                l++;
                r--;
                break;
            }
        }
        res = max(res, r - l + 1); //cập nhật kết quả
    }
    for (int i = 0; i < n - 1; i++) { //chọn từng chỉ mục là vị trí giữa
        if (str[i] == str[i + 1]) {
            l = i, r = i + 1;
            while (l > 0 && r < n - 1) {
                l--;
                r++;
                if (str[l] != str[r]) { //nếu kết thúc phần đối xứng dừng lại
                    l++;
                    r--;
                    break;
                }
            }
            res = max(res, r - l + 1);
        }
    }
    printf("%d\n", res);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        input();
        solve();
    }
    return 0;
}