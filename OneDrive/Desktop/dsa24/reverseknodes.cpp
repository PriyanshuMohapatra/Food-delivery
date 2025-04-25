#include <iostream>

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        int c = 0;
        ListNode *temp = head;
        ListNode *front = nullptr;
        ListNode *prev = nullptr;
        
        while (temp != nullptr) {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
            c++;
            
            if (c % k == 0) {
                ListNode *temp1 = temp;
                temp->next = nullptr;
                int i = 0;
                while (i < k && temp1 != nullptr) {
                    front = temp1->next;
                    temp1->next = prev;
                    prev = temp1;
                    temp1 = front;
                    i++;
                }
                temp->next = temp1;
                temp = temp1;
            }
        }
        
        return prev;
    }
};

// Function to print the linked list
void printList(ListNode *head) {
    ListNode *temp = head;
    while (temp != nullptr) {
        std::cout << temp->val;
        if (temp->next != nullptr)
            std::cout << " -> ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create a test linked list: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    int k = 2; // Test with k = 2, change as needed
    
    Solution solution;
    ListNode *reversedHead = solution.reverseKGroup(head, k);
    
    std::cout << "Original List: ";
    printList(head);
    
    std::cout << "Reversed List in groups of " << k << ": ";
    printList(reversedHead);
    
    // Clean up: free memory

    
    return 0;
}
