// 77. Moving Average from Data Stream
// Calculate the moving average of the last size values from a data stream.
// Theory / Approach:
// Keep a queue of the last size values and a running sum. When the queue grows
// too large, remove the oldest value from both the queue and sum.
//
// Why this works:
// The moving average needs only the current window. The running sum avoids
// recomputing the total for every new value.
//
// Time Complexity: O(1) per next call
// Space Complexity: O(size)
#include <bits/stdc++.h>
using namespace std;

class MovingAverage {
public:
    MovingAverage(int size) : size(size), sum(0) {}

    double next(int val) {
        window.push(val);
        sum += val;
        if ((int)window.size() > size) {
            sum -= window.front();
            window.pop();
        }
        return sum / (double)window.size();
    }

private:
    int size;
    double sum;
    queue<int> window;
};

int main() {
    MovingAverage ma(3);
    cout << "next(1) -> " << ma.next(1) << endl;       // 1.0
    cout << "next(10) -> " << ma.next(10) << endl;     // 5.5
    cout << "next(3) -> " << ma.next(3) << endl;       // 4.66667
    cout << "next(5) -> " << ma.next(5) << endl;       // 6.0
    return 0;
}
