#include <gtest/gtest.h>
#include <sstream>
#include <memory>
#include "../include/function.h"

TEST(SquareTest, ConstructorAndGetters) {
    Square square(4.0, 2.0, 3.0);
    ASSERT_DOUBLE_EQ(square.getCenterX(), 2.0);
    ASSERT_DOUBLE_EQ(square.getCenterY(), 3.0);
}

TEST(SquareTest, AreaCalculation) {
    Square square(5.0, 0.0, 0.0);
    ASSERT_DOUBLE_EQ(square.calculateArea(), 25.0);
    ASSERT_DOUBLE_EQ(static_cast<double>(square), 25.0);
}

TEST(SquareTest, InputOperator) {
    Square square;
    std::istringstream input("3.0");
    input >> square;
    
    ASSERT_DOUBLE_EQ(square.getCenterX(), 0.0);  // Центр всегда 0,0
    ASSERT_DOUBLE_EQ(square.getCenterY(), 0.0);
    ASSERT_DOUBLE_EQ(square.calculateArea(), 9.0);
}

TEST(SquareTest, OutputOperator) {
    Square square(2.0, 0.0, 0.0);
    std::ostringstream output;
    output << square;
    
    std::string result = output.str();
    ASSERT_TRUE(result.find("Square vertices:") != std::string::npos);
    ASSERT_TRUE(result.find("(1, -1)") != std::string::npos); // Проверяем конкретные координаты
}

TEST(RectangleTest, ConstructorAndGetters) {
    Rectangle rectangle(4.0, 6.0, 1.0, 2.0);
    ASSERT_DOUBLE_EQ(rectangle.getCenterX(), 1.0);
    ASSERT_DOUBLE_EQ(rectangle.getCenterY(), 2.0);
}

TEST(RectangleTest, AreaCalculation) {
    Rectangle rectangle(3.0, 7.0, 0.0, 0.0);
    ASSERT_DOUBLE_EQ(rectangle.calculateArea(), 21.0);
    ASSERT_DOUBLE_EQ(static_cast<double>(rectangle), 21.0);
}

TEST(RectangleTest, InputOperator) {
    Rectangle rectangle;
    std::istringstream input("3.0 5.0");
    input >> rectangle;
    
    ASSERT_DOUBLE_EQ(rectangle.getCenterX(), 0.0);  // Центр всегда 0,0
    ASSERT_DOUBLE_EQ(rectangle.getCenterY(), 0.0);
    ASSERT_DOUBLE_EQ(rectangle.calculateArea(), 15.0);
}

TEST(RectangleTest, OutputOperator) {
    Rectangle rectangle(3.0, 4.0, 0.0, 0.0);
    std::ostringstream output;
    output << rectangle;
    
    std::string result = output.str();
    ASSERT_TRUE(result.find("Rectangle vertices:") != std::string::npos);
}

TEST(TrapezoidTest, ConstructorAndGetters) {
    Trapezoid trapezoid(4.0, 6.0, 3.0, 1.0, 2.0);
    ASSERT_DOUBLE_EQ(trapezoid.getCenterX(), 1.0);
    ASSERT_DOUBLE_EQ(trapezoid.getCenterY(), 2.0);
}

TEST(TrapezoidTest, AreaCalculation) {
    Trapezoid trapezoid(5.0, 3.0, 4.0, 0.0, 0.0);
    ASSERT_DOUBLE_EQ(trapezoid.calculateArea(), 16.0);
    ASSERT_DOUBLE_EQ(static_cast<double>(trapezoid), 16.0);
}

TEST(TrapezoidTest, InputOperator) {
    Trapezoid trapezoid;
    std::istringstream input("4.0 6.0 3.0");
    input >> trapezoid;
    
    ASSERT_DOUBLE_EQ(trapezoid.getCenterX(), 0.0);  // Центр всегда 0,0
    ASSERT_DOUBLE_EQ(trapezoid.getCenterY(), 0.0);
    ASSERT_DOUBLE_EQ(trapezoid.calculateArea(), 15.0); // (4+6)*3/2 = 15
}

TEST(TrapezoidTest, OutputOperator) {
    Trapezoid trapezoid(2.0, 4.0, 3.0, 0.0, 0.0);
    std::ostringstream output;
    output << trapezoid;
    
    std::string result = output.str();
    ASSERT_TRUE(result.find("Trapezoid vertices:") != std::string::npos);
}

