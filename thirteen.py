#对于一个给定的 source 字符串和一个 target 字符串，你应该在 source 字符串中找出 target 字符串出现的第一个位置(从0开始)。如果不存在，则返回 -1。
class Solution:
    """
    @param source: 
    @param target: 
    @return: return the index
    """
    def strStr(self, source, target):
        # Write your code here
        if source is None or target is None:
            return -1
        if len(source) < len(target):
            return -1
        if source == target:
            return 0
        for i in range(len(source)-len(target)+1):
            if source[i:i+len(target)]==target:
                return i
            if i==len(source)-len(target) and source !=target:
                return -1
