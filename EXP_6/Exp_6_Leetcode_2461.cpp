#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long sum = 0, ans = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            mp[nums[right]]++;
            sum += nums[right];

            if (right - left + 1 > k) {
                mp[nums[left]]--;
                if (mp[nums[left]] == 0) mp.erase(nums[left]);
                sum -= nums[left];
                left++;
            }

            if (right - left + 1 == k && mp.size() == k) {
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};