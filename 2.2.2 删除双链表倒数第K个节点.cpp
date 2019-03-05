DList{
	int val;
	DListNode* next;
	DListNode* pre;
	DListNode(int x):val(x),next(NULL),pre(NULL){}
};

class Solution {
public:
    DListNode* removeNthFromEnd(DListNode* head, int n){
        if(!head || n < 1){
			return head;
		}
		DListNode* cur = head;
		while(cur){
			n--;
			cur = cur->next;
		}
		if(n == 0){
			head = head->next;
			head->pre = NULL;
		}
		if(n < 0){
			cur = head;
			while(++n != 0){
				cur = cur->next;
			}
			cur->next = cur->next->next;
			if(cur->next->next != NULL){//如果没有直接用pre 则删除不了倒数第1个
				cur->next->next->pre = cur;
			}
		}
		return head;
    }
};