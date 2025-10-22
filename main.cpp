#include "include/function.h"

using namespace std;

int main() {
    vector<Figure*> figures;
    int choice;
    while (true) {
        printMenu();
        cin >> choice;
        if (choice == 1) {
            Square* square = new Square();
            cout << "Enter a and center (a x y): ";
            cin >> *square;
            figures.push_back(square);
        }
        else if (choice == 2) {
            Rectangle* rect = new Rectangle();
            cout << "Enter a, b and center (a b x y): ";
            cin >> *rect;
            figures.push_back(rect);
        }
        else if (choice == 3) {
            Trapezoid* trap = new Trapezoid();
            cout << "Enter a, b, h and center (a b h x y): ";
            cin >> *trap;
            figures.push_back(trap);
        }
        else if (choice == 4) {
            if (figures.empty()) {
                cout << "No figures\n";
            }
            else {
                for (int i = 0; i < figures.size(); i++) {
                    cout << "Figure " << i+1 << ":\n";
                    cout << *figures[i] << endl;
                    cout << "Center: (" << figures[i]->getCenterX() 
                         << ", " << figures[i]->getCenterY() << ")\n";
                    cout << "Area: " << (double)*figures[i] << "\n\n";
                }
            }
        }
        else if (choice == 5) {
            double total = 0;
            for (int i = 0; i < figures.size(); i++) {
                total += (double)*figures[i];
            }
            cout << "Total area: " << total << endl;
        }
        else if (choice == 6) {
            if (figures.empty()) {
                cout << "No figures\n";
            }
            else {
                int index;
                cout << "Enter index (1-" << figures.size() << "): ";
                cin >> index;
                if (index >= 1 && index <= figures.size()) {
                    delete figures[index-1];
                    figures.erase(figures.begin() + index - 1);
                    cout << "Deleted\n";
                }
                else {
                    cout << "Wrong index\n";
                }
            }
        }
        else if (choice == 7) {
            if (figures.empty()) {
                cout << "No figures\n";
            }
            else {
                int index;
                cout << "Enter index to copy (1-" << figures.size() << "): ";
                cin >> index;
                if (index >= 1 && index <= figures.size()) {
                    Figure* copy = figures[index-1]->clone().release();
                    figures.push_back(copy);
                    cout << "Copied\n";
                }
                else {
                    cout << "Wrong index\n";
                }
            }
        }
        else if (choice == 8) {
            if (figures.size() < 2) {
                cout << "Need 2 figures\n";
            }
            else {
                int i1, i2;
                cout << "Enter two indices: ";
                cin >> i1 >> i2;
                if (i1 >= 1 && i1 <= figures.size() && i2 >= 1 && i2 <= figures.size()) {
                    if (figures[i1-1]->equals(figures[i2-1])) {
                        cout << "Figures are equal\n";
                    }
                    else {
                        cout << "Figures are different\n";
                    }
                }
                else {
                    cout << "Wrong indices\n";
                }
            }
        }
        else if (choice == 9) {
            Square s1(3, 0, 0);
            Square s2(s1);
            Square s3;
            s3 = s1;
            cout << "All squares have area: " << (double)s1 << endl;
            if (s1 == s2) {
                cout << "Copy works correctly\n";
            }
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "Wrong choice\n";
        }
    }
    for (int i = 0; i < figures.size(); i++) {
        delete figures[i];
    }
    return 0;
}