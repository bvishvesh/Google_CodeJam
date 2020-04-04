#include <bits/stdc++.h>
using namespace std;
int mat[60][60], n, kdia, test;
bool row_s[60][60], col_s[60][60],final;

void construct(int rows, int cols, int mi) {
    if (rows == n && cols == n + 1 && mi == kdia && !final) {
        final = true;
        cout << "Case #" << test << ": " << "POSSIBLE\n";
        for (int e = 1; e <= n; e++) {
            for (int h = 1; h <= n; h++) {
                cout << mat[e][h] << " ";
            }
            cout << "\n";
        }
        return;
    } else if (rows > n) {
        return;
    } else if (cols > n) {
        construct(rows + 1, 1, mi);
    }
    for (int i = 1; i <= n && !final; i++) {
        if (!row_s[rows][i] && !col_s[cols][i]) {
            row_s[rows][i] = col_s[cols][i] = true;
            if (rows == cols) {
                mi += i;
            }
            mat[rows][cols] = i;

            construct(rows, cols + 1, mi);

            row_s[rows][i] = col_s[cols][i] = false;
            if (rows == cols) {
                mi -= i;
            }
            mat[rows][cols] = 0;
        }
    }
}

int main() {
    int fg ;
    scanf(" %d", &fg);
    for (test =1;test <= fg; ++test) {
        scanf(" %d %d", &n, &kdia);
        construct(1, 1, 0);
        if (!final) {
            cout << "Case #" << test << ": " << "IMPOSSIBLE\n";
        }
        final = false;
    }
    return 0;
}