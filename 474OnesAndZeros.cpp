/***************************************************************
References: https://www.cnblogs.com/grandyang/p/6188893.html
***************************************************************/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // 创建一个二维的dp数组，长度都比给出的m,n大1
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        // 遍历数组中的字符串
        for(string str: strs){
            int zeros = 0,ones =0;
            // 记录当前字符串的01个数
            for(char c:str) (c=='0')?zeros++:ones++;
            // 更新dp数组，
            for(int i=m;i>=zeros;i--){
                for(int j=n;j>=ones;j--){
                    // dp[i - zeros][j - ones]表示当前的i和j减去zeros和ones之前 能拼成字符串的个数
                    // 加1表示拼成当前的字符串，当前字符串需要zeros个0和ones个1拼成
                    // 跟原有数值进行比较即可
                    dp[i][j] = max(dp[i][j],dp[i-zeros][j-ones]+1);
                }
            }
        }
        return dp[m][n];
    }
};
