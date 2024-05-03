class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        li1  = version1.split('.')
        li2  = version2.split('.')
        n = len(li1)
        m = len(li2)
        for i in range(0,n):
            li1[i] = int(li1[i])
        for i in range(0,m):
            li2[i] = int(li2[i])
            
        
        for i in range(0,min(n,m)):
            if li1[i]<li2[i]:
                return -1
            elif li1[i]>li2[i]:
                return 1
        if(n>m):
            for i in range(m,n):
                if(li1[i]!=0):
                    return 1
            return 0
        if(n<m):
            for i in range(n,m):
                if(li2[i]!=0):
                    return -1
            return 0
        else:
            return 0
        