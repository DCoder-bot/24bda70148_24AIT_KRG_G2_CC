class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<2) return false;
        unordered_map<int,int> mp;
        mp[0] = -1;
        long long prefix = 0;
        bool flag = false, prev = false;
        int ind = 0,need = 0;
        for(int i = 0; i<n;i++){
            int num = nums[i];
            if( num ==0){
                if(prev){
                    return true;
                }
                prev = true;
            }
            else prev = false;
            ind++;
            prefix += num;
            need = prefix % k;
            if(mp.count(need)){
                if(i - mp[need] >= 2)
                    flag =  true;
            }
            else{
            mp[need] = i;
            }
        }
        if(ind>=2 && flag) return true;
        return false; 
    }
};