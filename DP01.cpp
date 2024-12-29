#include <iostream>
#include <vector>
#include <string>
using namespace std;

int numWays(vector<string>& words, string target) {
    const int MOD = 1e9 + 7;
    int m = target.size();
    int n = words[0].size();

    // Precompute character frequencies at each index of words
    vector<vector<int>> freq(26, vector<int>(n, 0));
    for (const string& word : words) {
        for (int j = 0; j < n; ++j) {
            freq[word[j] - 'a'][j]++;
        }
    }

    // DP array: dp[i][j] -> ways to form target[0..i-1] using words[0..j-1]
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

    // Base case: one way to form an empty target
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = 1;
    }

    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            // Case 1: Skip the current column
            dp[i][j] = dp[i][j - 1];

            // Case 2: Use the current column if it matches target[i-1]
            char targetChar = target[i - 1];
            if (freq[targetChar - 'a'][j - 1] > 0) {
                dp[i][j] += dp[i - 1][j - 1] * freq[targetChar - 'a'][j - 1];
                dp[i][j] %= MOD;
            }
        }
    }

    return dp[m][n];
}

int main() {
    vector<string> words = {"acca", "bbbb", "caca"};
    string target = "aba";
    cout << numWays(words, target) << endl;

    vector<string> words2 = {"abba", "baab"};
    string target2 = "bab";
    cout << numWays(words2, target2) << endl;

    return 0;
}
