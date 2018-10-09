#在O(logn)时间复杂度的条件下，利用二分查找找数
class Solution:
    """
    @param nums: The integer array.
    @param target: Target to find.
    @return: The first position of target. Position starts from 0.
    """
    def binarySearch(self, nums, target):
        # write your code here
        return self.binaryFind(nums,target,0,len(nums))   #self 放在外边而不是作为实例参数
    def binaryFind(self,nums,target,left,right):
        if left>=right:
            return -1
        if nums[left]==target:
            return left
        mid=(left+right)//2
        if nums[mid]==target and nums[mid-1]!=target:
            return mid
        if nums[mid]>=target:
            right=mid
            return self.binaryFind(nums,target,left,right)
        elif nums[mid]<target:
            left=mid+1
            return self.binaryFind(nums,target,left,right)
        else:
            return -1
