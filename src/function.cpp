#include "../include/function.h"

Square::Square(double a, double centerX, double centerY) 
    : a(a), centerX(centerX), centerY(centerY) {}

void Square::printVertices(std::ostream& os) const {
    double half = a / 2.0;
    os << "vertices: "
        << centerX - half << "; " << centerY - half << ", "
        << centerX + half << "; " << centerY - half << ", "
        << centerX + half << "; " << centerY + half << ", "
        << centerX - half << "; " << centerY + half << ", ";
}

std::unique_ptr<Figure> Square::clone() const {
    return std::make_unique<Square>(*this);
}

bool Square::equals(const Figure* other) const {
    if (auto square = dynamic_cast<const Square*>(other)) {
        return *this == *square;
    }
    return false;
}

Square::Square(const Square& other) 
    : a(other.a), centerX(other.centerX), centerY(other.centerY) {}

Square::Square(Square&& other) noexcept 
    : a(std::move(other.a)), centerX(std::move(other.centerX)), centerY(std::move(other.centerY)) {
    other.a = 0.0;
    other.centerX = 0.0;
    other.centerY = 0.0;
}

Square& Square::operator=(const Square& other) {
    if (this != &other) {
        a = other.a;
        centerX = other.centerX;
        centerY = other.centerY;
    }
    return *this;
}

Square& Square::operator=(Square&& other) noexcept {
    if (this != &other) {
        a = std::move(other.a);
        centerX = std::move(other.centerX);
        centerY = std::move(other.centerY);
        other.a = 0.0;
        other.centerX = 0.0;
        other.centerY = 0.0;
    }
    return *this;
}

bool Square::operator==(const Square& other) const {
    return a == other.a && centerX == other.centerX && centerY == other.centerY;
}

double Square::getCenterX() const {
    return centerX;
}

double Square::getCenterY() const {
    return centerY;
}

double Square::calculateArea() const {
    return a * a;
}

std::istream& operator>>(std::istream& is, Square& square) {
    is >> square.a >> square.centerX >> square.centerY;
    return is;
}

Rectangle::Rectangle(double a, double b, double centerX, double centerY) 
    : a(a), b(b), centerX(centerX), centerY(centerY) {}

void Rectangle::printVertices(std::ostream& os) const {
    double half1 = a / 2.0;
    double half2 = b / 2.0;
    os << "vertices: "
        << centerX - half1 << "; " << centerY - half2 << ", "
        << centerX + half1 << "; " << centerY - half2 << ", "
        << centerX + half1 << "; " << centerY + half2 << ", "
        << centerX - half1 << "; " << centerY + half2 << ", ";
}

std::unique_ptr<Figure> Rectangle::clone() const {
    return std::make_unique<Rectangle>(*this);
}

bool Rectangle::equals(const Figure* other) const {
    if (auto rectangle = dynamic_cast<const Rectangle*>(other)) {
        return *this == *rectangle;
    }
    return false;
}

Rectangle::Rectangle(const Rectangle& other) 
    : a(other.a), b(other.b), centerX(other.centerX), centerY(other.centerY) {}

Rectangle::Rectangle(Rectangle&& other) noexcept 
    : a(std::move(other.a)), b(std::move(other.b)), 
      centerX(std::move(other.centerX)), centerY(std::move(other.centerY)) {
    other.a = 0.0;
    other.b = 0.0;
    other.centerX = 0.0;
    other.centerY = 0.0;
}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        a = other.a;
        b = other.b;
        centerX = other.centerX;
        centerY = other.centerY;
    }
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        a = std::move(other.a);
        b = std::move(other.b);
        centerX = std::move(other.centerX);
        centerY = std::move(other.centerY);
        other.a = 0.0;
        other.b = 0.0;
        other.centerX = 0.0;
        other.centerY = 0.0;
    }
    return *this;
}

bool Rectangle::operator==(const Rectangle& other) const {
    return a == other.a && b == other.b && 
           centerX == other.centerX && centerY == other.centerY;
}

double Rectangle::getCenterX() const {
    return centerX;
}

double Rectangle::getCenterY() const {
    return centerY;
}

double Rectangle::calculateArea() const {
    return a * b;
}

std::istream& operator>>(std::istream& is, Rectangle& rectangle) {
    is >> rectangle.a >> rectangle.b >> rectangle.centerX >> rectangle.centerY;
    return is;
}

Trapezoid::Trapezoid(double a, double b, double h, double centerX, double centerY) 
    : a(a), b(b), h(h), centerX(centerX), centerY(centerY) {}

void Trapezoid::printVertices(std::ostream& os) const {
    double half1 = a / 2.0;
    double half2 = b / 2.0;
    double half3 = h / 2.0;
    os << "vertices: "
        << centerX - half1 << "; " << centerY - half3 << ", "
        << centerX + half1 << "; " << centerY - half3 << ", "
        << centerX + half2 << "; " << centerY + half3 << ", "
        << centerX - half2 << "; " << centerY + half3 << ", ";
}

std::unique_ptr<Figure> Trapezoid::clone() const {
    return std::make_unique<Trapezoid>(*this);
}

bool Trapezoid::equals(const Figure* other) const {
    if (auto trapezoid = dynamic_cast<const Trapezoid*>(other)) {
        return *this == *trapezoid;
    }
    return false;
}

Trapezoid::Trapezoid(const Trapezoid& other) 
    : a(other.a), b(other.b), h(other.h), centerX(other.centerX), centerY(other.centerY) {}

Trapezoid::Trapezoid(Trapezoid&& other) noexcept 
    : a(std::move(other.a)), b(std::move(other.b)), h(std::move(other.h)),
      centerX(std::move(other.centerX)), centerY(std::move(other.centerY)) {
    other.a = 0.0;
    other.b = 0.0;
    other.h = 0.0;
    other.centerX = 0.0;
    other.centerY = 0.0;
}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this != &other) {
        a = other.a;
        b = other.b;
        h = other.h;
        centerX = other.centerX;
        centerY = other.centerY;
    }
    return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept {
    if (this != &other) {
        a = std::move(other.a);
        b = std::move(other.b);
        h = std::move(other.h);
        centerX = std::move(other.centerX);
        centerY = std::move(other.centerY);
        other.a = 0.0;
        other.b = 0.0;
        other.h = 0.0;
        other.centerX = 0.0;
        other.centerY = 0.0;
    }
    return *this;
}

bool Trapezoid::operator==(const Trapezoid& other) const {
    return a == other.a && b == other.b && h == other.h &&
           centerX == other.centerX && centerY == other.centerY;
}

double Trapezoid::getCenterX() const {
    return centerX;
}

double Trapezoid::getCenterY() const {
    return centerY;
}

double Trapezoid::calculateArea() const {
    return (a + b) * h / 2.0;
}

std::istream& operator>>(std::istream& is, Trapezoid& trapezoid) {
    is >> trapezoid.a >> trapezoid.b >> trapezoid.h >> trapezoid.centerX >> trapezoid.centerY;
    return is;
}

void printMenu() {
    std::cout << "1. add a square" << std::endl;
    std::cout << "2. add a rectangle" << std::endl;
    std::cout << "3. add a trapezoid" << std::endl;
    std::cout << "4. print all figures" << std::endl;
    std::cout << "5. calculate the total area" << std::endl;
    std::cout << "6. delete a figure by index" << std::endl;
    std::cout << "7. copy a figure" << std::endl;
    std::cout << "8. compare two figures" << std::endl;
    std::cout << "9. move" << std::endl;
    std::cout << "0. exit" << std::endl;
    std::cout << "choose option: ";
}