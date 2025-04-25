#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

string minWindow(string s, string t) {
    if (t.empty() || s.empty()) return "";

    unordered_map<char, int> freq;
    for (char c : t) freq[c]++; 

    int left = 0, right = 0, count = t.size(), minLen = INT_MAX, start = 0;

    while (right < s.size()) {
        if (freq[s[right]] > 0) count--;
        freq[s[right]]--;  
        right++;

        while (count == 0) {
            if (right - left < minLen) {  
                minLen = right - left;
                start = left;
            }

            freq[s[left]]++;  
            if (freq[s[left]] > 0) count++;
            left++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

int main() {
    string s = "ADOBEBANC", t = "ABC";
    cout << "Minimum window substring: " << minWindow(s, t) << endl;
    return 0;
}
