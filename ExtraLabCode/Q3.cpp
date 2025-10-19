//Detect Cycle in a Linked List
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Returns true if there is a cycle in the linked list.
bool hasCycle(ListNode* head) {
    if (!head) return false;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true; // cycle detected
    }
    return false;
}

// Returns the node where the cycle begins, or nullptr if there is no cycle.
ListNode* detectCycle(ListNode* head) {
    if (!head) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;

    // First, find meeting point if a cycle exists.
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            // Move one pointer to head, advance both by 1 until they meet.
            ListNode* entry = head;
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry; // start of cycle
        }
    }
    return nullptr; // no cycle
}