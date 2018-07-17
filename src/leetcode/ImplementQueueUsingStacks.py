class MyQueue:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.front = []
        self.back = []

    def push(self, x):
        """
        Push element x to the back of queue.
        :type x: int
        :rtype: void
        """
        self.front.append(x)

    def pop(self):
        """
        Removes the element from in front of queue and returns that element.
        :rtype: int
        """
        self._verifying()
        return self.back.pop()

    def peek(self):
        """
        Get the front element.
        :rtype: int
        """
        self._verifying()
        return self.back[-1]

    def empty(self):
        """
        Returns whether the queue is empty.
        :rtype: bool
        """

        if not self.front and not self.back:
            return True

        return False

    def _verifying(self):
        if not self.back:
            for _ in range(len(self.front)):
                e = self.front.pop()
                self.back.append(e)
