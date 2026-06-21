// 75. Logger Rate Limiter
// Design a logger such that for every unique message, it should only be
// printed at most once every 10 seconds.
// Theory / Approach:
// Store the last printed timestamp for each message. A message can print only if
// it has not appeared before or at least 10 seconds have passed.
//
// Why this works:
// The rule depends only on the previous accepted timestamp for the same message,
// so a hash map contains all needed state.
//
// Time Complexity: O(1) average per call
// Space Complexity: O(number of distinct messages)
#include <bits/stdc++.h>
using namespace std;

class Logger {
public:
    Logger() {}

    bool shouldPrintMessage(int timestamp, string message) {
        auto it = lastPrinted.find(message);
        if (it == lastPrinted.end() || timestamp - it->second >= 10) {
            lastPrinted[message] = timestamp;
            return true;
        }
        return false;
    }

private:
    unordered_map<string,int> lastPrinted;
};

int main() {
    Logger logger;
    cout << boolalpha;
    cout << "shouldPrintMessage(1, \"foo\") -> " << logger.shouldPrintMessage(1, "foo") << endl;  // true
    cout << "shouldPrintMessage(2, \"bar\") -> " << logger.shouldPrintMessage(2, "bar") << endl;  // true
    cout << "shouldPrintMessage(3, \"foo\") -> " << logger.shouldPrintMessage(3, "foo") << endl;  // false
    cout << "shouldPrintMessage(8, \"bar\") -> " << logger.shouldPrintMessage(8, "bar") << endl;  // false
    cout << "shouldPrintMessage(10, \"foo\") -> " << logger.shouldPrintMessage(10, "foo") << endl; // false
    cout << "shouldPrintMessage(11, \"foo\") -> " << logger.shouldPrintMessage(11, "foo") << endl; // true
    return 0;
}
