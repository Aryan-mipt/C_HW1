#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of values: ";
    cin >> n;

    string arr[n];
    for (int i = 0; i < n; ++i) {
        cout << "Enter the value: ";
        cin >> arr[i];
    }

    for (int j = 0; j < n; ++j) {
        string ele[3] = {arr[j]};

        
        if (ele[1] == ele[2]) {
            cout << ele[0] << " ";
        }
    }

    return 0;
}
