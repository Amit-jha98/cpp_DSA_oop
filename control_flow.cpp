#include <iostream>
using namespace std;

int main() {
    // If-else demonstration
    int num = 10;
    if (num > 0) {
        cout << "Positive number" << endl;
    } else if (num < 0) {
        cout << "Negative number" << endl;
    } else {
        cout << "Zero" << endl;
    }

    // Switch statement
    char grade = 'B';
    switch (grade) {
        case 'A': cout << "Excellent!" << endl; break;
        case 'B': cout << "Good!" << endl; break;
        case 'C': cout << "Fair" << endl; break;
        default: cout << "Invalid grade" << endl;
    }

    // For loop
    cout << "\nFor loop:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i << " ";
    }

    // While loop
    cout << "\n\nWhile loop:" << endl;
    int j = 0;
    while (j < 5) {
        cout << j << " ";
        j++;
    }

    // Do-while loop
    cout << "\n\nDo-while loop:" << endl;
    int k = 0;
    do {
        cout << k << " ";
        k++;
    } while (k < 5);

    return 0;
}