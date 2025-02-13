#include <iostream>
using namespace std;

class Array{
public: 
    int i,j;
    int low;
    int high;
    int size;
    int mid;
    float target;
    float *arr;    
public:
    Array(int s,float t) : size(s), target(t), low(0), high(s-1) {}
    

    
    void binarySearch(){
        cout << "Enter Element of array: " << endl;
        arr = new float[size];
        for(i=0;i<size;i++){
            cin >> arr[i];
        }
        cout << "Enter Element That You Want to find" << endl;
        cin >> target;
        // arr = new float[size];
        // for(i=0;i<size;i++){
        //     arr[i] = i+1;
        // }
        while(low<=high){
            mid = low + (high - low)/2;
            if(arr[mid] == target) {
                cout << " Element Found At: " << mid << endl;
                return;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << " Element Found At: " << mid << endl;
    }

        ~Array() {
        delete[] arr;
    }

};

int main (){
    int size;
    float target;
    cout <<  "Enter Size of array: " << endl;
    cin >> size;


    Array array1(size,target);
    array1.binarySearch();
    return 0;
}