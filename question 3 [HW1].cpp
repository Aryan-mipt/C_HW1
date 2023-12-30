#include <iostream>
using namespace std;


double distance(int x, int y) {
    return x * x + y * y;
}


void swap_P(int &x1, int &y1, int &x2, int &y2) {
    int tmpX = x1;
    int tmpY = y1;
    x1 = x2;
    y1 = y2;
    x2 = tmpX;
    y2 = tmpY;
}

int main() {
    int N, k;
    cout << "Enter the number of points N and k: ";
    cin >> N >> k;

    int points[N][2];

    
    for (int i = 0; i < N; ++i) {
        cout << "Enter the coordinates of point " << i + 1 << " (x y): ";
        cin >> points[i][0] >> points[i][1];
    }


    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (distance(points[j][0], points[j][1]) > distance(points[j + 1][0], points[j + 1][1])) {
                swap_P(points[j][0], points[j][1], points[j + 1][0], points[j + 1][1]);
            }
        }
    }

    cout << "Output:" << endl;
    for (int i = 0; i < k; ++i) {
        cout << points[i][0] << " " << points[i][1] << endl;
    }

    return 0;
}
