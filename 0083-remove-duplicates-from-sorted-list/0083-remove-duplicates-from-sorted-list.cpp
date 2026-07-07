/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> s;
        ListNode* cur = head;
        ListNode* before = head;
        
        while(cur){
            if(s.count(cur->val)){
                before->next = cur->next;
                delete cur;
                cur=before;
            }
            s.insert(cur->val);
            before = cur;
            cur = cur->next;
        }

        return head;
    }
};