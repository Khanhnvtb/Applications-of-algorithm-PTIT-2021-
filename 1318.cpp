//
// Created by khanh on 10/10/2021.
//

/*
DI CHUYỂN TRONG MÊ CUNG 2

Cho một mê cung bao gồm các khối được biểu diễn như một ma trận nhị phân A[N][N]. Một con chuột đi từ ô đầu tiên góc trái (A[0][0]) đến ô cuối cùng góc phải (A[N-1][N-1]) theo nguyên tắc:

Down (D): Chuột được phép xuống dưới nếu ô dưới nó có giá trị 1.
Right (R): Chuột được phép sang phải dưới nếu ô bên phải nó có giá trị 1.
Left (L): Chuột được phép sang trái dưới nếu ô bên trái nó có giá trị 1.
Up (U): Chuột được phép lên trên nếu ô trên nó có giá trị 1.
Hãy đưa ra tất cả các hành trình của con chuột trên mê cung. Đưa ra -1 nếu chuột không thể đi đến đích.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N là kích cỡ của mê cung; dòng tiếp theo đưa vào ma trận nhị phân A[N][N].
T, N, A[i][j] thỏa mãn ràng buộc: 1≤T ≤10; 2≤N≤8; 0≤A[i][j] ≤1.
Output:

Đưa ra các xâu ký tự được sắp xếp, trong đó mỗi xâu là một đường đi của con chuột trong mê cung. In ra đáp án theo thứ tự từ điển. Đưa ra -1 nếu chuột không đi được đến đích.
Input

3
4
1 0 0 0

1 1 0 1

0 1 0 0

0 1 1 1
4
1 0 0 0

1 1 0 1

1 1 0 0

0 1 1 1

5

1 0 0 0 0

1 1 1 1 1

1 1 1 0 1

0 0 0 0 1

0 0 0 0 1

Output

DRDDRR

DDRDRR DRDDRR

DDRRURRDDD DDRURRRDDD DRDRURRDDD DRRRRDDD
*/

#include <bits/stdc++.h>

using namespace std;

int n, state, a[10][10], vs[10][10];

void input() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            vs[i][j] = 0;
        }

}

void Try(int i, int j, string s) {
    if (i == n && j == n) {
        cout << s << " ";
        state = 1;
        return;
    }
    vs[i][j] = 1;
    int x = i + 1, y = j + 1, z = i - 1, t = j - 1;
    if (i < n && a[x][j] == 1 && vs[x][j] == 0) Try(x, j, s + 'D');
    if (j > 1 && a[i][t] == 1 && vs[i][t] == 0) Try(i, t, s + 'L');
    if (j < n && a[i][y] == 1 && vs[i][y] == 0) Try(i, y, s + 'R');
    if (i > 1 && a[z][j] == 1 && vs[z][j] == 0) Try(z, j, s + 'U');
    vs[i][j] = 0;
}

void solve() {
    state = 0;
    if (a[1][1] != 1 || a[n][n] != 1) printf("-1");
    else {
        Try(1, 1, "");
        if (state == 0) printf("-1");
    }
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
