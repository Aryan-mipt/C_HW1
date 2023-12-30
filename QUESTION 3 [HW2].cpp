#include <iostream>
#include <cmath>
using namespace std;
class Figure {
public:
    virtual double Area() const = 0;
    virtual double prmtr() const = 0;
    virtual void display() const = 0;
};
class Triangle : public Figure {
private:
    double side1;
    double side2;
    double side3;
public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}
    virtual double Area() const override {
        double s = (side1 + side2 + side3) / 2.0;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    virtual double prmtr() const override {
        return side1 + side2 + side3;
    }
    virtual void display() const override {
        cout << "Triangle: side1 = " << side1 << ", side2 = " << side2 << ", side3 = " << side3 << endl;
    }
};
class Rectangle : public Figure {
private:
    double length;
    double width;
public:
    Rectangle(double len, double wid) : length(len), width(wid) {}
    virtual double Area() const override {
        return length * width;
    }
    virtual double prmtr() const override {
        return 2 * (length + width);
    }
    virtual void display() const override {
        cout << "Rectangle: Length = " << length << ", Width = " << width << endl;
    }
};
class Circle : public Figure {
private:
    double radius;
public:
    Circle(double rad) : radius(rad) {}
    virtual double Area() const override {
        return M_PI * radius * radius;
    }
    virtual double prmtr() const override {
        return 2 * M_PI * radius;
    }
    virtual void display() const override {
        cout << "Circle: Radius = " << radius << endl;
    }
};

int main() {
    double side1, side2, side3, length, width, radius;
    cout << "Enter the sides of the triangle (e.g., 3 4 5): ";
    cin >> side1 >> side2 >> side3;
    Triangle trngl(side1, side2, side3);
    cout << "Enter the length and width of the rectangle (e.g., 4 5): ";
    cin >> length >> width;
    Rectangle rect(length, width);
    cout << "Enter the radius of the circle (e.g., 2): ";
    cin >> radius;
    Circle crcl(radius);
    trngl.display();
    cout << "Area: " << trngl.Area() << ", perimeter: " << trngl.prmtr() << endl;
    rect.display();
    cout << "Area: " << rect.Area() << ", perimeter: " << rect.prmtr() << endl;
    crcl.display();
    cout << "Area: " << crcl.Area() << ", Circumference: " << crcl.prmtr() << endl;
    return 0;
}
