#include "../include/function.h"

Square::Square(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
    : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4) {
    calculateCenter();
}

void Square::calculateCenter() {
    center_x = (x1 + x2 + x3 + x4) / 4.0;
    center_y = (y1 + y2 + y3 + y4) / 4.0;
}

Square::Square(const Square& other) 
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2),
      x3(other.x3), y3(other.y3), x4(other.x4), y4(other.y4),
      center_x(other.center_x), center_y(other.center_y) {}

Square::Square(Square&& other) noexcept 
    : x1(std::move(other.x1)), y1(std::move(other.y1)),
      x2(std::move(other.x2)), y2(std::move(other.y2)),
      x3(std::move(other.x3)), y3(std::move(other.y3)),
      x4(std::move(other.x4)), y4(std::move(other.y4)),
      center_x(std::move(other.center_x)), center_y(std::move(other.center_y)) {
    other.x1 = other.y1 = other.x2 = other.y2 = other.x3 = other.y3 = other.x4 = other.y4 = 0;
    other.center_x = other.center_y = 0;
}

Square& Square::operator=(const Square& other) {
    if (this != &other) {
        x1 = other.x1; y1 = other.y1;
        x2 = other.x2; y2 = other.y2;
        x3 = other.x3; y3 = other.y3;
        x4 = other.x4; y4 = other.y4;
        center_x = other.center_x;
        center_y = other.center_y;
    }
    return *this;
}

Square& Square::operator=(Square&& other) noexcept {
    if (this != &other) {
        x1 = std::move(other.x1); y1 = std::move(other.y1);
        x2 = std::move(other.x2); y2 = std::move(other.y2);
        x3 = std::move(other.x3); y3 = std::move(other.y3);
        x4 = std::move(other.x4); y4 = std::move(other.y4);
        center_x = std::move(other.center_x);
        center_y = std::move(other.center_y);
        other.x1 = other.y1 = other.x2 = other.y2 = other.x3 = other.y3 = other.x4 = other.y4 = 0;
        other.center_x = other.center_y = 0;
    }
    return *this;
}

bool Square::operator==(const Figure& other) const {
    if (auto square = dynamic_cast<const Square*>(&other)) {
        return *this == *square;
    }
    return false;
}

bool Square::operator==(const Square& other) const {
    return x1 == other.x1 && y1 == other.y1 &&
           x2 == other.x2 && y2 == other.y2 &&
           x3 == other.x3 && y3 == other.y3 &&
           x4 == other.x4 && y4 == other.y4;
}

std::pair<double, double> Square::center() const {
    return {center_x, center_y};
}

Square::operator double() const {
    return area();
}

std::unique_ptr<Figure> Square::clone() const {
    return std::make_unique<Square>(*this);
}

double Square::area() const {
    double area = std::abs((x1*y2 + x2*y3 + x3*y4 + x4*y1) - (y1*x2 + y2*x3 + y3*x4 + y4*x1)) / 2.0;
    return area;
}

void Square::printVertices(std::ostream& os) const {
    os << "Square vertices: ";
    os << "(" << x1 << ", " << y1 << "), ";
    os << "(" << x2 << ", " << y2 << "), ";
    os << "(" << x3 << ", " << y3 << "), ";
    os << "(" << x4 << ", " << y4 << ")";
}

void Square::read(std::istream& is) {
    is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    calculateCenter();
}

Rectangle::Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
    : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4) {
    calculateCenter();
}

void Rectangle::calculateCenter() {
    center_x = (x1 + x2 + x3 + x4) / 4.0;
    center_y = (y1 + y2 + y3 + y4) / 4.0;
}

Rectangle::Rectangle(const Rectangle& other) 
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2),
      x3(other.x3), y3(other.y3), x4(other.x4), y4(other.y4),
      center_x(other.center_x), center_y(other.center_y) {}

Rectangle::Rectangle(Rectangle&& other) noexcept 
    : x1(std::move(other.x1)), y1(std::move(other.y1)),
      x2(std::move(other.x2)), y2(std::move(other.y2)),
      x3(std::move(other.x3)), y3(std::move(other.y3)),
      x4(std::move(other.x4)), y4(std::move(other.y4)),
      center_x(std::move(other.center_x)), center_y(std::move(other.center_y)) {
    other.x1 = other.y1 = other.x2 = other.y2 = other.x3 = other.y3 = other.x4 = other.y4 = 0;
    other.center_x = other.center_y = 0;
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        x1 = other.x1; y1 = other.y1;
        x2 = other.x2; y2 = other.y2;
        x3 = other.x3; y3 = other.y3;
        x4 = other.x4; y4 = other.y4;
        center_x = other.center_x;
        center_y = other.center_y;
    }
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        x1 = std::move(other.x1); y1 = std::move(other.y1);
        x2 = std::move(other.x2); y2 = std::move(other.y2);
        x3 = std::move(other.x3); y3 = std::move(other.y3);
        x4 = std::move(other.x4); y4 = std::move(other.y4);
        center_x = std::move(other.center_x);
        center_y = std::move(other.center_y);
        other.x1 = other.y1 = other.x2 = other.y2 = other.x3 = other.y3 = other.x4 = other.y4 = 0;
        other.center_x = other.center_y = 0;
    }
    return *this;
}

bool Rectangle::operator==(const Figure& other) const {
    if (auto rectangle = dynamic_cast<const Rectangle*>(&other)) {
        return *this == *rectangle;
    }
    return false;
}

