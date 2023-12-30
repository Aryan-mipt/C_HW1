#include <iostream>
using namespace std;
class fraction {
    int num;
    int den;

    int hcf(int a, int b) {
        if (b == 0) {
            return a;
        }
        return hcf(b, a % b);
    }

    void smpl() {
        int cmndiv = hcf(num, den);
        num /= cmndiv;
        den /= cmndiv;
    }

public:
    fraction() : num(0), den(1) {}

    fraction& operator+=(const fraction& other) {
        num = num * other.den + other.num * den;
        den *= other.den;
        smpl();
        return *this;
    }

    friend ostream& operator<<(ostream& out, const fraction& frac) {
        out << frac.num << "/" << frac.den;
        return out;
    }

    friend istream& operator>>(istream& in, fraction& frac) {
        in >> frac.num;
        in.ignore(); // ignore /
        in >> frac.den;
        frac.smpl();
        return in;
    }

    double todbl() const {
        return static_cast<double>(num) / den;
    }
};

int main() {
    fraction a, b;

    cout << "Enter the first fraction (e.g., 1/2): ";
    cin >> a;

    cout << "Enter the second fraction (e.g., 3/4): ";
    cin >> b;

    cout << "Entered fractions: a = " << a << ", b = " << b << endl;

    a += b;
    cout << "Sum of fractions 'a' and 'b' = " << a << endl;

    cout << "Fraction a as double: " << a.todbl() << endl;

    return 0;
}
