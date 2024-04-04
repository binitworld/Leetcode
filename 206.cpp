#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
    public:
        ListNode* reverseList(ListNode* head){
            if(!head || !head->next)
                return head;

            ListNode* newHead = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;
            return newHead;
        }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(90);
    head->next->next->next->next->next->next = new ListNode(78);

    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    while(reversedHead != NULL){
        cout << reversedHead->val << " ";
        reversedHead = reversedHead->next;
    }
    return 0;
}
