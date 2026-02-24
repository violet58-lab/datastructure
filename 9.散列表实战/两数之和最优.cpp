#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashMap;
        for(int i = 0; i < nums.size(); ++i) {
            if(hashMap.find(target - nums[i]) != hashMap.end()) {
                return {i,hashMap[target - nums[i]]};
            } else {
                hashMap[nums[i]] = i;
            }
        }
        return {-1,-1};
    }
};