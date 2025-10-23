#include <gtest/gtest.h>
#include <sstream>
#include <memory>
#include "../include/function.h"

// Тесты для Square
TEST(SquareTest, ConstructorAndArea) {
    Square square(0, 0, 2, 0, 2, 2, 0, 2);
    ASSERT_DOUBLE_EQ(static_cast<double>(square), 4.0);
}

TEST(SquareTest, CenterCalculation) {
    Square square(0, 0, 4, 0, 4, 4, 0, 4);
    auto center = square.center();
    ASSERT_DOUBLE_EQ(center.first, 2.0);
    ASSERT_DOUBLE_EQ(center.second, 2.0);
}

TEST(SquareTest, InputOperator) {
    Square square;
    std::istringstream input("0 0 3 0 3 3 0 3");
    input >> square;
    
    auto center = square.center();
    ASSERT_DOUBLE_EQ(center.first, 1.5);
    ASSERT_DOUBLE_EQ(center.second, 1.5);
    ASSERT_DOUBLE_EQ(static_cast<double>(square), 9.0);
}

TEST(SquareTest, OutputOperator) {
    Square square(1, 1, 3, 1, 3, 3, 1, 3);
    std::ostringstream output;
    output << square;
    
    std::string result = output.str();
    ASSERT_TRUE(result.find("Square vertices:") != std::string::npos);
    ASSERT_TRUE(result.find("(1, 1)") != std::string::npos);
}

TEST(SquareTest, CloneOperation) {
    Square square(0, 0, 2, 0, 2, 2, 0, 2);
    auto cloned = square.clone();
    ASSERT_NE(cloned.get(), nullptr);
    ASSERT_DOUBLE_EQ(static_cast<double>(*cloned), 4.0);
    ASSERT_TRUE(square == *cloned);
}

// Тесты для Rectangle
TEST(RectangleTest, ConstructorAndArea) {
    Rectangle rectangle(0, 0, 5, 0, 5, 3, 0, 3);
    ASSERT_DOUBLE_EQ(static_cast<double>(rectangle), 15.0);
}

TEST(RectangleTest, CenterCalculation) {
    Rectangle rectangle(0, 0, 6, 0, 6, 4, 0, 4);
    auto center = rectangle.center();
    ASSERT_DOUBLE_EQ(center.first, 3.0);
    ASSERT_DOUBLE_EQ(center.second, 2.0);
}

TEST(RectangleTest, InputOperator) {
    Rectangle rectangle;
    std::istringstream input("0 0 4 0 4 2 0 2");
    input >> rectangle;
    
    auto center = rectangle.center();
    ASSERT_DOUBLE_EQ(center.first, 2.0);
    ASSERT_DOUBLE_EQ(center.second, 1.0);
    ASSERT_DOUBLE_EQ(static_cast<double>(rectangle), 8.0);
}

TEST(RectangleTest, OutputOperator) {
    Rectangle rectangle(0, 0, 3, 0, 3, 2, 0, 2);
    std::ostringstream output;
    output << rectangle;
    
    std::string result = output.str();
    ASSERT_TRUE(result.find("Rectangle vertices:") != std::string::npos);
}

TEST(RectangleTest, CloneOperation) {
    Rectangle rectangle(0, 0, 4, 0, 4, 2, 0, 2);
    auto cloned = rectangle.clone();
    ASSERT_NE(cloned.get(), nullptr);
    ASSERT_DOUBLE_EQ(static_cast<double>(*cloned), 8.0);
    ASSERT_TRUE(rectangle == *cloned);
}

// Тесты для Trapezoid
TEST(TrapezoidTest, ConstructorAndArea) {
    Trapezoid trapezoid(0, 0, 6, 0, 4, 3, 2, 3);
    double expected_area = std::abs((0*0 + 6*3 + 4*3 + 2*0) - (0*6 + 0*4 + 3*2 + 3*0)) / 2.0;
    ASSERT_DOUBLE_EQ(static_cast<double>(trapezoid), expected_area);
}

