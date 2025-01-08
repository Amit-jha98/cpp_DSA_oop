#include <iostream>
using namespace std;

//....TYPE OF FUNCTION....

//...Basedon return Type...

//1st Void Function
void printspmething() {
    cout << "How are you.. (-:";
}

//value-returning Function

int sum(int a, int b) {
    return a + b;
}

// Refrence-returning functions

int& getElement(vector<int>& arr, int index) {
    return arr[index];
}


//...Based On parameter...