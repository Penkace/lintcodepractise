#include<iostream>
#include<vector>
#include<string>
using namespace std;
//计数排序法，时间复杂度为 O(n),线性时间的排序
int main() {
	int a[5] = { 9, 3, 2, 4, 8 };
	int *p = new int[5];
	int *q = new int[10];
	for (int i = 0; i < 10; i++) {
		q[i] = 0;
	}
	for (int j = 0; j < 5; j++) {
		q[a[j]]++;
	}
	for (int i = 1; i < 10; ++i) {
		q[i] = q[i] + q[i - 1];//把排在i前面的个数加起来
	}

	for (int i = 5- 1; i >= 0; --i)
	{
		p[q[a[i]] - 1] = a[i];//把数字放进数组里面
		q[a[i]]--;//放进去了一个就减一
	}
	for (int j = 0; j < 5; ++j) {
		a[j] = p[j];//把排序好的数放进数组里面
		cout << a[j] << " ";
	}
	delete[]p;
	delete[]q;
	system("pause");
	return 0;
}
