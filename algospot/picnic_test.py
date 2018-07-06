import unittest
import sys

class TestPicnic(unittest.TestCase):

    def test_main(self):
        inputString = "a b c"
        expected = ["a", "b", "c"]

        sys.stdin = inputString

        self.assertEqual(expected, "")

    def split(self):
        strings = input()
        return strings.split(" ")

if __name__ == '__main__':
    unittest.main()
