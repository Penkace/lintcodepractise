/*************************************
    Problem: Decode Ways (DP)
    Solution: When I think the derivation of state transition formulation, I referred some blogs and found that from the end of the string
              we judge if it can decode and then move forward. Everytime we need to judge if The number and the character of the next digit
              form a number less than 26, which means it can form a new combination with the string after the first 2 letters.
              So dp[i] += dp[i-2]
    References: https://www.tianmaying.com/tutorial/LC91
*************************************/
class Solution {
public:
    int numDecodings(string s) {
        vector<int> opt(s.length()+1,0);
        // 只有一个数字是肯定可以decode
        opt[0] = 1;
        int l = s.length();
        for(int i=1;i<=l;i++){
            // 前一个字母不等于0,说明至少和前一个字母具有相同的decode数,这个0可能位于字符串中间，是不能解码的
            if(s[i-1]!='0') {
                opt[i] += opt[i-1];
            }
            // 再判断i和i-1是否可以组成10~26之间的数字
            if(i>1&&s.substr(i-2,2)>="10"&&s.substr(i-2,2)<="26"){
                opt[i]+=opt[i-2];
            }
        }
        return opt[l];
    }
};
