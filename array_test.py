import unittest

class TestArray(unittest.TestCase):
    def sum(arr=[]):
        sum = 0
        for i in arr:
            sum += i
        return sum

    def test_sum(self): 
        self.assertEqual(sum([1, 2, 3, 4]), 10, "dkdk")
