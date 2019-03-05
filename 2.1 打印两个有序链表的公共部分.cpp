/*
重合有三种情况：
	1、完全重合。两个链表的首尾node都一样。
    2、部分重合。呈一字型，也就是某个链表的尾部与另一个链表的前半部分有重合。
    3、部分重合。呈Y字型，两个链表的尾部完全重合
这道题很简单，因为有序，所以就比较大小，小的指针往后移动。直到发现有指针为空到达尾部。
*/
#include <iostream>
#include<string>
#include<vector>
#include"limits.h"
using namespace std;
struct Node{
    int value;
    Node* next;
};

void printComPart(Node *head1,Node *head2){
    
    while(head1 && head2){
        if(head1->value == head2->value){
            cout<<head1->value<<endl;
            head1 = head1->next;
            head2 = head2->next;
        }
        else head1->value > head2->value ? head2 = head2->next:head1 = head1->next;
    }
}
int main() {
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *ptr = NULL;

    for(int i =0;i<10;i++)
    {
        if(head1)
        {
            head1 = new Node;
            head1->value = i;
            head1->next = NULL;
            ptr = head1;
            continue;
        }
        ptr->next = new Node;
        ptr = ptr->next;
        ptr->value = i;
        ptr->next = NULL;
    }
    for(int i =7;i<12;i++)
    {
        if(head2)
        {
            head2 = new Node;
            head2->value = i;
            head2->next = NULL;
            ptr = head2;
            continue;
        }
        ptr->next = new Node;
        ptr = ptr->next;
        ptr->value = i;
        ptr->next = NULL;
    }
    printComPart(head1,head2);
    return 0;
}