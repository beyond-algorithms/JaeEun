from src.Test import Test as T


def solve():
    t = int(input().strip())

    for _ in range(t):
        n, m = list(map(int, input().strip().split()))
        members = list(map(int, input().strip().split()))

        are_friends = [[False for _ in range(n)] for _ in range(n)]
        it = iter(members)
        for m1 in it:
            m2 = next(it)
            are_friends[m1][m2] = True
            are_friends[m2][m1] = True

        is_taken = [False for _ in range(n)]
        print(_solve(are_friends, is_taken, 0))


def _solve(are_friends, is_taken, last_idx):
    un_taken = find_untaken(is_taken, last_idx)
    if un_taken == -1:
        return 1

    ret = 0
    for target in range(un_taken + 1, len(are_friends)):
        if are_friends[un_taken][target] and not is_taken[target]:
            is_taken[un_taken] = is_taken[target] = True

            ret += _solve(are_friends, is_taken, last_idx + 1)

            is_taken[un_taken] = is_taken[target] = False

    return ret


def find_untaken(is_taken, last_idx):
    for i in range(last_idx, len(is_taken)):
        if not is_taken[i]:
            return i

    return -1


user_input = '''
3
2 1
0 1
4 6
0 1 1 2 2 3 3 0 0 2 1 3
6 10
0 1 0 2 1 2 1 3 1 4 2 3 2 4 3 4 3 5 4 5
'''

expected = '''
1
3
4
'''

T.runningTest(user_input.strip(), expected.lstrip(), solve)
