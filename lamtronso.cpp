//
// Created by Khanh Nguyen Van on 10/16/2021.
//

/*
LÀM TRÒN SỐ

Bài làm tốt nhất
Cho số nguyên dương không quá 9 chữ số. Hãy làm tròn số N theo quy tắc sau:

Nếu N>10, làm tròn đến số hàng chục gần nhất
Sau đó nếu kết quả lớn hơn 100 thì làm tròn đến số hàng trăm gần nhất
Sau đó nếu kết quả lớn hơn 1000 thì làm trong đến số hàng nghìn gần nhất
Cứ tiếp tục như vậy …
Chú ý: Giá trị 5 sẽ được làm tròn lên.

Input

Dòng đầu ghi số bộ test (không quá 100)

Mỗi bộ test ghi số N trên một dòng (N nguyên dương và không quá 9 chữ số)

Output

Với mỗi test, ghi ra kết quả làm tròn tương ứng trên một dòng.

Ví dụ

Input

7

15

14

5

99

12345678

44444445

1445

Output

20

10

5

100

10000000

50000000

2000
*/

#include <bits/stdc++.h>

using namespace std;

char s[10];

void input() {
    scanf("%s", &s);
}

void solve() {
    int len = strlen(s) - 1;
    char state = s[len];
    for (int i = len - 1; i >= 0; i--) {
        if (state >= '5') {
            state = s[i] + 1;
            if (state == 58) {
                state = '0';
                if (i == 0) printf("1");
                else s[i - 1]++;
            }
        } else state = s[i];
    }
    printf("%c", state);
    for (int i = 0; i < len; i++) printf("0");
    printf("\n");
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
