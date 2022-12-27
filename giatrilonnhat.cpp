//
// Created by Khanh Nguyen Van on 10/17/2021.
//

/*
Cho dãy số nguyên A[] có N phần tử.

Gọi f(i,j) = |ai| + |ai+1| + … + |aj|
Goij g(i,j) = ai + ai+1 + … + aj
Với tất cả các cặp 1 ≤ i ≤ j ≤ N.

Hãy tính giá trị lớn nhất của f(i,j) + g(i,j).

Input

Dòng đầu ghi số N (1 ≤ N ≤ 50000)

Dòng thứ 2 ghi N số nguyên của dãy A[]

Output

Ghi ra giá trị lớn nhất của f(i,j) + g(i,j)

Ví dụ

Input

5

-3 5 -10 8 -2

Output

26
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    long long res = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > 0) res += a[i];
    }
    printf("%lld", res * 2);
    return 0;
}
