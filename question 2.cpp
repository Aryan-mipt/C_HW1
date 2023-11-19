#include <iostream>

using namespace std;

bool function(int x1, int y1, int x2, int y2, int X1, int Y1, int X2, int Y2) {
    if (x1 >= X2 || X1 >= x2) {
        return false;
    }


    if (y1 >= Y2 || Y1 >= y2) {
        return false;
    }


    return true;
}

int main() {
    int x1, y1, x2, y2;
    int X1, Y1, X2, Y2;
    cout << "Enter the coordinate of the first rectangle (x1) :- ";
    cin >> x1;
    cout << "Enter the coordinate of the first rectangle (y1) :- ";
    cin >>y1;
    cout << "Enter the coordinate of the first rectangle (x2) :- ";
    cin >>x2;
    cout << "Enter the coordinate of the first rectangle (y2) :- ";
    cin >>y2;


    cout << "Enter the coordinate of the second rectangle (X1) :- ";
    cin >> X1;
    cout << "Enter the coordinate of the second rectangle (Y1) :- ";
    cin >>Y1;
    cout << "Enter the coordinate of the second rectangle (x2) :- ";
    cin >>X2;
    cout << "Enter the coordinate of the second rectangle (y2) :- ";
    cin >>Y2;
    if (function(x1, y1, x2, y2, X1, Y1, X2, Y2)) {
        cout << "True, Rectangles overlap" << endl;
    } else {
        cout << "False, Rectangles do not overlap." << endl;
    }

    return 0;
}

