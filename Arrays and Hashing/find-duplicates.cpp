#include <set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        set<int> numbers(nums.begin(), nums.end());
        
        if(nums.size() != numbers.size()) {
            return true;
        }
        return false;
    }
};