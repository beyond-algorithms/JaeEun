from src.Test import Test as T
import heapq

dp = {}


def main():
    t = int(input().strip())
    for _ in range(t):
        dp.clear()
        N, P, M = map(int, input().strip().split())
        numbers = list(map(int, input().strip().split()))

        ret = makeBigNumber(P, M, numbers, 0, 0)
        print("#" + str(_ + 1) + " " + str(ret))


def makeBigNumber(P, M, numbers, idx, acc):
    if idx == len(numbers):
        assert P == 0 and M == 0
        return acc

    if (idx, P, M) in dp:
        return dp[(idx, P, M)]

    plus = 0
    minus = 0
    if P == 0 and M == 0:
        return acc
    if P > 0:
        plus = makeBigNumber(P - 1, M, numbers, idx + 1, acc + numbers[idx])
    if M > 0:
        minus = makeBigNumber(P, M - 1, numbers, idx + 1, acc - numbers[idx])

    ret = max(plus, minus)

    dp[(idx, P, M)] = ret

    return ret


user_input = '''
11
5 2 2
-37 33 0 -22 -32 
10 8 1
30 4 -16 -50 -34 -18 -24 -17 19 -38 
15 10 4
7 -41 -11 47 22 -6 -11 -31 -35 -17 -33 5 46 5 36 
20 17 2
-23 16 33 7 0 7 18 39 35 14 -9 38 -19 -26 17 18 0 29 35 39 
25 13 11
15 -30 42 38 25 2 28 16 34 37 31 15 -36 -31 40 27 -21 -20 50 -35 -31 -50 37 -45 47
1 0 0
9
6 4 1
1 2 -1 1 2 3
4 3 0
1 2 3 4
3 1 1
1 1 555
2 1 0
10 29
2 0 1
20 14
'''

expected = '''
#1 50
#2 -44
#3 263
#4 358
#5 749
#6 9
#7 10
#8 10
#9 555
#10 39
#11 6
'''

T.runningTest(user_input.strip(), expected.lstrip(), main)
