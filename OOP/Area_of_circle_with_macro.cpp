#include <iostream>
#define PI 3.14
using namespace std;

float area(float a, float r) {
    a=PI*r*r;
    return a;
}

int main () {
    float a ,r;
    cout<<"Enter Vlaue Of Radius" << endl;
    cin>>r;
    cout<<"Result is: " << area(a,r) << endl;
    return 0;
}


/*....OUTPUT.....

Enter Vlaue Of Radius
3
Result is: 28.26
*/
