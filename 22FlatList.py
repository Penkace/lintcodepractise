class Solution(object):

    # @param nestedList a list, each element in the list 
    # can be a list or integer, for example [1,2,[1,2]]
    # @return {int[]} a list of integer
    def flatten(self, nestedList):
        # Write your code here
        self.L=[]
        if nestedList is None:
            return []
        if type(nestedList)!=list:
            self.L.append(nestedList)
            return self.L
        else:
            self.findUntill(nestedList)
        return self.L
    def findUntill(self,alist):
        if alist is None:
            return []
        for i in alist:
            if type(i)==list:
                self.findUntill(i)
            else:
                self.L.append(i)
