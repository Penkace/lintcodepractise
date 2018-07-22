/***********
  >Lintcode 5th problem
  >在数组中找到第k大的元素
  >Request：Time complexity O(n)，Space complexity O(1)
  >Reference：https://blog.csdn.net/qq_38213612/article/details/80274903
***********/

class Solution {
public:
    /*
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
       return quicksort(nums,0,nums.size()-1,n);//Call function 'quicksort'
    }
    int quicksort(vector<int> &nums,int left,int right,int n){//the function is a algorithms 'quick sort'
        int i=left;
        int j=right;//i and j are the sentinels of the array
        int temp=nums[i];
        while(i<j){//all the sorting is under the condition of i smaller than j
            while(i<j&& temp>=nums[j]){//j searches the array from the reverse direction untill it finds a number which is smaller than base values
                j--;
            }
            if(i<j){
                nums[i]=nums[j];
                i++;
            }
            while(i<j&&temp<=nums[i]){//i searches the array untill it finds a number which is bigger than base values
                i++;
            }
            if(i<j){
                nums[j]=nums[i];//then exchange 
                j--;//this is the condition of the next search
            }
        }
        if(i==n-1){//if i is equal to n-1, it means that the number is i
            return temp;
        }
        else if(i>n-1){//if not and i bigger than n-1, we should call the function untill we find out the number.
            return quicksort(nums,left,i-1,n);
        }
        else{
            return quicksort(nums,i+1,right,n);
        }
    }
};
