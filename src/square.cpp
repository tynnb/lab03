#include "../include/square.h"

Square::Square(double side) {
    this->a = side;
    this->centerX = 0.0;
    this->centerY = 0.0;
}

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

std::unique_ptr<Figure> Square::clone() const {
    return std::make_unique<Square>(*this);
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

Square::Square(Square&& other) noexcept {
    a = std::move(other.a);
    centerX = std::move(other.centerX);
    centerY = std::move(other.centerY);
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
    is >> square.a;
    square.centerX = 0.0;
    square.centerY = 0.0;
    return is;
}