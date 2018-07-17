class Solution:
    def lemonadeChange(self, bills):
        changes = {}
        for bill in bills:
            if self.canProvideChanges(changes, int(bill)):
                continue
            return False

        return True

    def canProvideChanges(self, changes, bill):
        # 10달러 인경우 -> 5달러 1개
        # 20달러 -> 5달러 3개, 5달러1개+10달러1개
        if bill == 5:
            changes[5] = changes.get(5, 0) + 1
            return True

        if bill == 10:
            if changes.get(5, 0) <= 0:
                return False

            changes[5] = changes.get(5, 0) - 1
            changes[10] = changes.get(10, 0) + 1
            return True

        if bill == 20:
            if changes.get(5, 0) >= 1 and changes.get(10, 0) >= 1:
                changes[5] = changes.get(5, 0) - 1
                changes[10] = changes.get(10, 0) - 1
                return True

            if changes.get(5, 0) >= 3:
                changes[5] = changes.get(5, 0) - 3
                return True

            return False

        else:
            raise Exception("err")
