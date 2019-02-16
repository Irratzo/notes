// Beispiel einer virtuellen Funktion
#include <iostream>
#define PI 3.141592


class Circle {
  protected:
    double radius;
  public:
    Circle(double r);
    void setRadius(double r);
    double getRadius();
    double Diameter();
    double Circumference();
    virtual void print();
	void non_virt_print();
};

class Sphere : public Circle {
  public:
    Sphere(double r) : Circle(r) {};
    double Volume();
    virtual void print();
	void non_virt_print();
};

Circle::Circle(double r) {
  radius = r;
}

void Circle::setRadius(double r) {
  radius = r;
}

double Circle::getRadius() {
  return radius;
}

double Circle::Diameter() {
  return 2*radius;
}

double Circle::Circumference() {
  return 2*radius*PI;
}

void Circle::print() {
  std::cout << "I'm a circle with radius " << radius << "." << std::endl;
}

void Circle::non_virt_print() {
	std::cout << "Non-virtual: I'm a circle with radius " << radius << "." << std::endl;
}

double Sphere::Volume() {
	return radius * radius * radius * PI * 4 / 3;
}

void Sphere::print() {
  std::cout << "I'm a sphere with radius " << radius << "." << std::endl;
}

void Sphere::non_virt_print() {
	std::cout << "Non-virtual: I'm a sphere with radius " << radius << "." << std::endl;
}

int main() {
  Sphere * s = new Sphere(5.0);
  s->print();
  s->non_virt_print();
  Circle * c = s;
  c->print();
  c->non_virt_print();

  return 0;
}
