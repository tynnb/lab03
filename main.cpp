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
                std::cout << "Square added successfully!" << std::endl;
                break;
            }
            case 2: {
                auto rectangle = std::make_unique<Rectangle>();
                std::cout << "Enter rectangle parameters (width height centerX centerY): ";
                std::cin >> *rectangle;
                figures.push_back(std::move(rectangle));
                std::cout << "Rectangle added successfully!" << std::endl;
                break;
            }
            case 3: {
                auto trapezoid = std::make_unique<Trapezoid>();
                std::cout << "Enter trapezoid parameters (base1 base2 height centerX centerY): ";
                std::cin >> *trapezoid;
                figures.push_back(std::move(trapezoid));
                std::cout << "Trapezoid added successfully!" << std::endl;
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
                        std::cout << "Figure deleted successfully!" << std::endl;
                    }
                    else {
                        std::cout << "Invalid index!" << std::endl;
                    }
                }
                break;
            }
            case 7: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid option! Please try again." << std::endl;
                break;
            }
        }
    } while (choice != 7);
    return 0;
}