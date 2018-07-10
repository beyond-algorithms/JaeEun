import bisect


class Solution:
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        order = {}
        for move in moves:
            order[move] = order.get(move, 0) + 1

        UD, LR = 0, 0

        UD += order.get('U', 0)
        UD += -order.get('D', 0)

        LR += order.get('L', 0)
        LR += -order.get('R', 0)

        return UD == 0 and LR == 0

    def judgeCircle2(self, moves):
        return moves.count('L') == moves.count('R') and moves.count('U') == moves.count('D')
