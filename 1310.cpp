//
// Created by khanh on 10/9/2021.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int a[k + 1], i;
        for (i = 1; i <= k; i++) scanf("%d", &a[i]);
        for (i = k; i > 0; i--) {
            if (a[i] != n - k + i) {
                a[i]++;
                for (int j = i + 1; j <= k; j++)
                    a[j] = a[i] + j - i;
                break;
            }
        }
        if (i == 0) for (i = 1; i <= k; i++) printf("%d ", i);
        else for (i = 1; i <= k; i++) printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}