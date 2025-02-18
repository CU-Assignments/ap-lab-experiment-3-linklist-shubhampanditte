#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        ListNode* temp = head;
        int length = 1;
        while (temp->next) {
            temp = temp->next;
            length++;
        }
        
        temp->next = head;
        k = k % length;
        int stepsToNewHead = length - k;
        temp = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            temp = temp->next;
        }
        
        head = temp->next;
        temp->next = nullptr;
        
        return head;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    int k = 2;
    head = solution.rotateRight(head, k);
    printList(head);
    
    return 0;
}
