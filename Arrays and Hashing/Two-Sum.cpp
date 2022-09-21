#include <algorithm>
#include <vector>
#include <unordered_map>


/*
This solution is for sorted arrays
Sort nums and begin scanning from outside in. If the sum of these two
indices are too large, move the right pointer 1 down to get a smaller number.
If it's too small move left pointer up.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> copy(nums);
        sort(copy.begin(), copy.end());
        vector<int> solution;
        
        int i = 0;
        int j = nums.size() - 1;
        int tmp_sum;
        
        while (i < j) {
            tmp_sum = copy.at(i) + copy.at(j);
            if (tmp_sum == target) {
                solution.push_back(i);
                solution.push_back(j);
                break;
            }
            else if(tmp_sum < target) {
                i++;
            } 
            else if(tmp_sum > target) {
                j--;
            }
        }
        
        return solution;
    }
};
*/

/*
Hashing Solution: Create a hashmap representation of the nums array where keys are the 
integers and value is index. For each x, check if value - x exists in the map. If it does, 
return the index associated with value.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> copy_nums;
        vector<int> solution;
        
        for(int i = 0; i < nums.size(); i++) {
            copy_nums.insert({nums.at(i), i});
        }
        
        for (int x = 0; x < nums.size(); x++) {
            int y = target - nums.at(x);
            unordered_map<int, int>::const_iterator got = copy_nums.find(y);
            if(got != copy_nums.end()) {
                if (x == got->second) {
                    continue;
                }
                solution.push_back(x);
                solution.push_back(got->second);
                break;
            }
        }
        return solution;
    }
};