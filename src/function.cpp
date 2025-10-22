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
    std::cout << "\nMenu" << std::endl;
    std::cout << "1. Add Square" << std::endl;
    std::cout << "2. Add Rectangle" << std::endl;
    std::cout << "3. Add Trapezoid" << std::endl;
    std::cout << "4. Print all figures" << std::endl;
    std::cout << "5. Calculate total area" << std::endl;
    std::cout << "6. Delete figure by index" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "Choose option: ";
}