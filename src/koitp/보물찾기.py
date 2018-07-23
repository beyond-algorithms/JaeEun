from src.Test import Test as T
from collections import defaultdict
from heapq import *


def main():
    t = int(input())
    for _ in range(t):
        numberOfRuins, numberOfClues, timeout = map(int, input().strip().split())

        path = []
        for __ in range(numberOfClues):
            _from, _to = input().strip().split()
            path.append((_from, _to, 1))

        T.info(path)
        ret = find(path, "1", str(numberOfRuins))
        T.info(ret)


        print("#" + str(_ + 1) + " " + str(ret))


def find(edges, f, t):
    g = defaultdict(list)
    for l, r, c in edges:
        g[l].append((c, r))

    q, seen, mins = [(0, f, ())], set(), {f: 0}
    while q:
        (cost, v1, path) = heappop(q)
        if v1 not in seen:
            seen.add(v1)
            path = (v1, path)
            if v1 == t:
                return (cost, path)

            for c, v2 in g.get(v1, ()):
                if v2 in seen:
                    continue
                prev = mins.get(v2, None)
                next = cost + c
                if prev is None or next < prev:
                    mins[v2] = next
                    heappush(q, (next, v2, path))

    return float("inf")


user_input = '''
5
2 1 1
1 2
3 1 3
2 3
4 2 3
1 2
1 3
6 5 2
1 3
3 2
2 5
2 6
5 6
6 5 3
1 3
3 2
2 5
2 6
5 6
'''

expected = '''
#1 1
#2 -1
#3 -1
#4 -1
#5 3
'''

T.runningTest(user_input.strip(), expected.lstrip(), main)
