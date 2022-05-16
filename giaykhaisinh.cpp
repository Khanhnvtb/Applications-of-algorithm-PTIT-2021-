//
// Created by Nguyen Van Khanh on 11/7/2021.
//

#include <bits/stdc++.h>
using namespace std;

struct person { //kiểu dữ liệu người
    string father, son; //gồm tên cha và tên con
    int ageF, ageS; //tuổi của cha và tuổi của con
};

int x;
person a[102];

int cmp(person i, person j) { //hàm so sánh thứ tự của 2 người
    if (i.ageS < j.ageS) return 0;
    else if (i.ageS == j.ageS) if (i.son > j.son) return 0;
    return 1;
}

void init() { //hàm khởi tạo
    cin >> x;
    for (int i = 0; i < x; i++) cin >> a[i].father >> a[i].son >> a[i].ageF;
}

void solve(int t) {
    queue <pair <string, int> > q;
    q.push ({"Ted", 100}); //thêm cụ Ted và tuổi của cụ vào hàng đợi
    while (!q.empty ()) {
        string tmp = q.front ().first; //lấy ra người đầu tiên trong hàng đợi
        int age = q.front ().second; //lấy ra tuổi của người đó
        q.pop ();
        for (int i = 0; i < x; i++) { //tìm tất cả con của người đó
            if (a[i].father == tmp) {
                a[i].ageS = age - a[i].ageF; //tính tuổi con của người đó
                q.push ({a[i].son, a[i].ageS}); //thêm người con đó vào hàng đợi
            }
        }
    }
    sort (a, a + x, cmp); //sắp xếp lại theo thứ tự
    cout << "DATASET " << t << endl;
    for (int i = 0; i < x; i++) cout << a[i].son << " " << a[i].ageS << endl; //đưa ra kết quả
}


int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        init ();
        solve (i);
    }
    return 0;
}