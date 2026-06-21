// 97. Text Justification
// Format text so that each line has exactly maxWidth characters and is
// fully (left and right) justified. The last line is left-justified.
// Theory / Approach:
// Greedily pack as many words as fit on each line. Distribute spaces evenly
// between words, putting extra spaces on the left gaps; left-justify the last line.
//
// Why this works:
// Each line is independent once the maximum fitting word range is chosen. The
// formatting rules determine the exact spaces for that range.
//
// Time Complexity: O(total characters)
// Space Complexity: O(maxWidth) extra per line, excluding output.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0, n = words.size();
        while (i < n) {
            int j = i;
            int lineLen = 0;
            // Determine how many words fit on this line
            while (j < n && lineLen + (int)words[j].size() + (j - i) <= maxWidth) {
                lineLen += words[j].size();
                ++j;
            }
            int numWords = j - i;
            int totalSpaces = maxWidth - lineLen;
            string line;

            if (j == n || numWords == 1) {
                // Last line, or single word: left-justify
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k != j - 1) line += " ";
                }
                while ((int)line.size() < maxWidth) line += " ";
            } else {
                int gaps = numWords - 1;
                int spaceEach = totalSpaces / gaps;
                int extra = totalSpaces % gaps;
                for (int k = i; k < j; ++k) {
                    line += words[k];
                    if (k != j - 1) {
                        int spaces = spaceEach + (k - i < extra ? 1 : 0);
                        line += string(spaces, ' ');
                    }
                }
            }
            res.push_back(line);
            i = j;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    auto res = sol.fullJustify(words, 16);
    cout << "maxWidth=16\n";
    for (auto& line : res) cout << "\"" << line << "\"\n";
    return 0;
}