// Остальные тесты остаются без изменений
TEST(CopyMoveTest, SquareCopyConstructor) {
    Square square1(4.0, 2.0, 3.0);
    Square square2(square1);
    ASSERT_TRUE(square1 == square2);
}

TEST(CopyMoveTest, SquareMoveConstructor) {
    Square square1(4.0, 2.0, 3.0);
    Square square2(std::move(square1));
    ASSERT_DOUBLE_EQ(square2.getCenterX(), 2.0);
    ASSERT_DOUBLE_EQ(square2.getCenterY(), 3.0);
}

TEST(CopyMoveTest, SquareCopyAssignment) {
    Square square1(4.0, 2.0, 3.0);
    Square square2;
    square2 = square1;
    ASSERT_TRUE(square1 == square2);
}

TEST(CopyMoveTest, SquareMoveAssignment) {
    Square square1(4.0, 2.0, 3.0);
    Square square2;
    square2 = std::move(square1);
    ASSERT_DOUBLE_EQ(square2.getCenterX(), 2.0);
    ASSERT_DOUBLE_EQ(square2.getCenterY(), 3.0);
}

TEST(CopyMoveTest, RectangleComparison) {
    Rectangle rect1(3.0, 4.0, 1.0, 2.0);
    Rectangle rect2(3.0, 4.0, 1.0, 2.0);
    Rectangle rect3(3.0, 5.0, 1.0, 2.0);
    
    ASSERT_TRUE(rect1 == rect2);
    ASSERT_FALSE(rect1 == rect3);
}

TEST(CopyMoveTest, TrapezoidCopyOperations) {
    Trapezoid trap1(2.0, 4.0, 3.0, 1.0, 2.0);
    Trapezoid trap2 = trap1;
    Trapezoid trap3(trap1);
    
    ASSERT_TRUE(trap1 == trap2);
    ASSERT_TRUE(trap1 == trap3);
}

TEST(VirtualOperationsTest, SquareClone) {
    Square square(4.0, 2.0, 3.0);
    auto cloned = square.clone();
    ASSERT_NE(cloned.get(), nullptr);
    ASSERT_TRUE(square.equals(cloned.get()));
    ASSERT_DOUBLE_EQ(cloned->getCenterX(), 2.0);
    ASSERT_DOUBLE_EQ(cloned->getCenterY(), 3.0);
    ASSERT_DOUBLE_EQ(static_cast<double>(*cloned), 16.0);
}

TEST(VirtualOperationsTest, RectangleClone) {
    Rectangle rectangle(3.0, 5.0, 1.0, 2.0);
    auto cloned = rectangle.clone();
    ASSERT_NE(cloned.get(), nullptr);
    ASSERT_TRUE(rectangle.equals(cloned.get()));
    ASSERT_DOUBLE_EQ(cloned->getCenterX(), 1.0);
    ASSERT_DOUBLE_EQ(cloned->getCenterY(), 2.0);
    ASSERT_DOUBLE_EQ(static_cast<double>(*cloned), 15.0);
}

TEST(VirtualOperationsTest, TrapezoidClone) {
    Trapezoid trapezoid(4.0, 6.0, 3.0, 1.0, 2.0);
    auto cloned = trapezoid.clone();
    ASSERT_NE(cloned.get(), nullptr);
    ASSERT_TRUE(trapezoid.equals(cloned.get()));
    ASSERT_DOUBLE_EQ(cloned->getCenterX(), 1.0);
    ASSERT_DOUBLE_EQ(cloned->getCenterY(), 2.0);
    ASSERT_DOUBLE_EQ(static_cast<double>(*cloned), 15.0);
}

TEST(VirtualOperationsTest, SquareEquals) {
    Square square1(4.0, 2.0, 3.0);
    Square square2(4.0, 2.0, 3.0);
    Square square3(5.0, 2.0, 3.0);
    
    ASSERT_TRUE(square1.equals(&square2));
    ASSERT_FALSE(square1.equals(&square3));
}

