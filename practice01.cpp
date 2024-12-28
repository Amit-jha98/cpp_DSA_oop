#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <thread>
#include <functional>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

// Function declarations
int add(int a, int b);
int fact(int n);

int main(){
    // here is every basic component of c++ feel free to practice and contact Amit (sumitkr95078@gmail.com) if you want to learn something new
    //for some part (19 and 24 to 30) you need extra lib files so try to avoid it or download if you really want to play around it (-;
    
    // 1. Hello World: Basic program to print "Hello World" to the console. This is the simplest C++ program.
    cout << "Hello World" << endl;
    
    // 2. Variables: Demonstrates declaration and initialization of variables. Variables are used to store data.
    int a = 5;
    cout << a << endl;
    
    // 3. Data Types: Shows different data types in C++ (int, float, char, string). Each data type is used to store different types of data.
    a = 5;
    float b = 5.5;
    char c = 'A';
    string d = "Hello";
    cout << a << " " << b << " " << c << " " << d << endl;
    
    // 4. Operators: Demonstrates arithmetic operators in C++. Operators are used to perform operations on variables and values.
    a = 5;
    int b_int = 3;
    cout << a + b_int << endl;
    cout << a - b_int << endl;
    cout << a * b_int << endl;
    cout << a / b_int << endl;
    cout << a % b_int << endl;
    
    // 5. Input Output: Shows how to take input from the user and display output. cin is used for input and cout is used for output.
    cout << "Enter a number: ";
    cin >> a;
    cout << "You entered: " << a << endl;
    
    // 6. Conditional Statements: Demonstrates if-else statements. Conditional statements are used to perform different actions based on different conditions.
    cout << "Enter a number: ";
    cin >> a;
    if(a > 0){
        cout << "Positive" << endl;
    }else if(a < 0){
        cout << "Negative" << endl;
    }else{
        cout << "Zero" << endl;
    }
    
    // 7. Loops: Demonstrates for loop to print numbers from 0 to 9. Loops are used to execute a block of code repeatedly.
    for(int i = 0; i < 10; i++){
        cout << i << endl;
    }
    
    // 8. Functions: Shows how to define and use functions in C++. Functions are used to perform specific tasks.
    a = 5;
    b_int = 3;
    cout << add(a, b_int) << endl;
    
    // 9. Arrays: Demonstrates how to declare and use arrays. Arrays are used to store multiple values in a single variable.
    int arr[5] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++){
        cout << arr[i] << endl;
    }
    
    // 10. Strings: Shows how to use string class in C++. Strings are used to store text.
    string s = "Hello";
    cout << s << endl;
    
    // 11. Pointers: Demonstrates the use of pointers. Pointers are used to store the address of a variable.
    a = 5;
    int *p = &a;
    cout << *p << endl;
    
    // 12. Classes: Shows how to define and use classes in C++. Classes are used to create objects.
    class Student{
        public:
            string name;
            int age;
    };
    Student s1;
    s1.name = "Amit";
    s1.age = 20;
    cout << s1.name << " " << s1.age << endl;
    
    // 13. Vectors: Demonstrates the use of vectors from the STL. Vectors are dynamic arrays that can change in size.
    vector<int> v = {1, 2, 3, 4, 5};
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
    
    // 14. File Handling: Shows how to read from and write to files. File handling is used to store data permanently.
    ofstream out("output.txt");
    out << "Hello World" << endl;
    out.close();
    ifstream in("output.txt");
    in >> s;
    cout << s << endl;
    in.close();
    
    // 15. Exception Handling: Demonstrates try-catch blocks for error handling. Exception handling is used to handle runtime errors.
    try{
        a = 5;
        b_int = 0;
        int c = a / b_int;
        cout << c << endl;
    }catch(exception& e){
        cout << "Error: " << e.what() << endl;
    }
    
    // 16. Recursion: Shows how to use recursion to calculate factorial. Recursion is a technique where a function calls itself.
    cout << fact(5) << endl;
    
    // 17. Lambda Functions: Demonstrates the use of lambda functions. Lambda functions are anonymous functions that can be defined in place.
    auto addLambda = [](int a, int b){
        return a + b;
    };
    cout << addLambda(5, 3) << endl;
    
    // 18. Multithreading: Shows how to create and join threads. Multithreading is used to perform multiple tasks simultaneously.
    thread t([](){
        cout << "Hello World" << endl;
    });
    t.join();
    
    // 19. Networking: Demonstrates basic socket programming. Networking is used to connect and communicate with other computers.
    // int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    // struct sockaddr_in serv_addr;
    // serv_addr.sin_family = AF_INET;
    // serv_addr.sin_port = htons(8080);
    // inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    // connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    // send(sockfd, "Hello World", 12, 0);
    // close(sockfd);
    
    // 20. GUI: Shows how to create a basic GUI application. GUI (Graphical User Interface) is used to create interactive applications.
    // QApplication app(argc, argv);
    // QWidget widget;
    // widget.show();
    // return app.exec();
    
    // 21. STL: Demonstrates the use of Standard Template Library (STL) containers. STL provides a set of common classes for data structures and algorithms.
    vector<int> v2 = {1, 2, 3, 4, 5};
    for(int i = 0; i < v2.size(); i++){
        cout << v2[i] << endl;
    }
    
    // 22. Data Structures: Shows how to create and use linked lists. Data structures are used to store and organize data efficiently.
    struct Node{
        int data;
        Node *next;
    };
    Node *head = NULL;
    Node *temp = new Node;
    temp->data = 1;
    temp->next = NULL;
    head = temp;
    Node *temp2 = new Node;
    temp2->data = 2;
    temp2->next = NULL;
    head->next = temp2;
    cout << head->data << " " << head->next->data << endl;
    
    // 23. Algorithms: Demonstrates sorting algorithms using STL. Algorithms are used to perform operations on data structures.
    vector<int> v3 = {5, 3, 2, 4, 1};
    sort(v3.begin(), v3.end());
    for(int i = 0; i < v3.size(); i++){
        cout << v3[i] << endl;
    }
    
    // 24. Machine Learning: Shows a basic example of linear regression. Machine learning is a field of artificial intelligence that uses statistical techniques to give computer systems the ability to learn from data.
    // vector<vector<int>> X = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    // vector<int> y = {1, 2, 3, 4};
    // LinearRegression lr;
    // lr.fit(X, y);
    // cout << lr.predict({5, 6}) << endl;
    
    // 25. Deep Learning: Demonstrates a simple neural network model. Deep learning is a subset of machine learning that uses neural networks with many layers.
    // Sequential model;
    // model.add(Dense(64, "relu"));
    // model.add(Dense(64, "relu"));
    // model.add(Dense(10, "softmax"));
    // model.compile("adam", "crossentropy");
    // model.fit(X, y);
    // model.predict({5, 6});
    
    // 26. Web Development: Shows a basic web server setup. Web development is used to create websites and web applications.
    // app.get("/", [](req, res){
    //     res.send("Hello World");
    // });
    // app.listen(8080);
    
    // 27. Mobile Development: Demonstrates a simple mobile app using Flutter. Mobile development is used to create applications for mobile devices.
    // class MyApp extends StatelessWidget{
    //     @override
    //     Widget build(BuildContext context){
    //         return Text("Hello World");
    //     }
    // }
    
    // 28. Game Development: Shows a basic game development setup. Game development is used to create video games.
    // class Game extends StatelessWidget{
    //     @override
    //     Widget build(BuildContext context){
    //         return Scaffold(
    //             body: Center(
    //                 child: Text("Hello World")
    //             )
    //         );
    //     }
    // }
    
    // 29. Cloud Computing: Demonstrates a simple cloud computing example. Cloud computing is used to deliver computing services over the internet.
    // class Cloud extends StatelessWidget{
    //     @override
    //     Widget build(BuildContext context){
    //         return Scaffold(
    //             body: Center(
    //                 child: Text("Hello World")
    //             )
    //         );
    //     }
    // }
    
    // 30. IoT: Shows a basic IoT application setup. IoT (Internet of Things) is used to connect and exchange data with other devices and systems over the internet.
    // class IoT extends StatelessWidget{
    //     @override
    //     Widget build(BuildContext context){
    //         return Scaffold(
    //             body: Center(
    //                 child: Text("Hello World")
    //             )
    //         );
    //     }
    // }

    // 31. Practice input and output: Demonstrates basic input and output operations. This is a simple example to practice taking input and displaying output.
    int num1,num2,sum;
    float total,result;
    cout<< "Enter Two number: ";
    cin >> num1 >> num2;
    cout << "You entered: " << num1 << " and " << num2 << endl;
    sum=num1+num2;
    result=(sum*num1)/num2;
    total=result+sum;
    cout << "\n Sum of both number is: " << sum << "\n and final reault is: " << total;
    return 0;
}

// Function definitions
int add(int a, int b){
    return a + b;
}

int fact(int n){
    if(n == 0){
        return 1;
    }else{
        return n * fact(n - 1);
    }
}