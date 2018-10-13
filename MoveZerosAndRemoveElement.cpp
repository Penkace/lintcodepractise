/*****************************************************
  >File Name: MoveZeros And RemoveElement in lintcode
  >Author: Peng Kai
  >Date: 2018-10-13 11:20
  >mark: The performance of MoveZeros is conclusive but the performance of RemoveElement can be optimized. If you have any ideas, you can contact me.
*****************************************************/

class Solution {
public:
    /*
     * @param A: A list of integers
     * @param elem: An integer
     * @return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        int l=A.size();
        int k=0;
        for(int i=0;i<l;i++){
            if(A[i]!=elem){
                if(i!=k)
                    swap(A[k++],A[i]);
                else k++;
            }
        }
        return k;
    }
};
