#ifndef FUNCS
#define FUNCS

#include <iostream>
#include <vector>
#include <memory>

class Figure {
public:
    virtual ~Figure() = default;

    virtual void printVertices(std::ostream& os) const = 0;
    virtual double getCenterX() const = 0;
    virtual double getCenterY() const = 0;
    virtual double calculateArea() const = 0;

    virtual operator double() const {
        return calculateArea();
    }

    friend std::ostream& operator<<(std::ostream& os, const Figure& fig) {
        fig.printVertices(os);
        return os;
    }
};

class Square : public Figure {
public:
    Square() = default;
    Square(double a, double centerX, double centerY);

    void printVertices(std::ostream& os) const override;
    double getCenterX() const override;
    double getCenterY() const override;
    double calculateArea() const override;

    friend std::istream& operator>>(std::istream& is, Square& square);

private:
    double a;
    double centerX, centerY;
};

class Rectangle : public Figure {
public:
    Rectangle() = default;
    Rectangle(double a,double b, double centerX, double centerY);

    void printVertices(std::ostream& os) const override;
    double getCenterX() const override;
    double getCenterY() const override;
    double calculateArea() const override;

    friend std::istream& operator>>(std::istream& is, Rectangle& rectangle);

private:
    double a, b;
    double centerX, centerY;
};

class Trapezoid : public Figure {
public:
    Trapezoid() = default;
    Trapezoid(double a,double b, double h, double centerX, double centerY);

    void printVertices(std::ostream& os) const override;
    double getCenterX() const override;
    double getCenterY() const override;
    double calculateArea() const override;

    friend std::istream& operator>>(std::istream& is, Trapezoid& trapezoid);

private:
    double a, b, h;
    double centerX, centerY;
};

void printMenu();

#endif