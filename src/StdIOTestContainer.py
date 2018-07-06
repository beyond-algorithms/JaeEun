from unittest.mock import patch
import unittest
from io import StringIO
import sys 
import logging

logger = logging.getLogger()
logger.level = logging.DEBUG


class StdIOTestContainer(unittest.TestCase):
    @staticmethod
    def formated(lines):
        return list(map(lambda line: line.strip(),
                        lines.strip().splitlines()))

    @staticmethod
    def runFunction(user_input, func):
        with patch('builtins.input', side_effect=StdIOTestContainer.formated(user_input)), patch('sys.stdout', new_callable=StringIO) as out:
            func()

        return out.getvalue().strip()

    @staticmethod
    def runningTest(user_input, expected, func):
        actual = StdIOTestContainer.runFunction(user_input, func)

        testCase = unittest.TestCase()
        testCase.assertEqual(actual, '\n'.join(
            StdIOTestContainer.formated(expected)))

        StdIOTestContainer.testSimpleMsg("done")

    @staticmethod
    def testSimpleMsg(msg):
        stream_handler = logging.StreamHandler(sys.stdout)
        logger.addHandler(stream_handler)

        try:
            logging.getLogger().info(msg)
        finally:
            logger.removeHandler(stream_handler)