TEST(TrapezoidTest, CenterCalculation) {
    Trapezoid trapezoid(0, 0, 8, 0, 6, 4, 2, 4);
    auto center = trapezoid.center();
    ASSERT_DOUBLE_EQ(center.first, 4.0);
    ASSERT_DOUBLE_EQ(center.second, 2.0);
}

TEST(TrapezoidTest, InputOperator) {
    Trapezoid trapezoid;
    std::istringstream input("0 0 5 0 4 2 1 2");
    input >> trapezoid;
    
    auto center = trapezoid.center();
    ASSERT_DOUBLE_EQ(center.first, 2.5);
    ASSERT_DOUBLE_EQ(center.second, 1.0);
}

TEST(TrapezoidTest, OutputOperator) {
    Trapezoid trapezoid(0, 0, 4, 0, 3, 2, 1, 2);
    std::ostringstream output;
    output << trapezoid;
    
    std::string result = output.str();
    ASSERT_TRUE(result.find("Trapezoid vertices:") != std::string::npos);
}

// Тесты операций копирования и перемещения
TEST(CopyMoveTest, SquareCopyOperations) {
    Square square1(0, 0, 2, 0, 2, 2, 0, 2);
    Square square2 = square1;
    Square square3(square1);
    
    auto center1 = square1.center();
    auto center2 = square2.center();
    auto center3 = square3.center();
    
    ASSERT_DOUBLE_EQ(center1.first, center2.first);
    ASSERT_DOUBLE_EQ(center1.second, center2.second);
    ASSERT_DOUBLE_EQ(static_cast<double>(square1), static_cast<double>(square2));
    
    ASSERT_DOUBLE_EQ(center1.first, center3.first);
    ASSERT_DOUBLE_EQ(center1.second, center3.second);
    ASSERT_DOUBLE_EQ(static_cast<double>(square1), static_cast<double>(square3));
}

TEST(CopyMoveTest, SquareMoveOperations) {
    Square square1(0, 0, 3, 0, 3, 3, 0, 3);
    Square square2(std::move(square1));
    ASSERT_DOUBLE_EQ(static_cast<double>(square2), 9.0);
    
    Square square3;
    square3 = std::move(square2);
    ASSERT_DOUBLE_EQ(static_cast<double>(square3), 9.0);
}

// Тесты операций сравнения
TEST(ComparisonTest, SquareComparison) {
    Square square1(0, 0, 2, 0, 2, 2, 0, 2);
    Square square2(0, 0, 2, 0, 2, 2, 0, 2);
    Square square3(1, 1, 3, 1, 3, 3, 1, 3);
    
    ASSERT_TRUE(square1 == square2);
    ASSERT_FALSE(square1 == square3);
}

TEST(ComparisonTest, CrossTypeComparison) {
    Square square(0, 0, 2, 0, 2, 2, 0, 2);
    Rectangle rectangle(0, 0, 2, 0, 2, 2, 0, 2);
    
    // Явное преобразование к Figure& для избежания неоднозначности
    const Figure& fig1 = square;
    const Figure& fig2 = rectangle;
    
    ASSERT_FALSE(fig1 == fig2);
    ASSERT_FALSE(fig2 == fig1);
}

// Тесты полиморфизма
TEST(PolymorphismTest, FigurePointers) {
    auto square = std::make_unique<Square>(0, 0, 2, 0, 2, 2, 0, 2);
    auto rectangle = std::make_unique<Rectangle>(0, 0, 3, 0, 3, 4, 0, 4);
    
    std::vector<std::unique_ptr<Figure>> figures;
    figures.push_back(std::move(square));
    figures.push_back(std::move(rectangle));
    
    ASSERT_DOUBLE_EQ(static_cast<double>(*figures[0]), 4.0);
    ASSERT_DOUBLE_EQ(static_cast<double>(*figures[1]), 12.0);
}