bool Rectangle::operator==(const Rectangle& other) const {
    return x1 == other.x1 && y1 == other.y1 && 
           x2 == other.x2 && y2 == other.y2 && 
           x3 == other.x3 && y3 == other.y3 && 
           x4 == other.x4 && y4 == other.y4;
}

std::pair<double, double> Rectangle::center() const {
    return {center_x, center_y};
}

Rectangle::operator double() const {
    return area();
}

std::unique_ptr<Figure> Rectangle::clone() const {
    return std::make_unique<Rectangle>(*this);
}

double Rectangle::area() const {
    double area = std::abs((x1*y2 + x2*y3 + x3*y4 + x4*y1) - (y1*x2 + y2*x3 + y3*x4 + y4*x1)) / 2.0;
    return area;
}

void Rectangle::printVertices(std::ostream& os) const {
    os << "Rectangle vertices: ";
    os << "(" << x1 << ", " << y1 << "), ";
    os << "(" << x2 << ", " << y2 << "), ";
    os << "(" << x3 << ", " << y3 << "), ";
    os << "(" << x4 << ", " << y4 << ")";
}

void Rectangle::read(std::istream& is) {
    is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    calculateCenter();
}

Trapezoid::Trapezoid(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
    : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4) {
    calculateCenter();
}

void Trapezoid::calculateCenter() {
    center_x = (x1 + x2 + x3 + x4) / 4.0;
    center_y = (y1 + y2 + y3 + y4) / 4.0;
}

Trapezoid::Trapezoid(const Trapezoid& other) 
    : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2),
      x3(other.x3), y3(other.y3), x4(other.x4), y4(other.y4),
      center_x(other.center_x), center_y(other.center_y) {}

Trapezoid::Trapezoid(Trapezoid&& other) noexcept 
    : x1(std::move(other.x1)), y1(std::move(other.y1)),
      x2(std::move(other.x2)), y2(std::move(other.y2)),
      x3(std::move(other.x3)), y3(std::move(other.y3)),
      x4(std::move(other.x4)), y4(std::move(other.y4)),
      center_x(std::move(other.center_x)), center_y(std::move(other.center_y)) {
    other.x1 = other.y1 = other.x2 = other.y2 = other.x3 = other.y3 = other.x4 = other.y4 = 0;
    other.center_x = other.center_y = 0;
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this != &other) {
        x1 = other.x1; y1 = other.y1;
        x2 = other.x2; y2 = other.y2;
        x3 = other.x3; y3 = other.y3;
        x4 = other.x4; y4 = other.y4;
        center_x = other.center_x;
        center_y = other.center_y;
    }
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept {
    if (this != &other) {
        x1 = std::move(other.x1); y1 = std::move(other.y1);
        x2 = std::move(other.x2); y2 = std::move(other.y2);
        x3 = std::move(other.x3); y3 = std::move(other.y3);
        x4 = std::move(other.x4); y4 = std::move(other.y4);
        center_x = std::move(other.center_x);
        center_y = std::move(other.center_y);
        other.x1 = other.y1 = other.x2 = other.y2 = other.x3 = other.y3 = other.x4 = other.y4 = 0;
        other.center_x = other.center_y = 0;
    }
    return *this;
}

bool Trapezoid::operator==(const Figure& other) const {
    if (auto trapezoid = dynamic_cast<const Trapezoid*>(&other)) {
        return *this == *trapezoid;
    }
    return false;
}

bool Trapezoid::operator==(const Trapezoid& other) const {
    return x1 == other.x1 && y1 == other.y1 &&
           x2 == other.x2 && y2 == other.y2 &&
           x3 == other.x3 && y3 == other.y3 &&
           x4 == other.x4 && y4 == other.y4;
}

std::pair<double, double> Trapezoid::center() const {
    return {center_x, center_y};
}

Trapezoid::operator double() const {
    return area();
}

std::unique_ptr<Figure> Trapezoid::clone() const {
    return std::make_unique<Trapezoid>(*this);
}

double Trapezoid::area() const {
    double area = std::abs((x1*y2 + x2*y3 + x3*y4 + x4*y1) - (y1*x2 + y2*x3 + y3*x4 + y4*x1)) / 2.0;
    return area;
}

void Trapezoid::printVertices(std::ostream& os) const {
    os << "Trapezoid vertices: ";
    os << "(" << x1 << ", " << y1 << "), ";
    os << "(" << x2 << ", " << y2 << "), ";
    os << "(" << x3 << ", " << y3 << "), ";
    os << "(" << x4 << ", " << y4 << ")";
}

void Trapezoid::read(std::istream& is) {
    is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    calculateCenter();
}

void printMenu() {
    std::cout << "1. Add Square (enter 8 coordinates: x1 y1 x2 y2 x3 y3 x4 y4)" << std::endl;
    std::cout << "2. Add Rectangle (enter 8 coordinates: x1 y1 x2 y2 x3 y3 x4 y4)" << std::endl;
    std::cout << "3. Add Trapezoid (enter 8 coordinates: x1 y1 x2 y2 x3 y3 x4 y4)" << std::endl;
    std::cout << "4. Print all figures" << std::endl;
    std::cout << "5. Calculate total area" << std::endl;
    std::cout << "6. Delete figure by index" << std::endl;
    std::cout << "7. Copy figure" << std::endl;
    std::cout << "8. Compare two figures" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Choose option: ";
}