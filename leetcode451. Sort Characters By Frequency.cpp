/***********************************************************
  >File Name: 451. Sort Characters By Frequency
  >Author: Peng Kai
  >Date:2018-10-19
  >References: 参考了太多，仅供学习，侵权删。
***********************************************************/
//Description: Given a string, sort it in decreasing order based on the frequency of characters.

/*sort函数有三个参数，前两个参数是排序的数组的地址和结束地址，第三个参数是排序的方法，可以从小到大也可以从大到小排序，默认情况是从小到大排序。
bool myfunction (int i,int j) { return (i<j); }
bool myfunction2 (int i,int j) { return (i>j); }
上面两个函数声明是升序排序和降序排序的定义。*/

/*pair是将两个数据组合成为一个数据，当需要这样的需求时就可以使用pair。在STL库中的map就是将key和value放在一起来保存的。
或者是需要返回两个数据的时候，可以选择使用pair。    两个数据的类型可以不相同，pair实际上是一个结构体，其主要的两个成员变量是first和second，
这两个变量可以直接使用。*/

/*在C++和python中字符串都拥有方法append，往字符串后添加文本，此外还有substr、insert等方法可以调用*/

class Solution {
public:
    string frequencySort(string s) {
        string res="";
        unordered_map<char,int> record;
        vector<pair<char,int>> result;
        for(char c:s) record[c]++;
        for(pair<char,int> pair: record){
            result.push_back(pair);
        }
        
        sort(result.begin(),result.end(),compare);
        
        for(pair<char,int> pair:result)
            res.append(pair.second,pair.first);
        return res;
    }
    static bool compare(pair<char,int>a,pair<char,int>b){
        return a.second>b.second;
    }
};
