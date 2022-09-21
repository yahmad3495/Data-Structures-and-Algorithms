#include <algorithm>
/* 
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Solution: Lexigraphically sort both strings. If one is an anagram of the other, the
sorted strings should have the same characters at each index.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.size() != t.size()) {
            return false;
        }
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                return false;
            }
        }
        return true;
    }
};