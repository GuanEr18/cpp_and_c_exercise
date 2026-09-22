#include <iostream>
#include <cstring>
using namespace std;

int L, N, answer;
int mat[5][5];

void fill(int row, int col) {
    if (row == N) {
        for (int j = 0; j < N; j++) {
            int s = 0;
            for (int i = 0; i < N; i++) s += mat[i][j];
            if (s != L) return;
        }
        answer++;
        return;
    }
    if (col == N - 1) {
        int rowsum = 0;
        for (int j = 0; j < N - 1; j++) rowsum += mat[row][j];
        int last = L - rowsum;
        if (last < 0) return;
        mat[row][col] = last;
        for (int j = 0; j < N; j++) {
            int cs = 0;
            for (int i = 0; i <= row; i++) cs += mat[i][j];
            if (cs > L) return;
        }
        fill(row + 1, 0);
        return;
    }
    for (int v = 0; v <= L; v++) {
        int colsum = 0;
        for (int i = 0; i < row; i++) colsum += mat[i][col];
        if (colsum + v > L) continue;
        mat[row][col] = v;
        fill(row, col + 1);
    }
}

int main() {
    while (cin >> L >> N) {
        answer = 0;
        memset(mat, 0, sizeof(mat));
        fill(0, 0);
        cout << answer << endl;
    }
    return 0;
}