#include <iostream>
#include <vector>
#include <memory>
#include <limits>
#include "include/function.h"

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<std::unique_ptr<Figure>> figures;
    int choice;
    
    while (true) {
        printMenu();
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cout << "Invalid input! Please enter a number.\n";
            clearInput();
            continue;
        }
        switch (choice) {
            case 1: {
                auto square = std::make_unique<Square>();
                std::cout << "Enter 8 coordinates for square (x1 y1 x2 y2 x3 y3 x4 y4): ";
                if (!(std::cin >> *square)) {
                    std::cout << "Invalid input! Square not added.\n";
                    clearInput();
                } else {
                    figures.push_back(std::move(square));
                    std::cout << "Square added successfully!\n";
                }
                break;
            }
            case 2: {
                auto rectangle = std::make_unique<Rectangle>();
                std::cout << "Enter 8 coordinates for rectangle (x1 y1 x2 y2 x3 y3 x4 y4): ";
                if (!(std::cin >> *rectangle)) {
                    std::cout << "Invalid input! Rectangle not added.\n";
                    clearInput();
                } else {
                    figures.push_back(std::move(rectangle));
                    std::cout << "Rectangle added successfully!\n";
                }
                break;
            }
            case 3: {
                auto trapezoid = std::make_unique<Trapezoid>();
                std::cout << "Enter 8 coordinates for trapezoid (x1 y1 x2 y2 x3 y3 x4 y4): ";
                if (!(std::cin >> *trapezoid)) {
                    std::cout << "Invalid input! Trapezoid not added.\n";
                    clearInput();
                } else {
                    figures.push_back(std::move(trapezoid));
                    std::cout << "Trapezoid added successfully!\n";
                }
                break;
            }
            case 4: {
                if (figures.empty()) {
                    std::cout << "No figures in the array.\n";
                } else {
                    std::cout << "\n=== All Figures ===\n";
                    for (size_t i = 0; i < figures.size(); ++i) {
                        std::cout << "Figure " << i + 1 << ":\n";
                        std::cout << *figures[i] << std::endl;
                        
                        auto center = figures[i]->center();
                        std::cout << "Geometric center: (" 
                                  << center.first << ", " 
                                  << center.second << ")\n";
                        std::cout << "Area: " << static_cast<double>(*figures[i]) << "\n\n";
                    }
                }
                break;
            }
            case 5: {
                if (figures.empty()) {
                    std::cout << "No figures in the array.\n";
                } else {
                    double totalArea = 0.0;
                    for (const auto& figure : figures) {
                        totalArea += static_cast<double>(*figure);
                    }
                    std::cout << "Total area of all figures: " << totalArea << std::endl;
                }
                break;
            }
            case 6: {
                if (figures.empty()) {
                    std::cout << "No figures to delete.\n";
                } else {
                    std::cout << "Enter index to delete (1-" << figures.size() << "): ";
                    size_t index;
                    if (!(std::cin >> index)) {
                        std::cout << "Invalid input!\n";
                        clearInput();
                    } else if (index >= 1 && index <= figures.size()) {
                        figures.erase(figures.begin() + index - 1);
                        std::cout << "Figure deleted successfully!\n";
                    } else {
                        std::cout << "Invalid index!\n";
                    }
                }
                break;
            }
            case 7: {
                if (figures.empty()) {
                    std::cout << "No figures to copy.\n";
                } else {
                    std::cout << "Enter index to copy (1-" << figures.size() << "): ";
                    size_t index;
                    if (!(std::cin >> index)) {
                        std::cout << "Invalid input!\n";
                        clearInput();
                    } else if (index >= 1 && index <= figures.size()) {
                        auto copy_ptr = figures[index-1]->clone();
                        figures.push_back(std::move(copy_ptr));
                        std::cout << "Figure copied successfully!\n";
                    } else {
                        std::cout << "Invalid index!\n";
                    }
                }
                break;
            }
            case 8: {
                if (figures.size() < 2) {
                    std::cout << "Need at least 2 figures for comparison.\n";
                }
                else {
                    std::cout << "Enter two indices to compare (1-" << figures.size() << "): ";
                    size_t index1, index2;
                    if (!(std::cin >> index1 >> index2)) {
                        std::cout << "Invalid input!\n";
                        clearInput();
                    }
                    else if (index1 >= 1 && index1 <= figures.size() && 
                               index2 >= 1 && index2 <= figures.size()) {
                        bool are_equal = (*figures[index1-1] == *figures[index2-1]);
                        std::cout << "Figures " << index1 << " and " << index2 << " are " << (are_equal ? "EQUAL" : "DIFFERENT") << std::endl;
                    }
                    else {
                        std::cout << "Invalid indices!\n";
                    }
                }
                break;
            }
            case 0: {
                return 0;
            }
            default: {
                std::cout << "Invalid option! Please try again.\n";
                break;
            }
        }
    }
    return 0;
}