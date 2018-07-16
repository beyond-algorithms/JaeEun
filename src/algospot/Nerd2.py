from src.Test import Test as T


def main():
    t = int(input().strip())

    for _ in range(t):
        N = int(input().strip())

        s = set()
        for _ in range(N):
            p, q = list(map(int, input().strip().split()))
            s.add((p, q))

        print(solve(N, sorted(list(s), key=lambda x: x[0])))


def solve(N, people):
    _min = 987654321
    _max = -1
    _max_idx = -1

    ret = 0
    accept = []
    for i, (_, q) in enumerate(people):
        ret += len(accept)

        if q > _max:
            _max = q
            _max_idx = i
            accept.clear()
            accept.append(q)
            continue

        if q < _min:
            _min = q
            accept.append(q)
            continue

        accept = list(filter(lambda x: x > q, accept[_max_idx:]))

    ret += len(accept)
    return ret


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

T.runningTest(user_input.strip(), expected.lstrip(), main)
