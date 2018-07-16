"""
# Employee info
class Employee:
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates
"""


class Solution:
    def getImportance(self, employees, id):
        """
        :type employees: Employee
        :type id: int
        :rtype: int
        """
        people = {}
        for em in employees:
            people[em.id] = (em.importance, em.subordinates)

        cand = [id]
        ret = 0
        while cand:
            targetId = cand.pop()
            imp, sub = people.get(targetId)
            ret += imp

            if sub:
                cand += sub

        return ret

    def getImportance2(self, employees, id):
        """
        :type employees: Employee
        :type id: int
        :rtype: int
        """

        emap = {e.id: e for e in employees}
        return self.dfs(id, emap)

    def dfs(self, eid, emap):
        employee = emap[eid]
        return employee.importance + sum(self.dfs(ed, emap) for ed in employee.subordinates)
