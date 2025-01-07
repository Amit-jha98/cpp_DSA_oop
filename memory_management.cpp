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
    {
        Resource r;
        r.use();
    }
    cout << "\n-------------------\n";

    Resource* ptr = new Resource();
    ptr->use();
    delete ptr;
    cout << "\n-------------------\n";

    {
        unique_ptr<Resource> uniquePtr = make_unique<Resource>();
        uniquePtr->use();
    }
    cout << "\n-------------------\n";

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
