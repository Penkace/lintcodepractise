#include<iostream>
using namespace std;
/*
在数组中找到第k大的元素
你可以交换数组中的元素的位置
样例
给出数组 [9,3,2,4,8]，第三大的元素是 4
给出数组 [1,2,3,4,5]，第一大的元素是 5，第二大的元素是 4，第三大的元素是 3，以此类推
挑战
要求时间复杂度为O(n)，空间复杂度为O(1)*/

int thelargest(int a[],int k) {
	int i = 0;
	while (a[i] != '\0') {
		i++;
	}//得到数组的最大长度i

	int sl = i-1;//等于数组的下标值
	int *p = new int[sl];//定义存放最后结果的数组
	
	int key = a[0];
	for (i =sl; i >= 0; i--) {
		if (a[i] > key) {
			key = a[i];
		}
	}//找到原数组的最大值key
	int m = key;
	int *q = new int[m];//定义用来存放频率的数组
	for (int j = 0; j <m; j++) {
		q [j] = 0;//初始化该数组，另该数组的值都为0
	}

	for (int j = 0; j < m; j++) {
		q[a[j]]++;//存放每个数字出现的频率
	}
	for (int j = m-1; j >0; j++) {
		q[j] = q[j] + q[j - 1];//把这个数的大小排序出来
	}
	for (i = sl - 1; i >= 0; --i)
	{
		p[q[a[i]] - 1] = a[i];//把数字放进数组里面
		q[a[i]]--;//放进去了一个就减一
	}
	return p[k-1];
	delete[] p;
	delete[]q;
}

int main() {
	using namespace std;
	int a[5] = { 9,3,2,4,8 };
	int c=thelargest(a,3);
	cout << c << endl;
	system("pause");
	return 0;
}
