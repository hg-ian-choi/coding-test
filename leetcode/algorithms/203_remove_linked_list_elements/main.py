from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class RemoveLinkedListElements:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        if head == None:
            return None

        newHead = ListNode(0)
        newHead.next = head
        currentHead = newHead

        while currentHead.next != None:
            if currentHead.next.val == val:
                currentHead.next = currentHead.next.next
            else:
                currentHead = currentHead.next

        return newHead.next


    # Solution
    # solution 1
    def solution1(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        dummy_head = ListNode(-1)
        dummy_head.next = head

        current_node = dummy_head
        while current_node.next != None:
            if current_node.next.val == val:
                current_node.next = current_node.next.next
            else:
                current_node = current_node.next

        return dummy_head.next

    # solution 2
    def solution2(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        prev, curr = None, head
        while curr:
            if curr.val == val:
                if prev:
                    prev.next = curr.next
                else:
                    head = curr.next
                curr = curr.next
            else:
                prev, curr = curr, curr.next
        return head
