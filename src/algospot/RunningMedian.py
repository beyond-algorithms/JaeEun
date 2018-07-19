from src.Test import Test as T

import heapq


def main():
    t = int(input().strip())

    for _ in range(t):
        N, a, b = map(int, input().strip().split())
        print(solve(N, a, b) % 20090711)


def solve(N, a, b):
    mAxHeap = []
    mInHeap = [1983]

    ret = 0
    lastItem = 1983

    for _ in range(N):
        middle = getMiddleValue(mAxHeap, mInHeap) % 20090711
        ret += middle
        ret %= 20090711

        nextItem = (lastItem * a + b) % 20090711
        lastItem = nextItem

        if nextItem > middle:
            heapq.heappush(mInHeap, nextItem)
        else:
            heapq.heappush(mAxHeap, nextItem)

    return ret


def getMiddleValue(mAxHeap, mInHeap):
    if len(mInHeap) > len(mAxHeap):
        ret = heapq.heappop(mInHeap)
        heapq.heappush(mInHeap, ret)
        return ret
    else:
        heapq._heapify_max(mAxHeap)
        ret = heapq._heappop_max(mAxHeap)
        heapq.heappush(mAxHeap, ret)
        return ret


user_input = '''
3
10 1 0
10 1 1
10000 1273 4936
'''

expected = '''
19830
19850
2448920
'''

T.runningTest(user_input.strip(), expected.lstrip(), main)
