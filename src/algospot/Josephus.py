from src.Test import Test as T


def main():
    t = int(input().strip())

    for _ in range(t):
        N, K = list(map(int, input().strip().split()))
        alive = N
        grave = set()

        print(" ".join(map(str, solve(N, K, alive, grave, 1))))

        T.info("   ----     ")


def get_nextIdx(N, grave, idx, K):
    step = K - 1
    nextIdx = idx

    while True:
        T.info(nextIdx)

        if step == 0:
            return nextIdx

        if nextIdx == N:
            return nextIdx

        step -= 1
        nextIdx += 1



def kill(idx, grave):
    grave.add(idx)


def solve(N, K, alive, grave, idx):
    if alive == 2:
        total = {x+1 for x in range(N)}
        T.info("grave: " + str(grave))
        return list(total - grave)

    kill(idx, grave)
    nextIdx = get_nextIdx(N, grave, idx, K)
    T.info("returned: " + str(nextIdx))
    T.info("--------")
    return solve(N, K, alive - 1, grave, nextIdx)


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