TEST(PolymorphismTest, CenterThroughBasePointer) {
    auto square = std::make_unique<Square>(0, 0, 4, 0, 4, 4, 0, 4);
    auto rectangle = std::make_unique<Rectangle>(0, 0, 6, 0, 6, 4, 0, 4);
    
    std::unique_ptr<Figure> fig1 = std::move(square);
    std::unique_ptr<Figure> fig2 = std::move(rectangle);
    
    auto center1 = fig1->center();
    auto center2 = fig2->center();
    
    ASSERT_DOUBLE_EQ(center1.first, 2.0);
    ASSERT_DOUBLE_EQ(center1.second, 2.0);
    ASSERT_DOUBLE_EQ(center2.first, 3.0);
    ASSERT_DOUBLE_EQ(center2.second, 2.0);
}

// Тесты для работы с массивом фигур
TEST(FigureArrayTest, TotalAreaCalculation) {
    std::vector<std::unique_ptr<Figure>> figures;
    
    figures.push_back(std::make_unique<Square>(0, 0, 2, 0, 2, 2, 0, 2));
    figures.push_back(std::make_unique<Rectangle>(0, 0, 3, 0, 3, 4, 0, 4));
    figures.push_back(std::make_unique<Trapezoid>(0, 0, 4, 0, 3, 2, 1, 2));
    
    double total = 0.0;
    for (const auto& figure : figures) {
        total += static_cast<double>(*figure);
    }
    
    ASSERT_DOUBLE_EQ(total, 4.0 + 12.0 + static_cast<double>(*figures[2]));
}

// Тесты преобразования типов
TEST(ConversionTest, DoubleConversion) {
    Square square(0, 0, 5, 0, 5, 5, 0, 5);
    double area = static_cast<double>(square);
    ASSERT_DOUBLE_EQ(area, 25.0);
    
    Rectangle rectangle(0, 0, 6, 0, 6, 7, 0, 7);
    area = static_cast<double>(rectangle);
    ASSERT_DOUBLE_EQ(area, 42.0);
}

// Тесты потокового ввода/вывода
TEST(StreamTest, SquareStreamOperations) {
    Square square;
    std::istringstream input("0 0 4 0 4 4 0 4");
    input >> square;
    
    std::ostringstream output;
    output << square;
    
    std::string result = output.str();
    ASSERT_TRUE(result.find("(0, 0)") != std::string::npos);
    ASSERT_DOUBLE_EQ(static_cast<double>(square), 16.0);
}

TEST(StreamTest, PrintCentersAndAreas) {
    std::vector<std::unique_ptr<Figure>> figures;
    figures.push_back(std::make_unique<Square>(0, 0, 2, 0, 2, 2, 0, 2));
    figures.push_back(std::make_unique<Rectangle>(0, 0, 4, 0, 4, 3, 0, 3));
    
    testing::internal::CaptureStdout();
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Figure " << i + 1 << ":\n";
        std::cout << *figures[i] << std::endl;
        auto center = figures[i]->center();
        std::cout << "Center: (" << center.first << ", " << center.second << ")\n";
        std::cout << "Area: " << static_cast<double>(*figures[i]) << "\n\n";
    }
    std::string output = testing::internal::GetCapturedStdout();
    
    ASSERT_TRUE(output.find("Center") != std::string::npos);
    ASSERT_TRUE(output.find("Area") != std::string::npos);
}

// Тесты для операций копирования через clone
TEST(CloneTest, PolymorphicClone) {
    auto square = std::make_unique<Square>(0, 0, 3, 0, 3, 3, 0, 3);
    auto rectangle = std::make_unique<Rectangle>(0, 0, 4, 0, 4, 2, 0, 2);
    
    std::vector<std::unique_ptr<Figure>> figures;
    figures.push_back(std::move(square));
    figures.push_back(std::move(rectangle));
    
    std::vector<std::unique_ptr<Figure>> clones;
    for (const auto& figure : figures) {
        clones.push_back(figure->clone());
    }
    
    for (size_t i = 0; i < figures.size(); ++i) {
        ASSERT_TRUE(*figures[i] == *clones[i]);
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}