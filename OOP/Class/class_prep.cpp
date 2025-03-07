/*....OUTPUT...
Enter length and width of Rectangle: 4 6
Area of Rectangle is: 24
Perimeter of Rectangle is: 20
*/

#include<iostream>
using namespace std;

class Rectangle{
    //access specifier
    //by default it is private
private: 
    int l;
    int b;
    int area, perimeter;
public:
    //constructor
    Rectangle(int length,int width) : l(length), b(width) {}
    //methods (function)
    void RectangleArea(){
        area = l*b;
        cout << "Area of Rectangle is: " << area << endl;
    }

    void RectanglePerimeter(){
        perimeter = 2*(l+b);
        cout << "Perimeter of Rectangle is: " << perimeter << endl;
    }
};

int main(){
    //variable declaration
    int l,b;
    cout << "Enter length and width of Rectangle: ";
    cin >> l >> b;

    //object creation
    Rectangle r1(l,b);
    r1.RectangleArea();
    r1.RectanglePerimeter();
    return 0;
}