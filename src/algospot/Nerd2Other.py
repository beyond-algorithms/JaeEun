from src.Test import Test as T
from bisect import bisect_left
from collections import OrderedDict
import heapq


def main():
    t = int(input().strip())

    for _ in range(t):
        N = int(input().strip())

        ret = 0
        accept_p = []
        accept_q = []
        for _ in range(N):
            p, q = map(int, input().strip().split())
            ret += solve(accept_p, accept_q, p, q)

        print(ret)


# accept_P는 오름차순 정렬되어있다고 가정한다.
# (bisect를 이용하여 배열에 삽입)
def solve(accept_P, accept_Q, p, q):
    upper_idx = bisect_left(accept_P, p)
    N = len(accept_P)

    # q가 기존에 있는 것 보다 작아서, 새로 들어오는 게 무시되는 경우
    if upper_idx < N and q < accept_Q[upper_idx]:
        return N

    # 여기까지 왔다면, p는 기존것들보다는 큰데 q가 말썽인거다.
    # 어떤건 크고, 어떤건 작다. accept_Q 안에 있는 애들 중, q보다 작은 애들은 다 지워야 한다.
    lower = upper_idx

    # 어디까지 가장 작은지 찾기
    while lower > 0:
        if accept_Q[lower - 1] > q:
            break
        lower -= 1

    del accept_P[lower:upper_idx]
    del accept_Q[lower:upper_idx]

    # insert와 bisect_left를 이용해서 정렬삽입지점을 찾는다.
    i = bisect_left(accept_P, p)
    accept_P.insert(i, p)
    accept_Q.insert(i, q)

    return len(accept_P)


user_input = '''
2
4
72 50
57 67
74 55
64 60
5
1 5
2 4
3 3
4 2
5 1
'''

expected = '''
8
15
'''

T.runningTest(user_input.strip(), expected.lstrip(), main2)
