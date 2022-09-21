#include <queue>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        //Use priority queue, give prio to largest numbers
        priority_queue<int> helper;
        
        for(int x : nums) {
            helper.push(x);
        }
        
        for(int i = 0; i < k-1; i++) {
            helper.pop();
        }
        
        return helper.top();
    }
};