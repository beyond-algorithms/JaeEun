class Solution:
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """
        ret = []
        for num in range(left, right + 1):
            if self.isSelfDividingNumber(num):
                ret.append(num)

        return ret

    def isSelfDividingNumber(self, num):
        for s in list(map(int, str(num))):
            if not s:
                return False

            if not (num % s == 0):
                return False

        return True
