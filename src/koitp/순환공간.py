from src.Test import Test as T


def solve():
    t = int(input())
    for _ in range(t):
        row, column, r1, c1, r2, c2 = map(int, input().strip().split())

        y = abs(r1 - r2)
        x = abs(c1 - c2)

        ny = abs(y - row)
        nx = abs(x - column)

        print("#" + str(_ + 1) + " " + str(min(y, ny) + min(x, nx)))


user_input = '''
3
3 3 0 0 2 2
4 6 3 4 2 0
394 549 254 477 15 414
'''

expected = '''
#1 2
#2 3
#3 218
'''

T.runningTest(user_input.strip(), expected.lstrip(), solve)
