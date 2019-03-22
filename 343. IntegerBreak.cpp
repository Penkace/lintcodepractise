/***********************************************************
参考bobo老师的写法，然后做了个别的优化。
P
***********************************************************/
class Solution {
private:
    vector<int>memo;
    int get_max(int a,int b,int c){
        return (a>b?a:b)>c?(a>b?a:b):c;
    }
    int breakInteger(int n){
        if(n==1)
            return 1;
        if(memo[n] !=-1)
            return memo[n];
        int res =-1;
        for(int i=1;i<=n-1;i++){
            res =get_max(res,i*(n-i),i*breakInteger(n-i));
        }
        memo[n] = res;
        return res;
    }
public:    
    int integerBreak(int n) {
        memo = vector<int>(n+1,-1);
        return breakInteger(n);
    }
};
