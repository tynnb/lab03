#ifndef FUNCS
#define FUNCS

#include <iostream>
#include <vector>
#include <memory>

class Figure {
public:
    virtual ~Figure() = default;
    virtual std::unique_ptr<Figure> clone() const = 0;
    virtual bool equals(const Figure* other) const = 0;
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

class Rectangle : public Figure {
public:
    Rectangle() = default;
    Rectangle(double a,double b, double centerX, double centerY);
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

class Trapezoid : public Figure {
public:
    Trapezoid() = default;
    Trapezoid(double a,double b, double h, double centerX, double centerY);
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

void printMenu();

#endif