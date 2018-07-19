from src.Test import Test as T


def main():
    t = int(input().strip())
    for _ in range(t):
        totalPage, S, J, K = map(int, input().strip().split())
        restPages = set()

        for page in input().strip().split():
            restPages.add(int(page))

        ret = solve(totalPage, S, J, K, restPages)

        print("#" + str(_ + 1) + " " + str(ret))


def solve(totalPage, S, J, K, restPages):
    currentPage = S

    ret = 0
    while True:
        if currentPage > totalPage:
            break

        if currentPage in restPages:
            ret += 1

        currentPage += (J + 1)

    return ret


user_input = '''
1
8 5 30
19 1
12 2
6 1
13 1
8 3
15 2
11 2
7 1
'''

expected = '''
#1 23
'''

T.runningTest(user_input.strip(), expected.lstrip(), main)
