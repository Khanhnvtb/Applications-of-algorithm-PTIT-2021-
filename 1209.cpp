//
// Created by khanh on 10/9/2021.
//

/*
CHÚ CỪU XA CÁCH

Bài làm tốt nhất
Trên cánh đồng kích thước N x N có K chú cừu. Người nông dân sợ các chú cừu đi lạc nên đã làm một số rào chắn giữa các khu vực. Các chú cừu chỉ có thể di chuyển lên trên, xuống dưới, sang trái, sang phải khu vực bên cạnh, và không thể vượt qua được hàng rào.

Hai chú cừu A và B được gọi là ‘xa cách’ nếu như chúng không thể di chuyển tới vị trí của nhau. Các bạn hãy xác định xem số cặp chú cừu xa cách bằng nhau nhiêu?

Input:  Dòng đầu tiên gồm 3 số nguyên dương N, K và M (1 ≤  N ≤  100, K ≤  100, M ≤  N^2).  M dòng tiếp theo, mỗi dòng gồm 4 số nguyên u, v, x, y cho biết có rào chắn ở giữa hai khu vực (u, v) và (x, y) (2 ô này cạnh nhau). K dòng cuối, mỗi dòng chứa 2 số nguyên là tọa độ của mỗi chú cừu.

Output: In ra số cặp chú cừu bị xa cách tìm được.

 

Ví dụ:

Input

3 3 3

2 2 2 3

3 3 3 2

3 3 2 3

3 3

2 2

2 3

2

Output

Giải thích test: Cặp (3, 1) và (2, 1).
*/

#include <bits/stdc++.h>

using namespace std;

struct data {
    int up, left, right, down;
};

int n, k, m, res, vs[105][105];
data a[105][105]; // mảng lưu trữ vị trí hàng rào
int dx[] = {-1, 0, 0, 1}; // toạ độ x ứng với lên, trái, phải, xuống
int dy[] = {0, -1, 1, 0}; // toạ độ y ứng với lên, trái, phải, xuống
vector<pair<int, int> > b;

bool check(int i, int j) {
    if (i < 1 || i > n || j < 1 || j > n) return false;
    return true;
}

void input() { //hàm khởi tạo
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            vs[i][j] = 0; //đánh dấu tất cả chưa được thăm
            a[i][j] = {0, 1, 2, 3}; // đánh dấu tất cả vị trí đều đi được lên, trái, phải, xuống
        }
    int u, v, x, y;
    while (m--) {
        scanf("%d %d %d %d", &u, &v, &x, &y);
        if (u == x + 1) {
            a[u][v].up = -1; //đánh dấu có hàng rào
            a[x][y].down = -1; //đánh dấu có hàng rào
        } else if (v == y + 1) {
            a[u][v].left = -1; //đánh dấu có hàng rào
            a[x][y].right = -1; //đánh dấu có hàng rào
        } else if (v == y - 1) {
            a[u][v].right = -1; //đánh dấu có hàng rào
            a[x][y].left = -1; //đánh dấu có hàng rào
        } else {
            a[u][v].down = -1; //đánh dấu có hàng rào
            a[x][y].up = -1; //đánh dấu có hàng rào
        }
    }
    int i, j;
    for (int t = 0; t < k; t++) {
        scanf("%d %d", &i, &j);
        vs[i][j] = 2; //đánh dấu 2 là có cừu, đánh dấu 1 là đã duyệt qua, đánh dấu 0 là không có cừu và chưa duyệt qua
        b.push_back({i, j}); //thêm con cừu
    }
}

void solve() { //hàm xử lý
    res = 0;
    int row, col;
    for (int i = 0; i < b.size(); i++) { //duyệt qua tất cả con cừu
        row = b[i].first;
        col = b[i].second;
        if (vs[row][col] == 2) { //nếu cừu chưa được duyệt qua
            vs[row][col] = 1; //đánh dấu đã được duyệt qua
            queue<pair<int, int> > q;
            q.push({row, col}); //thêm con cừu đó vào hàng đợi
            int cnt = 1; //đánh dấu có 1 con cừu trong đàn hiện tại
            while (!q.empty()) {
                row = q.front().first;
                col = q.front().second;
                q.pop();
                if (a[row][col].up == 0) { // nếu bên trên không có hàng rào
                    int x = row + dx[0];
                    int y = col + dy[0];
                    if (check(x, y) && vs[x][y] != 1) { //kiểm tra nếu chưa được duyệt
                        if (vs[x][y] == 2) //nếu tại vị trí có cừu
                            cnt++; //tăng số con cừu trong 1 thành phần liên thông
                        vs[x][y] = 1; // đánh dấu đã duyệt qua
                        q.push({x, y}); //thêm con cừu đó vào hàng đợi
                    }
                }
                if (a[row][col].left == 1) { // nếu bên trái không có hàng rào
                    int x = row + dx[1];
                    int y = col + dy[1];
                    if (check(x, y) && vs[x][y] != 1) { //kiểm tra nếu chưa được duyệt
                        if (vs[x][y] == 2) //nếu tại vị trí có cừu
                            cnt++; //tăng số con cừu trong 1 thành phần liên thông
                        vs[x][y] = 1; //đánh dấu đã duyệt qua
                        q.push({x, y}); //thêm con cừu đó vào hàng đợi
                    }
                }
                if (a[row][col].right == 2) { // nếu bên phải không có hàng rào
                    int x = row + dx[2];
                    int y = col + dy[2];
                    if (check(x, y) && vs[x][y] != 1) { //kiểm tra nếu chưa được duyệt
                        if (vs[x][y] == 2)  //nếu tại vị trí có cừu
                            cnt++; //tăng số con cừu trong 1 thành phần liên thông
                        vs[x][y] = 1; //đánh dấu đã duyệt qua
                        q.push({x, y}); //thêm con cừu đó vào hàng đợi
                    }
                }
                if (a[row][col].down == 3) { // nếu bên dưới không có hàng rào
                    int x = row + dx[3];
                    int y = col + dy[3];
                    if (check(x, y) && vs[x][y] != 1) { //kiểm tra nếu chưa được duyệt
                        if (vs[x][y] == 2) //nếu tại vị trí có cừu
                            cnt++; //tăng số con cừu trong 1 thành phần liên thông
                        vs[x][y] = 1; //đánh dấu đã duyệt qua
                        q.push({x, y}); //thêm con cừu đó vào hàng đợi
                    }
                }
            }
            k -= cnt; // số con cừu còn lại chưa được duyệt qua
            res += k * cnt; //số cừu trong đàn hiện tại nhân với số con cừu chưa được duyệt qua
        }
    }
    printf("%d\n", res); //đưa ra kết quả
}

int main() {
    input();
    solve();
    return 0;
}
