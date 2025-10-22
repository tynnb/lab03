#ifndef SQUARE
#define SQUARE

#include "figure.h"
#include <iostream>

class Square : public Figure {
public:
    Square() = default;
    Square(double side);
    Square(double a, double centerX, double centerY);
    Square(const Square& other);
    Square(Square&& other) noexcept;
    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;
    bool operator==(const Square& other) const;
    
    std::unique_ptr<Figure> clone() const override;
    bool equals(const Figure* other) const override;
    void printVertices(std::ostream& os) const override;
    double getCenterX() const override;
    double getCenterY() const override;
    double calculateArea() const override;
    
    friend std::istream& operator>>(std::istream& is, Square& square);

private:
    double a;
    double centerX, centerY;
};

#endif