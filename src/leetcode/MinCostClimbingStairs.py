class Iteration:
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """

        if len(cost) < 2:
            return cost[0]

        dp = [-1 for _ in range(len(cost) + 1)]
        dp[1] = cost[0]
        dp[2] = cost[1]

        for i in range(3, len(dp)):
            dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i - 1]

        print(dp)
        return min(dp[len(dp) - 1], dp[len(dp) - 2])


class Recursion:
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        self.cost = cost
        self.dp = {}

        if len(cost) < 2:
            return self.solve(0)

        return min(self.solve(0), self.solve(1))

    def solve(self, idx):
        if idx >= len(self.cost):
            return 0

        if idx in self.dp:
            return self.dp[idx]

        val = self.cost[idx] + min(self.solve(idx + 1), self.solve(idx + 2))
        self.dp[idx] = val
        return val
