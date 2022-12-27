//
// Created by Khanh Nguyen Van on 10/16/2021.
//

/*
Trên trục Ox tính từ vị trí 0, người ta muốn xếp nhiều nhất các đoạn thẳng sao cho không đoạn nào chồng lấn lên nhau. Đoạn thẳng thứ i có vị trí bắt đầu là X1[i] và kết thúc tại X2[i], với X1[i] <= X2[i].

Hãy tính số đoạn thẳng nhiều nhất có thể được lựa chọn để đưa lên trục Ox và không có đoạn nào chồng lấn lên nhau.

Input

Dòng đầu tiên ghi số bộ test, không quá 10.

Với mỗi bộ test: dòng đầu ghi số N là số đoạn thẳng (không quá 105)

Tiếp theo là N dòng, mỗi dòng có 2 số nguyên mô tả đoạn thẳng. Các giá trị tọa độ đều là các số nguyên không âm và không quá 106.

Output

Với mỗi test, viết trên 1 dòng số lượng đoạn thẳng nhiều nhất có thể được lựa chọn thỏa mãn điều kiện đề bài.

Ví dụ

Input

1

10

39 55

37 74

0 1

19 25

65 76

51 52

19 21

5 94

46 65

32 40

Output

5
*/

#include <bits/stdc++.h>

using namespace std;

struct straightLine {
    int start, end;
};

int n;
straightLine a[100005];

int cmp(straightLine x, straightLine y) {
    if (x.end < y.end) return 1;
    if (x.end == y.end && x.start < y.start) return 1;
    return 0;
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d %d", &a[i].start, &a[i].end);
}

void solve() {
    sort(a, a + n, cmp);
    int ans = 1, prev = a[0].end;
    for (int i = 1; i < n; i++) {
        if (a[i].start >= prev) {
            ans++;
            prev = a[i].end;
        }
    }
    printf("%d\n", ans);
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
