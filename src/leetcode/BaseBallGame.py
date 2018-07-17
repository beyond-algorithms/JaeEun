class Solution:
    def calPoints(self, ops):
        history = []
        ret = 0

        for op in ops:
            if op.isdigit():
                op = int(op)
                ret += op

                history.append(op)
                continue

            if op.find("-") >= 0:
                op = -int(op[1:])
                ret += op

                history.append(op)
                continue

            if op == "C":
                last = history.pop()
                inverse = -last

                ret += inverse
                continue

            if op == "D":
                last = history[-1] * 2

                ret += last
                history.append(last)
                continue

            if op == "+":
                LL, L = history[-2], history[-1]
                plus = LL + L

                ret += plus
                history.append(plus)
                continue

        return ret


class Solution2:
    def calPoints(self, ops):
        """
        :type ops: List[str]
        :rtype: int
        """
        stack = []
        for i in ops:
            if i == '+':
                stack.append(stack[-1] + stack[-2])
            elif i == 'C':
                stack.pop()
            elif i == 'D':
                stack.append(2 * stack[-1])
            else:
                stack.append(int(i))
        return sum(stack)
