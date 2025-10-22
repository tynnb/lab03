#include "include/function.h"

int main() {
    std::vector<std::unique_ptr<Figure>> figures;
    int choice;
    do {
        printMenu();
        std::cin >> choice;
        switch (choice) {
            case 1: {
                auto square = std::make_unique<Square>();
                std::cout << "Enter square parameters (side centerX centerY): ";
                std::cin >> *square;
                figures.push_back(std::move(square));
                break;
            }
            case 2: {
                auto rectangle = std::make_unique<Rectangle>();
                std::cout << "Enter rectangle parameters (width height centerX centerY): ";
                std::cin >> *rectangle;
                figures.push_back(std::move(rectangle));
                break;
            }
            case 3: {
                auto trapezoid = std::make_unique<Trapezoid>();
                std::cout << "Enter trapezoid parameters (base1 base2 height centerX centerY): ";
                std::cin >> *trapezoid;
                figures.push_back(std::move(trapezoid));
                break;
            }
            case 4: {
                if (figures.empty()) {
                    std::cout << "No figures in the array." << std::endl;
                }
                else {
                    std::cout << "\n=== All Figures ===" << std::endl;
                    for (size_t i = 0; i < figures.size(); ++i) {
                        std::cout << "Figure " << i + 1 << ":" << std::endl;
                        std::cout << *figures[i] << std::endl;
                        std::cout << "Geometric center: (" 
                                  << figures[i]->getCenterX() << ", " 
                                  << figures[i]->getCenterY() << ")" << std::endl;
                        std::cout << "Area: " << static_cast<double>(*figures[i]) << std::endl;
                    }
                }
                break;
            }
            case 5: {
                double totalArea = 0.0;
                for (const auto& figure : figures) {
                    totalArea += static_cast<double>(*figure);
                }
                std::cout << "Total area of all figures: " << totalArea << std::endl;
                break;
            }
            case 6: {
                if (figures.empty()) {
                    std::cout << "No figures to delete." << std::endl;
                }
                else {
                    std::cout << "Enter index to delete (1-" << figures.size() << "): ";
                    size_t index;
                    std::cin >> index;
                    if (index >= 1 && index <= figures.size()) {
                        figures.erase(figures.begin() + index - 1);
                    }
                    else {
                        std::cout << "Invalid index" << std::endl;
                    }
                }
                break;
            }
            case 7: {
                if (figures.empty()) {
                    std::cout << "No figures to copy." << std::endl;
                }
                else {
                    std::cout << "Enter index to copy (1-" << figures.size() << "): ";
                    size_t index;
                    std::cin >> index;
                    if (index >= 1 && index <= figures.size()) {
                        auto copied_figure = figures[index-1]->clone();
                        figures.push_back(std::move(copied_figure));
                    }
                    else {
                        std::cout << "Invalid index" << std::endl;
                    }
                }
                break;
            }
            case 8: {
                if (figures.size() < 2) {
                    std::cout << "Need at least 2 figures for comparison." << std::endl;
                }
                else {
                    std::cout << "Enter two indices to compare (1-" << figures.size() << "): ";
                    size_t index1, index2;
                    std::cin >> index1 >> index2;
                    if (index1 >= 1 && index1 <= figures.size() && 
                        index2 >= 1 && index2 <= figures.size()) {
                        bool are_equal = figures[index1-1]->equals(figures[index2-1].get());
                        std::cout << "Figures " << index1 << " and " << index2 
                                  << " are " << (are_equal ? "EQUAL" : "DIFFERENT") << std::endl;
                    }
                    else {
                        std::cout << "Invalid indices" << std::endl;
                    }
                }
                break;
            }
            case 9: {
                if (figures.empty()) {
                    std::cout << "No figures to move." << std::endl;
                }
                else {
                    Square square(5.0, 1.0, 2.0);
                    std::cout << "Original square area: " << static_cast<double>(square) << std::endl;
                    Square moved_square(std::move(square));
                    std::cout << "After move constructor - moved square area: " << static_cast<double>(moved_square) << std::endl;
                    Square another_square;
                    another_square = std::move(moved_square);
                    std::cout << "After move assignment - another square area: " << static_cast<double>(another_square) << std::endl;
                }
                break;
            }
            case 0: {
                break;
            }
            default: {
                std::cout << "Invalid option" << std::endl;
                break;
            }
        }
    } while (choice != 0);
    return 0;
}