TEST(VirtualOperationsTest, RectangleEquals) {
    Rectangle rect1(3.0, 4.0, 1.0, 2.0);
    Rectangle rect2(3.0, 4.0, 1.0, 2.0);
    Rectangle rect3(3.0, 5.0, 1.0, 2.0);
    
    ASSERT_TRUE(rect1.equals(&rect2));
    ASSERT_FALSE(rect1.equals(&rect3));
}

TEST(VirtualOperationsTest, TrapezoidEquals) {
    Trapezoid trap1(2.0, 4.0, 3.0, 1.0, 2.0);
    Trapezoid trap2(2.0, 4.0, 3.0, 1.0, 2.0);
    Trapezoid trap3(2.0, 5.0, 3.0, 1.0, 2.0);
    
    ASSERT_TRUE(trap1.equals(&trap2));
    ASSERT_FALSE(trap1.equals(&trap3));
}

TEST(VirtualOperationsTest, CrossTypeEquals) {
    Square square(4.0, 2.0, 3.0);
    Rectangle rectangle(4.0, 4.0, 2.0, 3.0);
    
    ASSERT_FALSE(square.equals(&rectangle));
    ASSERT_FALSE(rectangle.equals(&square));
}

TEST(PolymorphismTest, FigurePointers) {
    auto square = std::make_shared<Square>(2.0, 1.0, 1.0);
    auto rectangle = std::make_shared<Rectangle>(3.0, 4.0, 2.0, 2.0);
    auto trapezoid = std::make_shared<Trapezoid>(2.0, 4.0, 3.0, 3.0, 3.0);
    std::vector<std::shared_ptr<Figure>> figures = {square, rectangle, trapezoid};
    
    ASSERT_DOUBLE_EQ(static_cast<double>(*figures[0]), 4.0);
    ASSERT_DOUBLE_EQ(static_cast<double>(*figures[1]), 12.0);
    ASSERT_DOUBLE_EQ(static_cast<double>(*figures[2]), 9.0);
}

TEST(PolymorphismTest, CenterThroughBasePointer) {
    auto square = std::make_shared<Square>(2.0, 5.0, 5.0);
    auto rectangle = std::make_shared<Rectangle>(4.0, 6.0, 3.0, 3.0);
    std::shared_ptr<Figure> fig1 = square;
    std::shared_ptr<Figure> fig2 = rectangle;
    
    ASSERT_DOUBLE_EQ(fig1->getCenterX(), 5.0);
    ASSERT_DOUBLE_EQ(fig1->getCenterY(), 5.0);
    ASSERT_DOUBLE_EQ(fig2->getCenterX(), 3.0);
    ASSERT_DOUBLE_EQ(fig2->getCenterY(), 3.0);
}

TEST(ArrayTest, EmptyVector) {
    std::vector<std::shared_ptr<Figure>> figures;
    double total = 0.0;
    for (const auto& figure : figures) {
        total += static_cast<double>(*figure);
    }
    ASSERT_DOUBLE_EQ(total, 0.0);
}

TEST(ArrayTest, MultipleFiguresTotalArea) {
    auto square = std::make_shared<Square>(2.0, 0.0, 0.0);
    auto rectangle = std::make_shared<Rectangle>(3.0, 4.0, 0.0, 0.0);
    auto trapezoid = std::make_shared<Trapezoid>(2.0, 4.0, 3.0, 0.0, 0.0);
    std::vector<std::shared_ptr<Figure>> figures = {square, rectangle, trapezoid};
    double total = 0.0;
    for (const auto& figure : figures) {
        total += static_cast<double>(*figure);
    }
    ASSERT_DOUBLE_EQ(total, 25.0);
}

TEST(ConversionTest, SquareToDouble) {
    Square square(3.0, 0.0, 0.0);
    double area = static_cast<double>(square);
    ASSERT_DOUBLE_EQ(area, 9.0);
}

TEST(ConversionTest, RectangleToDouble) {
    Rectangle rectangle(2.0, 5.0, 0.0, 0.0);
    double area = static_cast<double>(rectangle);
    ASSERT_DOUBLE_EQ(area, 10.0);
}

TEST(ConversionTest, TrapezoidToDouble) {
    Trapezoid trapezoid(3.0, 5.0, 4.0, 0.0, 0.0);
    double area = static_cast<double>(trapezoid);
    ASSERT_DOUBLE_EQ(area, 16.0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}