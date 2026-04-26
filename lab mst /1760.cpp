class Solution {
public:
int op;
    bool check(vector<int> &nums, int mid){
        long long ch = 0;
        for(int i:nums){
            if(i <= mid) continue;
            ch += (i - 1)/mid;
        }
        if(ch <=op) return true;
        return false;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        op = maxOperations;
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(nums,mid)){
                high = mid -1;
                ans = mid;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};