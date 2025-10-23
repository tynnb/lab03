#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include <cmath>
#include <sstream>
#include "../include/function.h"

// Вспомогательная функция для сравнения double с допуском
bool doubleEquals(double a, double b, double epsilon = 1e-9) {
    return std::abs(a - b) < epsilon;
}

// Вспомогательная функция для сравнения пар координат
bool pairEquals(const std::pair<double, double>& a, 
                const std::pair<double, double>& b, 
                double epsilon = 1e-9) {
    return doubleEquals(a.first, b.first, epsilon) && 
           doubleEquals(a.second, b.second, epsilon);
}

class SquareTest : public ::testing::Test {
protected:
    void SetUp() override {
        square = new Square(0, 0, 1, 0, 1, 1, 0, 1);
    }

    void TearDown() override {
        delete square;
    }

    Square* square;
};

TEST_F(SquareTest, ConstructorAndCoordinates) {
    ASSERT_NE(square, nullptr);
    
    // Проверяем, что площадь вычисляется корректно
    EXPECT_NEAR(static_cast<double>(*square), 1.0, 1e-9);
}

TEST_F(SquareTest, CenterCalculation) {
    auto center = square->center();
    EXPECT_NEAR(center.first, 0.5, 1e-9);
    EXPECT_NEAR(center.second, 0.5, 1e-9);
}

TEST_F(SquareTest, AreaCalculation) {
    double area = square->area();
    EXPECT_NEAR(area, 1.0, 1e-9);
}

TEST_F(SquareTest, CloneOperation) {
    Figure* cloned = square->clone();
    ASSERT_NE(cloned, nullptr);
    
    // Проверяем, что клон имеет те же координаты
    Square* clonedSquare = dynamic_cast<Square*>(cloned);
    ASSERT_NE(clonedSquare, nullptr);
    
    auto originalCenter = square->center();
    auto clonedCenter = clonedSquare->center();
    EXPECT_TRUE(pairEquals(originalCenter, clonedCenter));
    
    EXPECT_NEAR(static_cast<double>(*square), static_cast<double>(*clonedSquare), 1e-9);
    
    delete cloned;
}

TEST_F(SquareTest, EqualityOperator) {
    Square* sameSquare = new Square(0, 0, 1, 0, 1, 1, 0, 1);
    Square* differentSquare = new Square(0, 0, 2, 0, 2, 2, 0, 2);
    
    EXPECT_TRUE(*square == *sameSquare);
    EXPECT_FALSE(*square == *differentSquare);
    
    delete sameSquare;
    delete differentSquare;
}

TEST_F(SquareTest, InputOutputOperations) {
    std::ostringstream oss;
    oss << *square;
    
    std::string output = oss.str();
    EXPECT_TRUE(output.find("Square vertices") != std::string::npos);
    EXPECT_TRUE(output.find("(0, 0)") != std::string::npos);
    
    Square* newSquare = new Square();
    std::istringstream iss("0 0 1 0 1 1 0 1");
    iss >> *newSquare;
    
    EXPECT_TRUE(*square == *newSquare);
    delete newSquare;
}

class RectangleTest : public ::testing::Test {
protected:
    void SetUp() override {
        rectangle = new Rectangle(0, 0, 2, 0, 2, 1, 0, 1);
    }

    void TearDown() override {
        delete rectangle;
    }

    Rectangle* rectangle;
};

TEST_F(RectangleTest, ConstructorAndCoordinates) {
    ASSERT_NE(rectangle, nullptr);
    EXPECT_NEAR(static_cast<double>(*rectangle), 2.0, 1e-9);
}

TEST_F(RectangleTest, CenterCalculation) {
    auto center = rectangle->center();
    EXPECT_NEAR(center.first, 1.0, 1e-9);
    EXPECT_NEAR(center.second, 0.5, 1e-9);
}

