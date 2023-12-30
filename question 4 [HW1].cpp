#include <iostream>
using namespace std;

void S_matrix(int n, int matrix[][10]) {
    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    int num = 1;

    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; ++i) {
            matrix[top][i] = num++;
        }
        ++top;

        for (int i = top; i <= bottom; ++i) {
            matrix[i][right] = num++;
        }
        --right;

        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                matrix[bottom][i] = num++;
            }
            --bottom;
        }


        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = num++;
            }
            ++left;
        }
    }
}

void print(int n, int matrix[][10]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int matrix[10][10];

    S_matrix(n, matrix);

    cout << "Output:" << endl;
    print(n, matrix);

    return 0;
}
