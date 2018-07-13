class Solution:
    def peakIndexInMountainArray(self, A):
        return self.helper(A, 0, len(A))

    def helper(self, A, lo, hi):
        idx = (lo + hi) // 2
        # assert(0 < idx < len(A))
        # print(A[idx+1])

        if (A[idx - 1] < A[idx]) and (A[idx] > A[idx + 1]):
            return idx

        if A[idx] < A[idx + 1]:
            return self.helper(A, idx + 1, hi)

        if A[idx] > A[idx + 1]:
            return self.helper(A, lo, idx - 1)

    def peakIndexInMountainArray2(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        last = A[0]
        for i, num in enumerate(A):
            if last > num:
                return i - 1

            last = num

    def peakIndexInMountainArray3(self, A):
        lo, hi = 0, len(A) - 1

        while lo < hi:
            mi = (lo + hi) / 2

            if A[mi] < A[mi + 1]:
                lo = mi + 1
            else:
                hi = mi
        return lo
