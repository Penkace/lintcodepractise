#include<iostream>
using namespace std;
int digitCounts(int k, int n) {
    int count=0,singlecount=0;
		int p=n;
		int num=0;//表示处理数字的位数 num=0表示处理个位 1表示十位等
		if(k==0) return (n/10)+1;//0-9里面有1个，以这个为一组去加
		if(n==0) return 0;//如果数组的长度为0就要返回
		while(p!=0){//从最高的数开始数，知道最小
			if((p%10)>k) singlecount=(int) ((p/10+1)*(Math.pow(10, (double)num)));//位数，>k表示还可以除。
			else if((p%10)==k) singlecount=(int) ((p/10)*(Math.pow(10, (double)num))+(n%((Math.pow(10, (double)num))))+1);
			else singlecount=(int) ((p/10)*(Math.pow(10, (double)num)));
			count+=singlecount;
			p=p/10;//除完小于表示已经不能再除了
			num++;
		}
		return count;
    }

int main(){
  int n=12,k=0;
  digitCounts(0,12);
  cout<<"The number "<<k<<" have appeared "<<count<<" times.\n";
