#include <iostream>
using namespace std;


void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}



void print(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
    }
    cout << endl;
}



void gP(int arr[], int n, int start) {
    if (start == n - 1) {
        print(arr, n);
    } else {
        for (int i = start; i < n; ++i) {
            swap(arr[start], arr[i]);
            gP(arr, n, start + 1);
            swap(arr[start], arr[i]);
        }
    }
}



int main() {
    int number;
    cout << "Enter a three-digit number :- ";
    cin >> number;

    if (number > 99 && number <= 999) {
        int digits[3] = {number / 100, (number / 10) % 10, number % 10};

        gP(digits, 3, 0);
    } else {
        cout << "Please enter a valid three-digit number." << endl;
    }

    return 0;
}
