/************************
  >File Name: Fill blanks with numbers one to nine. □ □ □ + □ □ □ = □ □ □
  >Author：Penkace
  >Refences: 《啊哈！算法》
  >Time: 2018-08-01 Wednesday
  >Idea: Recursion
************************/
#include<iostream>
using namespace std;
void dfs(int);
int a[10], book[10], total = 0;//初始化两个数组，内部元素都为0

void dfs(int step) {
	int i;
	if (step == 10) {//如果箱子中的牌放满了，则开始验证下式是否成立
		if (a[1] * 100 + a[2] * 10 + a[3] + a[4] * 100 + a[5] * 10 + a[6] == a[7] * 100 + a[8] * 10 + a[9])
		{
			total++;
			for (int j = 0; j < 10; j++) {
				cout << a[j] << " ";
			}
			cout << "\n";
		}//判断是否能够相加，然后输出这组数字的顺序
			return;//返回上一次dfs的调用
		}
		for (i = 1; i <= 9; i++)//数字1到9轮流放入
		{
			if (book[i] == 0) {
				a[step] = i;//使得箱子里面的数字是i
				book[i] = 1;//book数组用于表示数字是否在手上，用来标记牌是否使用。如果book[i]等于零，则说明牌在手上
				dfs(step + 1);//前面的盒子放好了，则处理下一个盒子
				book[i] = 0;//将盒子中的牌回收
			}
		}
		return;
	}

int main()
{
	dfs(1);//开始从第一个小箱子放起
	cout << total/2 << endl;//对于数字排列，因为左右两个数出现过两次，所以就要除以2，但如果是排列组合问题则不需要除以2
	system("pause");
	return 0;
}
