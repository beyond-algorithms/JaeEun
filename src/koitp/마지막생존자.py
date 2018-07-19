from src.Test import Test as T

dy = [-1, -1, -1, 0, 0, 1, 1, 1, 0]
dx = [-1, 0, 1, -1, 1, -1, 0, 1, 0]


def main():
    t = int(input())
    for _ in range(t):
        N = int(input().strip())

        grid = [[int(x) for x in input().strip().split()] for _ in range(N)]
        result = solve(grid)

        print("#" + str(_ + 1) + " " + str(result))


def solve(grid):
    ret = 0
    for y in range(len(grid)):
        for x in range(len(grid[0])):
            if isValid(grid, y, x):
                ret += 1
    return ret


def isValid(grid, y, x):
    water = 0
    mountain = 0
    grassy = 0

    for i in range(9):
        ny = y + dy[i]
        nx = x + dx[i]

        if not (0 <= ny < len(grid)):
            continue
        if not (0 <= nx < len(grid[0])):
            continue

        region = grid[ny][nx]
        if region == 0:
            return False
        if region == 1:
            water += 1
        elif region == 2:
            mountain += 1
        elif region == 3:
            grassy += 1

    if water > 0 and mountain > 0 and grassy > 0:
        return True
    return False


user_input = '''
2
5
0 1 1 2 1
3 2 1 3 2
2 1 3 1 0
0 1 2 2 3 
0 0 1 1 1
5
1 1 1 1 1
2 2 2 2 2
3 3 3 3 3
2 2 2 2 2
1 1 1 1 1
'''

expected = '''
#1 7
#2 10
'''

T.runningTest(user_input.strip(), expected.lstrip(), main)
