/*
19. Remove Nth Node From End of List
https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
*/
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || n < 1){
            return head;
        }
        ListNode* cur = head;
        while(cur){
            n--;
            cur = cur->next;
        }
        if(n == 0){//说明要删除的节点是头节点
            head = head->next;    
        }
        if(n < 0){// N-K+1是要删除的节点
            cur = head;
            while(++n != 0){//这里一定是++n 为的是找到倒数第K个节点的前一个节点
                cur = cur->next;
            }
            cur->next = cur->next->next;  
        }
        return head;
    }
};