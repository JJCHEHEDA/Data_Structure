class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mnnum = nums[nums.size()-1]+nums[nums.size()-2]+nums[nums.size()-3];
        int mn = abs(mnnum-target);
        for (int i=0 ; i<nums.size() ; i++){
            int l = i+1, r = nums.size()-1;
            while (l<r){
                int x = nums[l]+nums[r]+nums[i];
                if (x>target){
                    r--;
                }
                else{
                    l++;
                }
                int m = abs(target-x);
                if (m<mn){
                    mnnum = x;
                    mn = m;
                }
            }
        }
        return mnnum;
    }
};