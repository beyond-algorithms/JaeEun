from unittest.mock import patch
import unittest
from io import StringIO

class ContainersTestCase(unittest.TestCase):
    def formated(self, lines):
        return list(map(lambda line: line.strip(),
                        lines.strip().splitlines()))

    def runFunction(self, user_input, func):
        with patch('builtins.input', side_effect=self.formated(user_input)), patch('sys.stdout', new_callable=StringIO) as out:
            func()

        return out.getvalue().strip()

    def test_1(self):
        user_input = '''
        2
        1 2 3   
                4 5 10           

        '''

        expected = '''
        2 3 4
        8 10 20
        '''

        actual = self.runFunction(user_input, self.solve)

        self.assertEqual(actual, '\n'.join(self.formated(expected)))

    def solve(self):
        t = int(input())
        func = [lambda x: x+1, lambda x: x*2]

        for i in range(t):
            nums = list(map(int, input().split(" ")))
            print(" ".join(list(map(str, [func[i](x) for x in nums]))))


if __name__ == '__main__':
    unittest.main()
