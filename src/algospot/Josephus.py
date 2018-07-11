from src.Test import Test as T


def main():
    t = int(input().strip())

    for _ in range(t):
        N, K = list(map(int, input().strip().split()))

        print(" ".join(list(map(str, solve(N, K)))))


def solve(N, K):
    p = [x for x in range(N + 1)]
    T.info(p.pop(0))
    alive = N

    idx = 1
    while alive > 2:
        idx = p.pop(idx) + 1

        if idx == N:
            idx = 1

        for _ in range(K - 1):
            idx += 1
            if idx == N:
                idx = 0

    return p


user_input = '''
2
6 3
40 3
'''

expected = '''
3 5
11 26
'''

T.runningTest(user_input.strip(), expected.lstrip(), main)
