/*************************
  >File Name: 二叉查找树中搜索区间
  >Author: PengKai
  >Date: 2018-08-21 Monday 00:50
  >Reference: https://blog.csdn.net/linglian0522/article/details/55261803
*************************/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: param root: The root of the binary search tree
     * @param k1: An integer
     * @param k2: An integer
     * @return: return: Return all keys that k1<=key<=k2 in ascending order
     */
    vector<int> searchRange(TreeNode * root, int k1, int k2) {
        // write your code here
        vector<int> results;
        if(root==NULL) return results;
        
        stack<TreeNode*> nodenum;
        TreeNode *p=root;
        while(p!=NULL || !nodenum.empty() ){
            while(p!=NULL){//找到大于下界最左边的结点
                nodenum.push(p);
                if(p->val >=k1)
                    p=p->left;
                    else p=NULL;
            }  
            if(!nodenum.empty()){
                p=nodenum.top();
                nodenum.pop();//栈顶是左边最小的结点,并且判断该结点是否符合条件，符合就加入到vector中
                if(p->val<=k2&& p->val>=k1)
                    results.push_back(p->val);
            }
            if(p->val>k2) p=NULL;//遍历完左边最小开始遍历其右边结点，把符合条件的数留在数组中
            else p=p->right;
        }
        return results;
    }
};
