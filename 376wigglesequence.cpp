/*************************************************************************
刚开始的时候想能不能就在一个数组内进行动态规划的方法去做，难处在于当前序列的下一个序列是需要大于还是小于的数接上
这里的标记比较麻烦，后来参考了博客https://www.cnblogs.com/grandyang/p/5697621.html的一个解法，发现采用两个数组来做是比较好的
一个数组是记录首差为正，另一个数组记录首差为负的，可以理解为上一次是正，或者是负。
两层循环，外围遍历的数和内围遍历的数，当内围遍历的数大于外围遍历的数，就要跟在首差为负的数进行加1，并与当前首差为正的序列进行比较，看哪个大。
*************************************************************************/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==0) return 0;
        
        vector<int> rz(nums.size(),1);
        vector<int> rf(nums.size(),1);
        
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]) rz[i] = max(rz[i],rf[j]+1);
                else if(nums[i]<nums[j]) rf[i] = max(rf[i],rz[j]+1);
            }
        }
        return max(rz.back(),rf.back());
    }
};
