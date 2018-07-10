class Solution:
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        res = []
        for i in range(len(A[0])):
            new_inner = []
            for inner in A:
                new_inner.append(inner[i])
            res.append(new_inner)

        return res
