#include "../include/rectangle.h"

Rectangle::Rectangle(double width, double height) {
    this->a = width;
    this->b = height;
    this->centerX = 0.0;
    this->centerY = 0.0;
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

std::unique_ptr<Figure> Rectangle::clone() const {
    return std::make_unique<Rectangle>(*this);
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

Rectangle::Rectangle(Rectangle&& other) noexcept {
    a = std::move(other.a);
    b = std::move(other.b);
    centerX = std::move(other.centerX);
    centerY = std::move(other.centerY);
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
    is >> rectangle.a >> rectangle.b;
    rectangle.centerX = 0.0;
    rectangle.centerY = 0.0;
    return is;
}