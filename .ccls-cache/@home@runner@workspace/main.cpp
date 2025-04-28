#include <iostream>
#include <string>
using namespace std;

class BasicShape {
private:
    double area;
    string name;

public:
    BasicShape() : area(0), name("") {}

    void setArea(double a) {
        area = a;
    }
    double getArea() {
      return area;
    }
    void setName(string n) {
        name = n;
    }
    string getName() {
      return name;
    }
    virtual void calcArea() = 0;
    virtual ~BasicShape() {}
};

class Circle : public BasicShape {
private: 
    double xCenter, yCenter, radius;

public:
    Circle(double x, double y, double r, string n = "Circle") {
        setName(n);
        xCenter = x;
        yCenter = y;
        radius = r;
        calcArea();
    }
  void calcArea() override {
    double area = 3.14159 * radius * radius;
    setArea(area);
  }
  double getXCenter() {
    return xCenter;
  }
  double getYCenter() {
    return yCenter;
  }
  double getRadius() {
    return radius;
  }
};

class Rectangle : public BasicShape {
private:
    double length, width;

public:
    Rectangle(double l, double w, string n = "Rectangle") {
        setName(n);
        length = l;
        width = w;
        calcArea();
    }
  void calcArea() override {
    double area = length * width;
    setArea(area);
  }
  double getLength() {
    return length;
  }
  double getWidth() {
    return width;
  }
};

class Square : public Rectangle {
private:
    double side;

public:
    Square(double s, string n = "Square") : Rectangle(s, s, n) {
        side = s;
        setName(n);
    }
    double getSide() {
          return side;
    }
};

int main() {
  BasicShape* shapes[5];
  shapes[0] = new Rectangle(5, 10, "Rectangle1");
  shapes[1] = new Rectangle(3, 4, "Rectangle2");
  shapes[2] = new Circle(0, 0, 7, "Circle1");
  shapes[3] = new Circle(1, 2, 3, "Circle2");
  shapes[4] = new Square(6, "Square1");

  for (int i = 0; i < 5; i++) {
    cout << shapes[i]->getName() << ": Area = " << shapes[i]->getArea() << endl;
  }
  for (int i = 0; i < 5; i++) {
    delete shapes[i];
  }
  return 0;
};
