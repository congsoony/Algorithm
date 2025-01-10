
class Solution(object):
    def removeElements(self, head, val):
     
        while head and head.val==val:
            head = head.next
        tail = head
        before = head

        while tail:
            if tail.val == val:
                before.next= tail.next
                tail.next = None
                tail = before.next
            else:
                before = tail
                tail = tail.next
        return head
