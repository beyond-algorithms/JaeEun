import sys
sys.path.append('.')

from src.StdIOTestContainer import StdIOTestContainer as T

def solve():
    line = input().split(" ")

    print(" ".join(list(map(str, [int(x)*2 for x in line]))))


T.runningTest("1 2 4", "2 4 8", solve)
