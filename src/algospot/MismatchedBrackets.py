from src.Test import Test as T


def pair(bracket):
    if bracket == ')':
        return '('

    if bracket == '}':
        return '{'

    if bracket == ']':
        return '['

    raise False


def main():
    t = int(input().strip())
    for _ in range(t):
        stack = []
        brackets = input().strip()

        print(solve(stack, brackets))


def solve(stack, brackets):
    for bracket in brackets:
        if not stack or bracket in '({[':
            stack.append(bracket)
            continue

        if stack[-1] == pair(bracket):
            stack.pop()

    if not stack:
        return "YES"
    else:
        return "NO"


def opposite2(bracket):
    if bracket == '(':
        return ')'

    if bracket == '{':
        return '}'

    if bracket == '[':
        return ']'


def solve2(stack, brackets):
    for bracket in brackets:
        o_bracket = opposite2(bracket)
        idx = brackets.index(o_bracket)


user_input = '''
3
()()
({[}])
({}[(){}])
'''

expected = '''
YES
NO
YES
'''

T.runningTest(user_input.strip(), expected.lstrip(), main)
