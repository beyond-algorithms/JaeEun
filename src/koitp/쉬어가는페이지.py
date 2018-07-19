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
3
40 2 2 7
5 10 15 20 25 30 35
50 23 3 2
43 39
100 35 1 10
10 9 8 7 6 5 4 1 2 3

'''

expected = '''
#1 3
#2 2
#3 0
'''

T.runningTest(user_input.strip(), expected.lstrip(), main)
