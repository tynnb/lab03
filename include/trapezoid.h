#ifndef TRAPEZOID
#define TRAPEZOID

#include "figure.h"
#include <iostream>

class Trapezoid : public Figure {
public:
    Trapezoid() = default;
    Trapezoid(double a, double b, double h, double centerX, double centerY);
    Trapezoid(const Trapezoid& other);
    Trapezoid(Trapezoid&& other) noexcept;
    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid& operator=(Trapezoid&& other) noexcept;
    bool operator==(const Trapezoid& other) const;
    
    std::unique_ptr<Figure> clone() const override;
    bool equals(const Figure* other) const override;
    void printVertices(std::ostream& os) const override;
    double getCenterX() const override;
    double getCenterY() const override;
    double calculateArea() const override;
    
    friend std::istream& operator>>(std::istream& is, Trapezoid& trapezoid);

private:
    double a, b, h;
    double centerX, centerY;
};

#endif