class Solution {
public:
    /**
     * @param n: An integer
     * @return: the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        int count=1,m=0,num;
        if(n==1) return 1;
        while(count!=n){
        m++;
        num=m;
        while(num>=2&& num%2==0) n/=2;
        while(num>=5&& num%5==0) n/=5;
        while(num>=3&& num%3==0) n/=3;
        if(num==1) count+=1;
        }
        return m;
    }
};
