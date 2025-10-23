#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <memory>
#include <cmath>

class Figure {
public:
    virtual ~Figure() = default;
    
    virtual std::pair<double, double> center() const = 0;
    
    virtual explicit operator double() const = 0;
    
    virtual std::unique_ptr<Figure> clone() const = 0;
    virtual bool operator==(const Figure& other) const = 0;
    
    friend std::ostream& operator<<(std::ostream& os, const Figure& fig) {
        fig.printVertices(os);
        return os;
    }
    
    friend std::istream& operator>>(std::istream& is, Figure& fig) {
        fig.read(is);
        return is;
    }

protected:
    virtual void printVertices(std::ostream& os) const = 0;
    
    virtual void read(std::istream& is) = 0;
};

class Square : public Figure {
public:
    Square() = default;
    Square(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    
    Square(const Square& other);
    Square& operator=(const Square& other);
    
    Square(Square&& other) noexcept;
    Square& operator=(Square&& other) noexcept;
    
    bool operator==(const Figure& other) const override;
    bool operator==(const Square& other) const;
    
    std::pair<double, double> center() const override;
    explicit operator double() const override;
    std::unique_ptr<Figure> clone() const override;
    
    double area() const;

private:
    double x1, y1, x2, y2, x3, y3, x4, y4;
    
    void printVertices(std::ostream& os) const override;
    void read(std::istream& is) override;
    
    void calculateCenter();
    double center_x, center_y;
};

class Rectangle : public Figure {
public:
    Rectangle() = default;
    Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    
    Rectangle(Rectangle&& other) noexcept;
    Rectangle& operator=(Rectangle&& other) noexcept;
    
    bool operator==(const Figure& other) const override;
    bool operator==(const Rectangle& other) const;
    
    std::pair<double, double> center() const override;
    explicit operator double() const override;
    std::unique_ptr<Figure> clone() const override;
    
    double area() const;

private:
    double x1, y1, x2, y2, x3, y3, x4, y4;
    
    void printVertices(std::ostream& os) const override;
    void read(std::istream& is) override;
    
    void calculateCenter();
    double center_x, center_y;
};

class Trapezoid : public Figure {
public:
    Trapezoid() = default;
    Trapezoid(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    
    Trapezoid(const Trapezoid& other);
    Trapezoid& operator=(const Trapezoid& other);
    
    Trapezoid(Trapezoid&& other) noexcept;
    Trapezoid& operator=(Trapezoid&& other) noexcept;
    
    bool operator==(const Figure& other) const override;
    bool operator==(const Trapezoid& other) const;
    
    std::pair<double, double> center() const override;
    explicit operator double() const override;
    std::unique_ptr<Figure> clone() const override;
    
    double area() const;

private:
    double x1, y1, x2, y2, x3, y3, x4, y4;
    
    void printVertices(std::ostream& os) const override;
    void read(std::istream& is) override;
    
    void calculateCenter();
    double center_x, center_y;
};

void printMenu();

#endif