TEST_F(RectangleTest, AreaCalculation) {
    double area = rectangle->area();
    EXPECT_NEAR(area, 2.0, 1e-9);
}

TEST_F(RectangleTest, CloneOperation) {
    Figure* cloned = rectangle->clone();
    ASSERT_NE(cloned, nullptr);
    
    Rectangle* clonedRect = dynamic_cast<Rectangle*>(cloned);
    ASSERT_NE(clonedRect, nullptr);
    
    auto originalCenter = rectangle->center();
    auto clonedCenter = clonedRect->center();
    EXPECT_TRUE(pairEquals(originalCenter, clonedCenter));
    
    EXPECT_NEAR(static_cast<double>(*rectangle), static_cast<double>(*clonedRect), 1e-9);
    
    delete cloned;
}

TEST_F(RectangleTest, EqualityOperator) {
    Rectangle* sameRect = new Rectangle(0, 0, 2, 0, 2, 1, 0, 1);
    Rectangle* differentRect = new Rectangle(0, 0, 3, 0, 3, 1, 0, 1);
    
    EXPECT_TRUE(*rectangle == *sameRect);
    EXPECT_FALSE(*rectangle == *differentRect);
    
    delete sameRect;
    delete differentRect;
}

class TrapezoidTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Трапеция с основаниями y=0 и y=1, высотой 1
        trapezoid = new Trapezoid(0, 0, 1, 0, 0.5, 1, 0, 1);
    }

    void TearDown() override {
        delete trapezoid;
    }

    Trapezoid* trapezoid;
};

TEST_F(TrapezoidTest, ConstructorAndCoordinates) {
    ASSERT_NE(trapezoid, nullptr);
}

TEST_F(TrapezoidTest, CenterCalculation) {
    auto center = trapezoid->center();
    // Центр трапеции
    EXPECT_NEAR(center.first, 0.375, 1e-9);
    EXPECT_NEAR(center.second, 0.5, 1e-9);
}

TEST_F(TrapezoidTest, AreaCalculation) {
    double area = trapezoid->area();
    // Площадь трапеции: (a + b) * h / 2 = (1 + 0.5) * 1 / 2 = 0.75
    EXPECT_NEAR(area, 0.75, 1e-9);
}

TEST_F(TrapezoidTest, CloneOperation) {
    Figure* cloned = trapezoid->clone();
    ASSERT_NE(cloned, nullptr);
    
    Trapezoid* clonedTrap = dynamic_cast<Trapezoid*>(cloned);
    ASSERT_NE(clonedTrap, nullptr);
    
    auto originalCenter = trapezoid->center();
    auto clonedCenter = clonedTrap->center();
    EXPECT_TRUE(pairEquals(originalCenter, clonedCenter));
    
    delete cloned;
}

TEST_F(TrapezoidTest, EqualityOperator) {
    Trapezoid* sameTrap = new Trapezoid(0, 0, 1, 0, 0.5, 1, 0, 1);
    Trapezoid* differentTrap = new Trapezoid(0, 0, 2, 0, 1, 1, 0, 1);
    
    EXPECT_TRUE(*trapezoid == *sameTrap);
    EXPECT_FALSE(*trapezoid == *differentTrap);
    
    delete sameTrap;
    delete differentTrap;
}

class FigurePolymorphismTest : public ::testing::Test {
protected:
    void SetUp() override {
        figures.push_back(new Square(0, 0, 1, 0, 1, 1, 0, 1));
        figures.push_back(new Rectangle(0, 0, 2, 0, 2, 1, 0, 1));
        figures.push_back(new Trapezoid(0, 0, 1, 0, 0.5, 1, 0, 1));
    }

    void TearDown() override {
        for (auto figure : figures) {
            delete figure;
        }
        figures.clear();
        
        for (auto clone : clones) {
            delete clone;
        }
        clones.clear();
    }

    std::vector<Figure*> figures;
    std::vector<Figure*> clones;
};

