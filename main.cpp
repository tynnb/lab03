#include <iostream>
#include <limits>
#include <array>
#include "include/function.h"

const size_t MAX_FIGURES = 100;

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::array<Figure*, MAX_FIGURES> figures{nullptr};
    size_t figuresCount = 0;
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
                if (figuresCount >= MAX_FIGURES) {
                    std::cout << "Maximum number of figures reached (" << MAX_FIGURES << ")!\n";
                    break;
                }
                Square* square = new Square();
                std::cout << "Enter 8 coordinates for square (x1 y1 x2 y2 x3 y3 x4 y4): ";
                if (!(std::cin >> *square)) {
                    std::cout << "Invalid input! Square not added.\n";
                    delete square;
                    clearInput();
                } else {
                    figures[figuresCount] = square;
                    figuresCount++;
                    std::cout << "Square added successfully! Total figures: " << figuresCount << "\n";
                }
                break;
            }
            case 2: {
                if (figuresCount >= MAX_FIGURES) {
                    std::cout << "Maximum number of figures reached (" << MAX_FIGURES << ")!\n";
                    break;
                }
                Rectangle* rectangle = new Rectangle();
                std::cout << "Enter 8 coordinates for rectangle (x1 y1 x2 y2 x3 y3 x4 y4): ";
                if (!(std::cin >> *rectangle)) {
                    std::cout << "Invalid input! Rectangle not added.\n";
                    delete rectangle;
                    clearInput();
                } else {
                    figures[figuresCount] = rectangle;
                    figuresCount++;
                    std::cout << "Rectangle added successfully! Total figures: " << figuresCount << "\n";
                }
                break;
            }
            case 3: {
                if (figuresCount >= MAX_FIGURES) {
                    std::cout << "Maximum number of figures reached (" << MAX_FIGURES << ")!\n";
                    break;
                }
                Trapezoid* trapezoid = new Trapezoid();
                std::cout << "Enter 8 coordinates for trapezoid (x1 y1 x2 y2 x3 y3 x4 y4): ";
                if (!(std::cin >> *trapezoid)) {
                    std::cout << "Invalid input! Trapezoid not added.\n";
                    delete trapezoid;
                    clearInput();
                } else {
                    figures[figuresCount] = trapezoid;
                    figuresCount++;
                    std::cout << "Trapezoid added successfully! Total figures: " << figuresCount << "\n";
                }
                break;
            }
            case 4: {
                if (figuresCount == 0) {
                    std::cout << "No figures in the array.\n";
                } else {
                    std::cout << "\n=== All Figures (" << figuresCount << " total) ===\n";
                    for (size_t i = 0; i < figuresCount; ++i) {
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
                if (figuresCount == 0) {
                    std::cout << "No figures in the array.\n";
                } else {
                    double totalArea = 0.0;
                    for (size_t i = 0; i < figuresCount; ++i) {
                        totalArea += static_cast<double>(*figures[i]);
                    }
                    std::cout << "Total area of all " << figuresCount << " figures: " << totalArea << std::endl;
                }
                break;
            }
            case 6: {
                if (figuresCount == 0) {
                    std::cout << "No figures to delete.\n";
                } else {
                    std::cout << "Enter index to delete (1-" << figuresCount << "): ";
                    size_t index;
                    if (!(std::cin >> index)) {
                        std::cout << "Invalid input!\n";
                        clearInput();
                    } else if (index >= 1 && index <= figuresCount) {
                        delete figures[index - 1];
                        
                        for (size_t i = index - 1; i < figuresCount - 1; ++i) {
                            figures[i] = figures[i + 1];
                        }
                        figures[figuresCount - 1] = nullptr;
                        figuresCount--;
                        std::cout << "Figure deleted successfully! Total figures: " << figuresCount << "\n";
                    } else {
                        std::cout << "Invalid index!\n";
                    }
                }
                break;
            }
            case 7: {
                if (figuresCount == 0) {
                    std::cout << "No figures to copy.\n";
                } else if (figuresCount >= MAX_FIGURES) {
                    std::cout << "Maximum number of figures reached! Cannot copy.\n";
                } else {
                    std::cout << "Enter index to copy (1-" << figuresCount << "): ";
                    size_t index;
                    if (!(std::cin >> index)) {
                        std::cout << "Invalid input!\n";
                        clearInput();
                    } else if (index >= 1 && index <= figuresCount) {
                        auto copy_ptr = figures[index-1]->clone();
                        figures[figuresCount] = copy_ptr.release();
                        figuresCount++;
                        std::cout << "Figure copied successfully! Total figures: " << figuresCount << "\n";
                    } else {
                        std::cout << "Invalid index!\n";
                    }
                }
                break;
            }
            case 8: {
                if (figuresCount < 2) {
                    std::cout << "Need at least 2 figures for comparison.\n";
                }
                else {
                    std::cout << "Enter two indices to compare (1-" << figuresCount << "): ";
                    size_t index1, index2;
                    if (!(std::cin >> index1 >> index2)) {
                        std::cout << "Invalid input!\n";
                        clearInput();
                    }
                    else if (index1 >= 1 && index1 <= figuresCount && 
                               index2 >= 1 && index2 <= figuresCount) {
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
                for (size_t i = 0; i < figuresCount; ++i) {
                    delete figures[i];
                    figures[i] = nullptr;
                }
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