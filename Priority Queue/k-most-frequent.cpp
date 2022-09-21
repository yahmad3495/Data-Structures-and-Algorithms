#include <unordered_map>
#include <queue>

class Solution {
public:
    
    struct myComp {
        constexpr bool operator()(pair<int, int> const& a, pair<int, int> const&b) {
            return a.second < b.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> solution;
        unordered_map<int,int> frequencies;
        
        //Store all frequencies in a hashmap
        for (const auto& num : nums) {
            //Check if num is alr in hashmap
            if (frequencies.find(num) == frequencies.end()) {
                frequencies.insert({num, 0});
            } else {
                frequencies[num]++;
            }
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pq;
        for (const auto& pair : frequencies) {
            pq.push(pair);
        }
        
        for (int i = 0; i < k; i++) {
            solution.push_back(pq.top().first);
            pq.pop();
        }
        //Use pq to give priority to elements that are more frequent
        return solution;
    }
};