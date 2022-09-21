#include <algorithm>
#include <unordered_map>

/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

Solution: Sort words in lexographical order. All anagrams of a word have one unique sort. Use this sort as the
key in a hashmap entry, where the value associated is a list of all words that have this lex sort.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> ans;
        vector<string> words (strs.begin(), strs.end());
        vector<vector<string>> result;
        
        for(int i = 0; i < words.size(); i++) {
            sort(words.at(i).begin(), words.at(i).end());
            if (ans.find(words.at(i)) == ans.end()) {
                vector<string> anagrams;
                anagrams.push_back(strs.at(i));
                ans.insert({words.at(i), anagrams});
            } 
            else {
                ans[words.at(i)].push_back(strs.at(i));
            }
        }
        
        for (const auto& anagram_list : ans) {
            result.push_back(anagram_list.second);
        }
        return result;
    }
};