#include <iostream>
using namespace std;

class circle
{
private:
    float radius,circumferance,area;
    float pi=3.14;
public:
    circle(float r) : radius(r){}                                                                              
    void calculate() {
        cout << "Enter Value of radius" << endl;
           cin >> radius;
           circumferance = 2*pi*radius;
           area = pi*radius*radius;
           cout << "Circumferance is: " << circumferance << endl;
           cout << "Area is: " << area << endl;
    }                                      
};

int main(){
    circle circle1(0);
    circle1.calculate();
    return 0;
}
