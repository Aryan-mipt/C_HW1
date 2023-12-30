#include <iostream>
using namespace std;

const int msize = 10;

class Vector {
private:
    double elements[msize];
    int size;
public:
    Vector() : size(0) {}
    Vector(const double* values, int n) : size(n) {
        if (n > msize) {
            cerr << "Error: Vector size exceeds the maximum limit." << endl;
            size = 0;
        } else {
            for (int i = 0; i < size; ++i) {
                elements[i] = values[i];
            }
        }
    }
    Vector& operator+=(const Vector& other) {
        if (size==other.size) {
            for (int i = 0; i < size; ++i) {
                elements[i] += other.elements[i];
            }
        } else {
            cerr << "Error: Vectors must have the same size for addition." << endl;
        }
        return *this;
    }
    friend Vector operator*(const Vector& vec, double scalar) {
        Vector result = vec;
        for (int i = 0; i < result.size; ++i) {
            result.elements[i] *= scalar;
        }
        return result;
    }
    friend double operator*(const Vector& vec1, const Vector& vec2) {
        int size1 = vec1.size;
        int size2 = vec2.size;
        if (size1 == size2) {
            double result = 0.0;
            for (int i = 0; i < size1; ++i) {
                result += vec1.elements[i] * vec2.elements[i];
            }
            return result;
        } else {
            cerr << "Error: Vectors must have the same size for scalar product." << endl;
            return 0.0;
        }
    }
    friend ostream& operator<<(ostream& out, const Vector& vec) {
        out << "(";
        for (int i = 0; i < vec.size; ++i) {
            out << vec.elements[i];
            if (i < vec.size - 1) {
                out << ", ";
            }
        }
        out << ")";
        return out;
    }
    friend istream& operator>>(istream& in, Vector& vec) {
        int i = 0;
        while (i < vec.size && in >> vec.elements[i]) {
            ++i;
        }
        return in;
    }
};

int main() {
    int size;
    cout << "Enter the size of the vectors: ";
    cin >> size;
    double values1[msize], values2[msize];
    cout << "Enter the elements of the first vector (e.g., 1.0 2.0 3.0): ";
    Vector v1(values1, size);
    cin >> v1;
    cout << "Enter the elements of the second vector (e.g., 4.0 5.0 6.0): ";
    Vector v2(values2, size);
    cin >> v2;
    cout << "Vector 1: " << v1 << endl;
    cout << "Vector 2: " << v2 << endl;
    v1 += v2;
    cout << "Sum of both vectors: " << v1 << endl;
    Vector v3 = v1 * 2.0;
    cout<<"Scalar Multiplication: "<<endl << "v1 * 2.0: " << v3 << endl;
    double result = v1 * v2;
    cout << "Scalar product of v1 and v2: " << result << endl;
    return 0;
}
