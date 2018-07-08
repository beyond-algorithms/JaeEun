import sys
sys.path.append('.')
import logging
from src.StdIOTestContainer import StdIOTestContainer as T

def solve():
    t = int(input().strip())
    for _ in range(t):
        nLine = int(input())

        sentenses = ""
        for _ in range(nLine):
            sentenses += input()
        
        totalSentense = sentenses.split("-")
        totalSentense = "".join([" " if not sen else sen for sen in totalSentense])

        splited = totalSentense.split(" ")
        T.info(splited)

        ret = list(map(len, splited))
        ret = [x for x in ret if x]
        T.info(ret)
        print(sum(ret) / len(ret))

user_input = '''
4
3
hello-
there-
world
4
a-
-
-
b
3
i am ver-
y sleepy arent-
 you 
1
jong-man rules
'''
expected = '''
15.000
1.000
3.500
4.000
'''

T.runningTest(user_input, expected, solve)
