from src.Test import Test as T

cInfo = []
minCounselTime = 0
totalWorkTime = 0
dp = {}


def main():
    global minCounselTime, totalWorkTime, dp
    minCounselTime = 0

    t = int(input().strip())
    for case in range(t):
        dp.clear()
        totalCustomer, minCounselTime, totalWorkTime = map(int, input().strip().split())

        global cInfo
        cInfo = []
        for _ in range(totalCustomer):
            wannaTime, penalty = map(int, input().split())
            cInfo.append((wannaTime, penalty))

        ret = getMaxScore(totalWorkTime, 0)
        print("#" + str(case + 1) + " " + str(ret))


def getMaxScore(currentWorkTime, idx):
    if idx >= len(cInfo):
        return 0
    if currentWorkTime < minCounselTime:
        return 0

    if (currentWorkTime, idx) in dp:
        return dp.get((currentWorkTime, idx))

    ret = 0
    wanna, penalty = cInfo[idx]
    for actualTime in reversed(range(minCounselTime, wanna + 1)):
        currentScore = 10
        p = (wanna - actualTime) * penalty
        currentScore -= p

        nextTime = currentWorkTime - actualTime
        if nextTime < 0:
            continue

        ret = max(ret, currentScore + getMaxScore(nextTime, idx + 1))

    dp[(currentWorkTime, idx)] = ret
    return ret


user_input = '''
4
8 5 30
19 1
12 2
6 1
13 1
8 3
15 2
11 2
7 1
2 5 20
15 2
10 3
1 5 10
15 1
20 8 190
15 1
20 1
22 2
8 2
11 1
13 1
15 1
44 3
27 2
12 2
15 1
20 1
22 2
8 2
11 1
13 1
15 1
44 3
27 2
12 2
'''

expected = '''
#1 23
#2 10
#3 5
#4 100
'''

T.runningTest(user_input.strip(), expected.lstrip(), main)