TEST_F(FigurePolymorphismTest, PolymorphicCenter) {
    for (Figure* figure : figures) {
        auto center = figure->center();
        ASSERT_NE(center.first, 0.0);
        ASSERT_NE(center.second, 0.0);
    }
}

TEST_F(FigurePolymorphismTest, PolymorphicArea) {
    for (Figure* figure : figures) {
        double area = static_cast<double>(*figure);
        EXPECT_GT(area, 0.0);
    }
}

TEST_F(FigurePolymorphismTest, PolymorphicClone) {
    for (Figure* figure : figures) {
        Figure* cloned = figure->clone();
        ASSERT_NE(cloned, nullptr);
        clones.push_back(cloned);
        
        // Проверяем, что клон имеет ту же площадь
        EXPECT_NEAR(static_cast<double>(*figure), static_cast<double>(*cloned), 1e-9);
    }
}

// Исправленный тест для сравнения разных типов фигур
TEST_F(FigurePolymorphismTest, CrossTypeComparison) {
    Square square(0, 0, 1, 0, 1, 1, 0, 1);
    Rectangle rectangle(0, 0, 2, 0, 2, 1, 0, 1);
    
    // Явно приводим к Figure& чтобы избежать неоднозначности
    const Figure& squareRef = square;
    const Figure& rectangleRef = rectangle;
    
    // Квадрат и прямоугольник не должны быть равны
    EXPECT_FALSE(squareRef == rectangleRef);
    EXPECT_FALSE(rectangleRef == squareRef);
}

// Тест для проверки сравнения с разными типами через dynamic_cast
TEST(CrossTypeComparisonTest, DifferentTypes) {
    Square square(0, 0, 1, 0, 1, 1, 0, 1);
    Rectangle rectangle(0, 0, 2, 0, 2, 1, 0, 1);
    Trapezoid trapezoid(0, 0, 1, 0, 0.5, 1, 0, 1);
    
    // Все фигуры разных типов, поэтому не должны быть равны
    EXPECT_FALSE(square == static_cast<const Figure&>(rectangle));
    EXPECT_FALSE(rectangle == static_cast<const Figure&>(square));
    EXPECT_FALSE(trapezoid == static_cast<const Figure&>(square));
    EXPECT_FALSE(square == static_cast<const Figure&>(trapezoid));
}

TEST(CloneTest, PolymorphicClone) {
    std::vector<Figure*> figures;
    std::vector<Figure*> clones;
    
    figures.push_back(new Square(0, 0, 1, 0, 1, 1, 0, 1));
    figures.push_back(new Rectangle(0, 0, 2, 0, 2, 1, 0, 1));
    figures.push_back(new Trapezoid(0, 0, 1, 0, 0.5, 1, 0, 1));
    
    for (Figure* figure : figures) {
        Figure* cloned = figure->clone();
        ASSERT_NE(cloned, nullptr);
        clones.push_back(cloned);
        
        // Проверяем полиморфное поведение
        EXPECT_NEAR(static_cast<double>(*figure), static_cast<double>(*cloned), 1e-9);
    }
    
    // Очистка памяти
    for (auto figure : figures) {
        delete figure;
    }
    for (auto clone : clones) {
        delete clone;
    }
}

// Тест для проверки работы оператора ввода с некорректными данными
TEST(InputTest, InvalidInput) {
    Square square;
    std::istringstream iss("invalid data");
    
    // Должен установить failbit при некорректном вводе
    iss >> square;
    EXPECT_TRUE(iss.fail());
}

// Тест для проверки геометрического центра
TEST(CenterTest, GeometricCenter) {
    Square square(0, 0, 2, 0, 2, 2, 0, 2);
    auto center = square.center();
    
    // Центр квадрата 2x2 должен быть в (1, 1)
    EXPECT_NEAR(center.first, 1.0, 1e-9);
    EXPECT_NEAR(center.second, 1.0, 1e-9);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}