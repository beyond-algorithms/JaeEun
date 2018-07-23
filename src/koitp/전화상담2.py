cInfo = []
minCounselTime = 0
totalWorkTime = 0


def main():
    global minCounselTime, totalWorkTime, cInfo

    t = int(input().strip())
    for case in range(t):
        minCounselTime = 0
        totalWorkTime = 0
        cInfo = []
        cache = [[-1 for x in range(10001)] for _ in range(101)]

        totalCustomer, minCounselTime, totalWorkTime = map(int, input().strip().split())

        for _ in range(totalCustomer):
            wannaTime, penalty = map(int, input().split())
            cInfo.append((wannaTime, penalty))

        ret = getMaxScore(cache, totalWorkTime, 0, 0)
        print("#" + str(case + 1) + " " + str(ret))


def getMaxScore(dp2, currentWorkTime, idx, prevTime):
    if idx >= len(cInfo):
        return 0
    if currentWorkTime < minCounselTime:
        return 0

    if dp2[idx][prevTime] != -1:
        return dp2[idx][prevTime]

    ret = 0
    wanna, penalty = cInfo[idx]
    for actualTime in reversed(range(minCounselTime, wanna + 1)):
        currentScore = 10
        p = (wanna - actualTime) * penalty
        currentScore -= p

        nextTime = currentWorkTime - actualTime
        if nextTime < 0:
            continue

        ret = max(ret, currentScore + getMaxScore(dp2, nextTime, idx + 1, nextTime))

    dp2[idx][prevTime] = ret
    return ret


main()
