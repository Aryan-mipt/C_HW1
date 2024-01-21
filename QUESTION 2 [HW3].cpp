#include <iostream>
using namespace std;

int pow(int b, int exp) {
    int result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= b;
    }
    return result;
}

int sum(int n, int k) {
    int result = 0;
    for (int i = 1; i <= k; ++i) {
        result += pow(n, i);
    }
    return result;
}

int main() {
    int n, k;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;
    int result = sum(n, k);
    cout << "Sum of the sequence F(" << n << ", " << k << ") = " << result << endl;
    return 0;
}
