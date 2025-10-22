#include "../include/trapezoid.h"

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

std::unique_ptr<Figure> Trapezoid::clone() const {
    return std::make_unique<Trapezoid>(*this);
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

Trapezoid::Trapezoid(Trapezoid&& other) noexcept {
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