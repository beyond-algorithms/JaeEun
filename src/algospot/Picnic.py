import sys
sys.path.append('.')

from src.StdIOTestContainer import StdIOTestContainer as T

def solve():
    t = int(input().strip())

    for _ in range(t):
        n, m = list(map(int, input().strip().split(" ")))
        members = list(map(int, input().strip().split(" ")))

        areFriends = [[False for _ in range(n)] for _ in range(n)]
        it = iter(members)
        for m1 in it:
            m2 = next(it)
            areFriends[m1][m2] = True
            areFriends[m2][m1] = True

        isTaken = [False for _ in range(n)]
        print(_solve(areFriends, isTaken, 0))

def _solve(areFriends, isTaken, lastIdx):
    unTaken = findUntaken(isTaken, lastIdx)    
    if unTaken == -1:
        return 1

    ret = 0
    for target in range(unTaken+1, len(areFriends)):
        if areFriends[unTaken][target] and not isTaken[target]:
            isTaken[unTaken] = isTaken[target] = True

            ret += _solve(areFriends, isTaken, lastIdx+1)

            isTaken[unTaken] = isTaken[target] = False

    return ret

def findUntaken(isTaken, lastIdx):
    for i in range(lastIdx, len(isTaken)):
        if not isTaken[i]:
            return i
    
    return -1



user_input = '''
3 
2 1 
0 1 
4 6 
0 1 1 2 2 3 3 0 0 2 1 3 
6 10 
0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5
'''

expected = '''
1
3
4
'''

T.runningTest(user_input.strip(), expected.lstrip(), solve)
