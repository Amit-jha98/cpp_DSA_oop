/*..OUTPUT...
Enter Element In array: 1 2 3 4 5 6 
Element Of array are: 1 2 3 4 5 6
*/

#include <iostream>
using namespace std;

int main(){

    // Decleration of the array...
    int  i,arr[5];
    cout <<"Enter Element In array: ";

    //Loop for adding elemenet in array...
    for (i=0; i<=5; i++)
    {
        cin >> arr[i];
    };

    //printing output (Elements of array)...
    cout << "Element Of array are: ";
    for (i=0; i<=5; i++){
        cout << arr[i] << " ";
    };
    return 0;
}
