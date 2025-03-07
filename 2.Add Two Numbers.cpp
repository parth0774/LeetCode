'''
2. Add Two Numbers
Medium
Topics
Companies
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
'''

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to add two numbers represented as linked lists
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0); // Dummy node for result list
    ListNode* current = dummy; // Pointer to construct the new list
    int carry = 0; // Variable to store carry

    while (l1 || l2 || carry) {
        int sum = carry; // Start with carry from previous step

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10; // Compute new carry
        current->next = new ListNode(sum % 10); // Store digit in new node
        current = current->next;
    }

    return dummy->next; // Return the result list (skip dummy)
}

// Helper function to create a linked list from a vector
ListNode* createLinkedList(int arr[], int size) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    for (int i = 0; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return dummy->next;
}

// Helper function to print a linked list
void printLinkedList(ListNode* node) {
    while (node) {
        cout << node->val;
        if (node->next) cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

// Main function
int main() {
    int arr1[] = {2, 4, 3}; // Represents number 342
    int arr2[] = {5, 6, 4}; // Represents number 465

    ListNode* l1 = createLinkedList(arr1, 3);
    ListNode* l2 = createLinkedList(arr2, 3);

    ListNode* result = addTwoNumbers(l1, l2);
    printLinkedList(result); // Output: 7 -> 0 -> 8 (Represents 807)

    return 0;
}
