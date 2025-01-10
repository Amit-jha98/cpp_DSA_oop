#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

void demonstrateVectors() {
    vector<int> vec = {1, 2, 3, 4, 5};
    
    // Basic operations
    vec.push_back(6);
    vec.insert(vec.begin(), 0);
    
    // Algorithms
    sort(vec.begin(), vec.end());
    auto it = find(vec.begin(), vec.end(), 3);
    int sum = accumulate(vec.begin(), vec.end(), 0);
    
    // Lambda with algorithms
    for_each(vec.begin(), vec.end(), [](int& n) { n *= 2; });
    
    cout << "Vector operations completed\n";
}

void demonstrateMap() {
    map<string, int> scores;
    
    // Inserting elements
    scores["Amit"] = 95;
    scores["sumit"] = 89;
    scores.insert({"tum", 78});
    
    // Accessing elements
    for(const auto& [name, score] : scores) {
        cout << name << ": " << score << endl;
    }
}

void demonstrateSet() {
    set<int> uniqueNums = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    
    // Sets automatically maintain unique, sorted elements
    for(int num : uniqueNums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    demonstrateVectors();
    cout << "\n-------------------\n";
    demonstrateMap();
    cout << "\n-------------------\n";
    demonstrateSet();
    
    return 0;
}
