#include <iostream>

class Array{
public: 
    int i,j;
    int size;
    int low;
    int high;
    int mid;
    float target;
    float *arr;    
public:
    Array(int s,float t) : size(s), target(t), low(0), high(s-1) {}
    

    
    void binarySearch(){
        std::cout << "Enter Element of array: " << std::endl;
        arr = new float[size];
        for(i=0;i<size;i++){
            std::cin >> arr[i];
        }
        std::cout << "Enter Element That You Want to find" << std::endl;
        std::cin >> target;
        while(low<=high){
            mid = low + (high - low)/2;
            if(arr[mid] == target) {
                std::cout << "Element Found At: " << mid << std::endl;
                return;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        std::cout << "Element Does Not Exist "<< std::endl;
    }

        ~Array() {
        delete[] arr;
    }

};

int main (){
    int size;
    float target;
    std::cout <<  "Enter Size of array: " << std::endl;
    std::cin >> size;


    Array array1(size,target);
    array1.binarySearch();
    return 0;
}