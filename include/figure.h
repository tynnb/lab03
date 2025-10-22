#ifndef FIGURE
#define FIGURE

#include <iostream>
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

#endif