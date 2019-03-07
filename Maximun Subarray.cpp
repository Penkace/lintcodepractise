/**********************************************
    Problem: Maximun Subarray
    Solution: At first, my transition formulation is f(n) = max(f(n-1)+nums[i],nums[i]) which is wrong, because if f(5) = nums[5] and
              f(6) = f(5)+nums[6], we can't know whether nums[5]+nums[6]+nums[7] is larger than nums[5]. So I change my solution and finally
              the transition formulation is if f(n-1)>0,which means it's useful, f(n) = f(n-1)+nums[i] and we maintain a sum to record the
              maximum.
**********************************************/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l =nums.size();
        int sum = INT_MIN;
        vector<int>opt(l,0);
        opt[0] = nums[0];
        sum = opt[0];
        for(int i=1;i<l;i++){
            opt[i] = (opt[i-1]>0)?(opt[i-1]+nums[i]):nums[i];
            if(opt[i]>sum) sum = opt[i];
        }
        return sum;
    }
};
