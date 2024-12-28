#include <iostream>
#include <memory>
using namespace std;

class Resource {
public:
    Resource() { cout << "Resource acquired\n"; }
    ~Resource() { cout << "Resource destroyed\n"; }
    void use() { cout << "Resource being used\n"; }
};

int main() {
    // Stack Memory Example
    {
        Resource r;  // Automatically destroyed when scope ends
        r.use();
    }  // r is destroyed here
    cout << "\n-------------------\n";

    // Heap Memory with Raw Pointer
    Resource* ptr = new Resource();
    ptr->use();
    delete ptr;  // Manual cleanup required
    cout << "\n-------------------\n";

    // Smart Pointers
    // 1. Unique Pointer
    {
        unique_ptr<Resource> uniquePtr = make_unique<Resource>();
        uniquePtr->use();
    }  // Automatically deleted
    cout << "\n-------------------\n";

    // 2. Shared Pointer
    {
        shared_ptr<Resource> sharedPtr1 = make_shared<Resource>();
        {
            shared_ptr<Resource> sharedPtr2 = sharedPtr1;
            cout << "Reference count: " << sharedPtr1.use_count() << endl;
            sharedPtr2->use();
        }
        cout << "Reference count: " << sharedPtr1.use_count() << endl;
        sharedPtr1->use();
    }

    return 0;
}
