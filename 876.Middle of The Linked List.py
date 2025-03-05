# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        # Use the two-pointer technique (slow and fast pointers)
        slow = fast = head
        
        # Move fast pointer by 2 steps and slow pointer by 1 step until fast reaches the end
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        # Return the slow pointer, which is at the middle node
        return slow

# Helper function to convert a Python list to a linked list
def list_to_linkedlist(nums):
    head = ListNode(nums[0])
    current = head
    for num in nums[1:]:
        current.next = ListNode(num)
        current = current.next
    return head

# Helper function to print the linked list (for testing purposes)
def print_linkedlist(head):
    current = head
    while current:
        print(current.val, end=" -> ")
        current = current.next
    print("None")

# Create a linked list from a Python list
nums = [1, 2, 3, 4, 5]  # Example list
linked_list_head = list_to_linkedlist(nums)

# Initialize Solution object and find the middle node
solution = Solution()
middle = solution.middleNode(linked_list_head)

# Print the value of the middle node
print("Middle node value:", middle.val)
