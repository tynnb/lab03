#include "../include/function.h"

Square::Square(double a, double centerX, double centerY) {
    this->a = a;
    this->centerX = centerX;
    this->centerY = centerY;
}

void Square::printVertices(std::ostream& os) const {
    double half = a / 2.0;
    os << "Square vertices: ";
    os << "(" << centerX - half << ", " << centerY - half << "), ";
    os << "(" << centerX + half << ", " << centerY - half << "), ";
    os << "(" << centerX + half << ", " << centerY + half << "), ";
    os << "(" << centerX - half << ", " << centerY + half << ")";
}

Figure* Square::clone() const {
    return new Square(*this);
}

bool Square::equals(const Figure* other) const {
    const Square* square = dynamic_cast<const Square*>(other);
    if (square == nullptr) return false;
    return (a == square->a && centerX == square->centerX && centerY == square->centerY);
}

Square::Square(const Square& other) {
    a = other.a;
    centerX = other.centerX;
    centerY = other.centerY;
}

Square& Square::operator=(const Square& other) {
    if (this != &other) {
        a = other.a;
        centerX = other.centerX;
        centerY = other.centerY;
    }
    return *this;
}

bool Square::operator==(const Square& other) const {
    return (a == other.a && centerX == other.centerX && centerY == other.centerY);
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

Rectangle::Rectangle(double a, double b, double centerX, double centerY) {
    this->a = a;
    this->b = b;
    this->centerX = centerX;
    this->centerY = centerY;
}

void Rectangle::printVertices(std::ostream& os) const {
    double half1 = a / 2.0;
    double half2 = b / 2.0;
    os << "Rectangle vertices: ";
    os << "(" << centerX - half1 << ", " << centerY - half2 << "), ";
    os << "(" << centerX + half1 << ", " << centerY - half2 << "), ";
    os << "(" << centerX + half1 << ", " << centerY + half2 << "), ";
    os << "(" << centerX - half1 << ", " << centerY + half2 << ")";
}

Figure* Rectangle::clone() const {
    return new Rectangle(*this);
}

bool Rectangle::equals(const Figure* other) const {
    const Rectangle* rectangle = dynamic_cast<const Rectangle*>(other);
    if (rectangle == nullptr) return false;
    return (a == rectangle->a && b == rectangle->b && 
            centerX == rectangle->centerX && centerY == rectangle->centerY);
}

Rectangle::Rectangle(const Rectangle& other) {
    a = other.a;
    b = other.b;
    centerX = other.centerX;
    centerY = other.centerY;
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

bool Rectangle::operator==(const Rectangle& other) const {
    return (a == other.a && b == other.b && 
            centerX == other.centerX && centerY == other.centerY);
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

Trapezoid::Trapezoid(double a, double b, double h, double centerX, double centerY) {
    this->a = a;
    this->b = b;
    this->h = h;
    this->centerX = centerX;
    this->centerY = centerY;
}

void Trapezoid::printVertices(std::ostream& os) const {
    double half1 = a / 2.0;
    double half2 = b / 2.0;
    double half3 = h / 2.0;
    os << "Trapezoid vertices: ";
    os << "(" << centerX - half1 << ", " << centerY - half3 << "), ";
    os << "(" << centerX + half1 << ", " << centerY - half3 << "), ";
    os << "(" << centerX + half2 << ", " << centerY + half3 << "), ";
    os << "(" << centerX - half2 << ", " << centerY + half3 << ")";
}

Figure* Trapezoid::clone() const {
    return new Trapezoid(*this);
}

bool Trapezoid::equals(const Figure* other) const {
    const Trapezoid* trapezoid = dynamic_cast<const Trapezoid*>(other);
    if (trapezoid == nullptr) return false;
    return (a == trapezoid->a && b == trapezoid->b && h == trapezoid->h &&
            centerX == trapezoid->centerX && centerY == trapezoid->centerY);
}

Trapezoid::Trapezoid(const Trapezoid& other) {
    a = other.a;
    b = other.b;
    h = other.h;
    centerX = other.centerX;
    centerY = other.centerY;
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

bool Trapezoid::operator==(const Trapezoid& other) const {
    return (a == other.a && b == other.b && h == other.h &&
            centerX == other.centerX && centerY == other.centerY);
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
    std::cout << "1. Add square" << std::endl;
    std::cout << "2. Add rectangle" << std::endl;
    std::cout << "3. Add trapezoid" << std::endl;
    std::cout << "4. Print all figures" << std::endl;
    std::cout << "5. Calculate total area" << std::endl;
    std::cout << "6. Delete figure by index" << std::endl;
    std::cout << "7. Copy figure" << std::endl;
    std::cout << "8. Compare figures" << std::endl;
    std::cout << "9. Show move operations" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Choose: ";
}