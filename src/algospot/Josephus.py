from src.Test import Test as T


def main():
    t = int(input().strip())

    for _ in range(t):
        N, K = list(map(int, input().strip().split()))

        print(" ".join(list(map(str, solve(N, K)))))


def solve(N, K):
    alive = N

    p = [x for x in range(N)]

    idx = 0
    while alive > 2:
        p.pop(idx)

        idx = (idx + K - 1) % len(p)
        alive -= 1

    return list(map(lambda x: x + 1, p))


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
