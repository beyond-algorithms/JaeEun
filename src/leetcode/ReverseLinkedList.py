class Solution:
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head

        store = []
        node = head
        while True:
            if not node:
                break

            store.append(node)
            node = node.next

        store = store[::-1]
        for i in range(len(store) - 1):
            last, cur = store[i], store[i + 1]
            last.next = cur

        store[-1].next = None

        return store[0]

#
#
# public ListNode reverseList(ListNode head) {
#     ListNode prev = null;
#     ListNode curr = head;

#     while (curr != null) {
#         ListNode nextTemp = curr.next;
#         curr.next = prev;
#         prev = curr;
#         curr = nextTemp;
#     }

#     return prev;
# }
#
# public ListNode reverseList(ListNode head) {
#     if (head == null || head.next == null) return head;

#     ListNode p = reverseList(head.next);

#     head.next.next = head;
#     head.next = null;

#     return p;
# }