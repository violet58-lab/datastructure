#include <iostream>
using namespace std;

#define infinity 21000
#define N 4

void floyd(int matrix[N][N], int n) {
    int i, j, k;
    int M[N][N], P[N][N];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            M[i][j] = matrix[i][j];
            if (i != j && matrix[i][j] < infinity)
                P[i][j] = i;
            else
                P[i][j] = -1;
        }
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (M[i][k] < infinity &&
                    M[k][j] < infinity &&
                    M[i][k] + M[k][j] < M[i][j]) {
                    M[i][j] = M[i][k] + M[k][j];
                    P[i][j] = P[k][j];
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j && M[i][j] < infinity) {
                cout << M[i][j] << ": ";
                k = j;
                cout << k;
                while (k != i) {
                    k = P[i][k];
                    cout << "<-" << k;
                }
                cout << endl;
            }
        }
    }
}

int main() {
    int matrix[N][N] = {
        {0,        2,        6,        4},
        {infinity, 0,        3,        infinity},
        {7,        infinity, 0,        1},
        {5,        infinity, 12,       0}
    };

    floyd(matrix, N);
    return 0;
}