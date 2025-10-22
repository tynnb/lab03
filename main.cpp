#include "include/function.h"

using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    vector<Figure*> figures;
    int choice;
    
    while (true) {
        printMenu();
        cin >> choice;
        
        if (cin.fail()) {
            cout << "Invalid input! Please enter a number.\n";
            clearInput();
            continue;
        }
        
        switch (choice) {
            case 1: {
                Square* square = new Square();
                cout << "Enter side length: ";
                if (!(cin >> *square)) {
                    cout << "Invalid input! Square not added.\n";
                    delete square;
                    clearInput();
                } else {
                    figures.push_back(square);
                    cout << "Square added\n";
                }
                break;
            }
            case 2: {
                Rectangle* rect = new Rectangle();
                cout << "Enter width and height: ";
                if (!(cin >> *rect)) {
                    cout << "Invalid input! Rectangle not added.\n";
                    delete rect;
                    clearInput();
                } else {
                    figures.push_back(rect);
                    cout << "Rectangle added\n";
                }
                break;
            }
            case 3: {
                Trapezoid* trap = new Trapezoid();
                cout << "Enter base1, base2 and height: ";
                if (!(cin >> *trap)) {
                    cout << "Invalid input! Trapezoid not added.\n";
                    delete trap;
                    clearInput();
                } else {
                    figures.push_back(trap);
                    cout << "Trapezoid added\n";
                }
                break;
            }
            case 4: {
                if (figures.empty()) {
                    cout << "No figures\n";
                } else {
                    for (int i = 0; i < figures.size(); i++) {
                        cout << "Figure " << i+1 << ":\n";
                        cout << *figures[i] << endl;
                        cout << "Center: (" << figures[i]->getCenterX() 
                             << ", " << figures[i]->getCenterY() << ")\n";
                        cout << "Area: " << (double)*figures[i] << "\n\n";
                    }
                }
                break;
            }
            case 5: {
                if (figures.empty()) {
                    cout << "No figures\n";
                } else {
                    double total = 0;
                    for (int i = 0; i < figures.size(); i++) {
                        total += (double)*figures[i];
                    }
                    cout << "Total area: " << total << endl;
                }
                break;
            }
            case 6: {
                if (figures.empty()) {
                    cout << "No figures\n";
                } else {
                    int index;
                    cout << "Enter index (1-" << figures.size() << "): ";
                    cin >> index;
                    
                    if (cin.fail()) {
                        cout << "Invalid input!\n";
                        clearInput();
                    } else if (index >= 1 && index <= figures.size()) {
                        delete figures[index-1];
                        figures.erase(figures.begin() + index - 1);
                        cout << "Deleted\n";
                    } else {
                        cout << "Wrong index\n";
                    }
                }
                break;
            }
            case 7: {
                if (figures.empty()) {
                    cout << "No figures\n";
                } else {
                    int index;
                    cout << "Enter index to copy (1-" << figures.size() << "): ";
                    cin >> index;
                    
                    if (cin.fail()) {
                        cout << "Invalid input!\n";
                        clearInput();
                    } else if (index >= 1 && index <= figures.size()) {
                        auto copy_ptr = figures[index-1]->clone();
                        figures.push_back(copy_ptr.release());
                        cout << "Copied\n";
                    } else {
                        cout << "Wrong index\n";
                    }
                }
                break;
            }
            case 8: {
                if (figures.size() < 2) {
                    cout << "Need 2 figures\n";
                } else {
                    int i1, i2;
                    cout << "Enter two indices: ";
                    cin >> i1 >> i2;
                    
                    if (cin.fail()) {
                        cout << "Invalid input!\n";
                        clearInput();
                    } else if (i1 >= 1 && i1 <= figures.size() && i2 >= 1 && i2 <= figures.size()) {
                        if (figures[i1-1]->equals(figures[i2-1])) {
                            cout << "Figures are equal\n";
                        } else {
                            cout << "Figures are different\n";
                        }
                    } else {
                        cout << "Wrong indices\n";
                    }
                }
                break;
            }
            case 9: {
                Square s1(5, 1, 2);
                cout << "Original square area: " << (double)s1 << endl;
                Square s2(std::move(s1));
                cout << "After move constructor:\n";
                cout << "s2 area: " << (double)s2 << endl;
                Square s3;
                s3 = std::move(s2);
                cout << "After move assignment:\n";
                cout << "s3 area: " << (double)s3 << endl;
                cout << "Move operations demonstrated successfully!\n";
                break;
            }
            case 0: {
                break;
            }
            default: {
                cout << "Wrong choice\n";
                break;
            }
        }
        if (choice == 0) {
            break;
        }
    }
    for (int i = 0; i < figures.size(); i++) {
        delete figures[i];
    }
    return 0;
}