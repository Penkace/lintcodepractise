/****************************************************
  >File Name: Leetcode problem NO.76 Minimum Window Substring
  >Author: Peng Kai
  >Date: 2018-10-19 
  >References: http://www.cnblogs.com/grandyang/p/4340948.html
****************************************************/
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> Ts;//存储t字符串中已有的字符以及其个数
        int cnt=0;//计算window中已有t字符串的个数
        string res="";//用于保留返回的结果字符串
        int l=0,minsize=s.size()+1;//minsize记为s.size()+1,在最后的时候如果依旧是这个值说明没有更新这个字符串的长度，说明没有最短的子字符串
        for(char c:t) Ts[c]++;//把t中有的字符映射到Ts哈希表中
        for(int r=0;r<s.size();r++){//开始滑动窗口方法的，l记为窗口的左边，r为窗口的右边
            if(--Ts[s[r]]>=0){//如果满足这个判断式，说明s[r]是字符串t中的一个字符，这时候cnt加一
                ++cnt;
            }
            //当cnt等于字符串t的个数时，说明窗口里面包含了t字符串中的所有字符
            while(cnt==t.size()){
                if(minsize>r-l+1){//更新最小值
                    minsize=r-l+1;
                    res=s.substr(l,minsize);//更新结果字符串
                }
                if(++Ts[s[l]]>0) cnt--;//如果左边的l加了之后大于0，就要跳过这个值，因为这不是t中的字符串值，可以去掉
                l++;//左边开始往右移
            }
        }
        return res;
    }
};
