from src.Test import Test as T


def main():
    t = int(input().strip())

    for _ in range(t):
        N, K = list(map(int, input().strip().split()))
        alive = N
        grave = set()

        print(" ".join(map(str, solve(N, K, alive, grave, 0))))

        T.info("   ----     ")


def get_nextIdx(N, grave, idx, K):
    step = K - 1
    nextIdx = idx

    while True:
        T.info(nextIdx)



        if nextIdx == N:
            nextIdx = 0


        if step == 0:
            return nextIdx % N




def kill(idx, grave):
    grave.add(idx)


def solve(N, K, alive, grave, idx):
    if alive == 2:
        total = {x for x in range(N)}
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
