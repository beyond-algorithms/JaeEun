def mergeTreesBFS(self, t1, t2):
    if not t1:
        return t2

    BFS = [(t1, t2)]

    for n1, n2 in BFS:
        if not n2:
            continue

        n1.val += n2.val

        if not n1.left:
            n1.left = n2.left
        else:
            BFS.append((n1.left, n2.left))

        if not n1.right:
            n1.right = n2.right
        else:
            BFS.append((n1.right, n2.right))

    return t1


def mergeTreesDFS(self, t1, t2):
    def _merge(_from, _to):
        if not _from:
            return

        _to.val += _from.val

        if not _to.left:
            _to.left = _from.left
        else:
            self._merge(_from.left, _to.left)

        if not _to.right:
            _to.right = _from.right
        else:
            self._merge(_from.right, _to.right)

    if not t1:
        return t2

    if not t2:
        return t1

    self._merge(t1, t2)

    return t2


# other answers


def mergeTrees1(self, t1, t2):
    if t1 is None or t2 is None:
        return t1 or t2

    t3 = TreeNode(t1.val + t2.val)
    t3.left = self.mergeTrees1(t1.left, t2.left)
    t3.right = self.mergeTrees1(t1.right, t2.right)
    return t3


def mergeTrees2(self, t1, t2):
    if t1 is None:
        return t2
    if t2 is None:
        return t1
    else:
        t1.val += t2.val
        t1.left = self.mergeTrees2(t1.left, t2.left)
        t1.right = self.mergeTrees2(t1.right, t2.right)
        return t1
