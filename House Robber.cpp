/******************************************************************************************************************************************************
      Problem: House Robber  (Easy DP)
      Solution: Using the idea of dynamic programming to solve the problem is an effective way. To work out the vector tmp is the subproblem
                And the State Transition formulation is f(n) = max(f(n-2)+arr[n],f(n-1)). f(0) and f(1) is known. Top-down solving the problem
                gets the answer.
******************************************************************************************************************************************************/
class Solution {
public:
    int rob(vector<int>& nums) {
        int l = nums.size();
        if(l==0) return 0;
        else if(l==1) return nums[0];
        else{
            vector<int>tmp(l,0);
            tmp[0] = nums[0];
            tmp[1] = max(nums[0],nums[1]);
            for(int i=2;i<l;i++){
                tmp[i] = max(tmp[i-2]+nums[i],tmp[i-1]);
            }
            return tmp[l-1];
        }
    }
};
