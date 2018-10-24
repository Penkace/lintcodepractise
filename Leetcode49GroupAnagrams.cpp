/*******************************************************************
  >File Name: 49. Group Anagrams
  >Author: Peng Kai
  >Date: 2018-10-24
  >References: https://blog.csdn.net/zjajgyy/article/details/73718698
*******************************************************************/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> res;//创建一个string，vector<string>的键值表
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            if(res.find(s)!=res.end()){            //如果在表中能够找到，则把该字符串放入到res中
                res[s].push_back(strs[i]);         //因为查找表res的第二个维度是一个vector数组，所以可以把找到的strs[i]给存储到这个anagrams中
            }else{
                vector<string>result={strs[i]};    //否则就需要往表中添加该字符串
                res[s]=result;
            }
        }
        vector<vector<string>>result;
        for(unordered_map<string,vector<string>>::iterator iter=res.begin();iter!=res.end();iter++){
            result.push_back(iter->second);//建立一个输出结果的字符串，遍历res字符串，把键对应的值字符串全部压入到result的结果字符串中
        }
        return result;
    }
};
