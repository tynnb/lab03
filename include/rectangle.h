#ifndef RECTANGLE
#define RECTANGLE

#include "figure.h"
#include <iostream>

class Rectangle : public Figure {
public:
    Rectangle() = default;
    Rectangle(double a, double b, double centerX, double centerY);
    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;
    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;
    bool operator==(const Rectangle& other) const;
    
    std::unique_ptr<Figure> clone() const override;
    bool equals(const Figure* other) const override;
    void printVertices(std::ostream& os) const override;
    double getCenterX() const override;
    double getCenterY() const override;
    double calculateArea() const override;
    
    friend std::istream& operator>>(std::istream& is, Rectangle& rectangle);

private:
    double a, b;
    double centerX, centerY;
};

#endif