from src.Test import Test as T


def main():
    t = int(input().strip())

    for _ in range(t):
        N = int(input().strip())
        pre = list(map(int, input().strip().split()))
        inorder = list(map(int, input().strip().split()))

        print(solve(N, pre, inorder))


def solve(N, pre, inorder):
    mid = getMid(pre, inorder)
    if not mid:
        T.info(pre)
        T.info(inorder)
        T.info(" ")

        return inorder

    newPreLeft = pre[1:mid + 1]
    newInorderLeft = inorder[:mid]
    left = solve(N, newPreLeft, newInorderLeft)

    newPreRight = pre[mid + 1:]
    newInorderRight = inorder[mid + 1:]
    right = solve(N, newPreRight, newInorderRight)

    return [left] + [right] + [inorder[mid]]


def getMid(pre, inorder):
    if not pre:
        return

    mid = pre[0]
    return inorder.index(mid)


user_input = '''
2
7
27 16 9 12 54 36 72
9 12 16 27 36 54 72
6
409 479 10 838 150 441
409 10 479 150 838 441
'''

expected = '''
12 9 16 36 72 54 27
10 150 441 838 479 409
'''

T.runningTest(user_input.strip(), expected.lstrip(), main)
