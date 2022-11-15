//
// Created by Nguyen Van Khanh on 11/2/2021.
//

/*
TÌM ĐƯỜNG
Cho một bảng S[][] kích thước N x M, bao gồm các ô trống, các vật cản. Ban đầu bạn ở vị trí S. Nhiệm vụ của bạn là hãy di chuyển tới vị trí T, sao cho số lần đổi hướng không quá hai lần.

Input:

Dòng đầu tiên là số lượng bộ test T (T <= 20).

Mỗi test bắt đầu bởi hai số nguyên N và M (1 <= N, M <= 500).

N dòng tiếp theo, mỗi dòng gồm M kí tự mô tả bảng S. Trong đó: ‘.’ là một ô trống, ‘*’ là vật cản, ‘S’ là vị trí xuất phát và ‘T’ là vị trí đích. (Chỉ có một vị trí S và T duy nhất).

Output: 

Với mỗi test, in ra “YES” nếu tìm được đường đi, ra in “NO” trong trường hợp ngược lại.

Test ví dụ:

Input:

Output

2

5 5

..S..

****.

T....

****.

.....

5 5

S....

****.

.....

.****

..T..

 

YES

NO

*/

#include <bits/stdc++.h>
using namespace std;
int n, m, start_row, start_col, dest_row, dest_col, vs[505][505];
char a[505][505];

void init() { //hàm khởi tạo
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') { //gán vị trí bắt đầu
                start_row = i;
                start_col = j;
            } else if (a[i][j] == 'T') { //gán vị trí kết thúc
                dest_row = i;
                dest_col = j;
            }
        }
    }
}

int bfs() { //hàm bfs
    queue <pair <int, int> > q;
    q.push ({start_row, start_col});
    while (!q.empty ()) { //do đánh dấu đã duyệt là 1 nên số lần đổi hướng sẽ bằng vs[i][j] - 2
        int row = q.front ().first;
        int col = q.front ().second;
        if (vs[row][col] == 4) return 3; //nếu qua số lần đổi hướng trả về 3
        q.pop ();
        //duyệt theo các hướng và tăng số lần đổi hướng lên và thêm vị trí được duyệt đến vào hàng đợi
        for (int i = row - 1; i >= 0; i--)
            if (a[i][col] == '*') break;
            else {
                if (vs[i][col] == 0) {
                    vs[i][col] = vs[row][col] + 1;
                    q.push ({i, col});
                }
            }
        for (int i = row + 1; i < n; i++)
            if (a[i][col] == '*') break;
            else {
                if (vs[i][col] == 0) {
                    vs[i][col] = vs[row][col] + 1;
                    q.push ({i, col});
                }
            }
        for (int i = col - 1; i >= 0; i--)
            if (a[row][i] == '*') break;
            else {
                if (vs[row][i] == 0) {
                    vs[row][i] = vs[row][col] + 1;
                    q.push ({row, i});
                }
            }
        for (int i = col + 1; i < m; i++)
            if (a[row][i] == '*') break;
            else {
                if (vs[row][i] == 0) {
                    vs[row][i] = vs[row][col] + 1;
                    q.push ({row, i});
                }
            }
        if (vs[dest_row][dest_col] != 0) return vs[dest_row][dest_col] - 2; //nếu tìm thấy đích thì trả về số lần đổi
    }
    return 3; //nếu không tìm được đừng đi thì trả về số lớn hơn 2
}

void solve() { //hàm xử lý
    memset (vs, 0, sizeof (vs)); //làm mới mảng đã thăm
    vs[start_row][start_col] = 1; //đánh dấu vị trí xuất phát đã được duyệt qua
    if (bfs () <= 2) cout << "YES" << endl; //đưa ra kết quả
    else cout << "NO" << endl;
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
