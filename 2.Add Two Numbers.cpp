#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {} // Use nullptr instead of NULL
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

    ListNode* result = dummy->next;
    delete dummy; // Free the dummy node
    return result; // Return the result list (skip dummy)
}

// Helper function to create a linked list from an array
ListNode* createLinkedList(const int arr[], int size) {
    if (size == 0) return nullptr; // Handle empty array case

    ListNode* head = new ListNode(arr[0]); // First node
    ListNode* current = head;

    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
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

// Helper function to free memory
void freeLinkedList(ListNode* node) {
    while (node) {
        ListNode* temp = node;
        node = node->next;
        delete temp;
    }
}

// Main function
int main() {
    int arr1[] = {2, 4, 3}; // Represents number 342
    int arr2[] = {5, 6, 4}; // Represents number 465

    ListNode* l1 = createLinkedList(arr1, 3);
    ListNode* l2 = createLinkedList(arr2, 3);

    ListNode* result = addTwoNumbers(l1, l2);

    cout << "Sum: ";
    printLinkedList(result); // Output: 7 -> 0 -> 8 (Represents 807)

    // Free allocated memory
    freeLinkedList(l1);
    freeLinkedList(l2);
    freeLinkedList(result);

    return 0;
}
