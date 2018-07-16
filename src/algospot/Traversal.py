from src.Test import Test as T


def main():
    t = int(input().strip())

    for _ in range(t):
        N = int(input().strip())
        pre = list(map(int, input().strip().split()))
        inorder = list(map(int, input().strip().split()))

        print(solve(N, pre, inorder))


def solve(N, pre, inorder):
    left, root, right = inorder_LeftRootRight(pre, inorder)

    if not root:
        return left, right, root

    mid = len(left)
    newPre = pre_LeftRootRight(pre[1: mid + 1], inorder[:mid])
    newInorder = inorder_LeftRootRight(pre[mid + 1:], inorder[mid + 1:])

    return left + right + solve(N, newPre, newInorder)


def inorder_LeftRootRight(pre, inorder):
    if not pre:
        return None

    root = pre[0]
    mid = inorder.index(root)

    left = inorder[:mid]
    right = inorder[mid + 1:]

    return left, root, right


def pre_LeftRootRight(pre, inorder):
    if not pre:
        return None

    T.info(pre)
    T.info(inorder)

    root = pre[0]
    mid = inorder.index(root)

    left = inorder[:mid]
    len(left)

    return pre[1 + mid:], root, pre[mid + 1:]


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
