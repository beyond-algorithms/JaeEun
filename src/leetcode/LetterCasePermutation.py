class Solution:
    def letterCasePermutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        ret = []
        self.helper(S, 0, ret)
        return ret

    def toggle(self, ch):
        if ch.isupper():
            return ch.lower()

        return ch

    def helper(self, S, idx, ret):
        if idx >= len(S):
            ret.append(S)
            return

        if S[idx].isdigit():
            self.helper(S, idx + 1, ret)
            return

        newS = S[:idx] + S[idx].lower() + S[idx + 1:]
        self.helper(newS, idx + 1, ret)

        newS = S[:idx] + S[idx].upper() + S[idx + 1:]
        self.helper(newS, idx + 1, ret)

        return ret
