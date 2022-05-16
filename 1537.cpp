//
// Created by Nguyen Van Khanh on 11/2/2021.
//

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