#include<stack>
using namespace std;
struct Node{
	int val;
	Node* left;
	Node* right;
	Node(int x = 0):val(x),left(NULL),right(NULL){}
};

//任何能用递归解决的问题 都能用非递归的方式实现

void preOrder(Node* head){
	if(head != NULL){
		stack<Node*>s;
		s.push(head);
		while(!s.empty()){//结束的条件是 栈为空
			head = s.top();
			s.pop();
			cout<<head->value<<endl;//先将根打印然后弹出
			if(head->right != NULL){
				s.push(head->right);//先压入右节点，然后压入左节点，这样可以保证左节点每次都会打印弹出
			}
			if(head->left != NULL){
				s.push(head->left);
			}
		}
	}
	return;
}

void inOrder(Node* head){
	if(head != NULL){
		stack<Node*>s;
		Node* cur = head;
		while(!s.empty() || cur != NULL){
			if(head){//如果节点存在了就一直压入左节点
				s.push(cur);
				cur = cur->left;
			}
			else{//如果节点不存在了，就弹出打印 节点更换为栈顶右节点
				cur = s.top();
				cout<<cur->val<<endl;
				s.pop();
				cur = cur->right;
			}
		}
	}
	return;
}

void posOrder1(Node* head){
	if(!head){
		stack<Node*>s1;//使用两个栈来解决 思路很简单
		stack<Node*>s2;//s1弹出的节点压入s2中  s1弹出的顺序是中右左 s2弹出的顺序就是左右中 
		s1.push(head);
		while(!s1.empty()){
			Node* cur = s1.top();
			s2.push(cur);
			s1.pop();
			if(cur->left){
				s1.push(cur->left);
			}
			if(cur->right){
				s1.push(cur->right);
			}
		}
		
		while(!s2.empty()){
			cout<<s2.top()->val<<endl;
			s2.pop();
		}
	}
	return;
}

void posOrder2(Node* head){//只使用一个栈
	if(!head){
		stack<Node*>s;
		Node*c = NULL;
		s.push(head);
		while(!s.empty()){//c表示栈顶节点 head表示上一个打印并弹出栈的节点(初始化为头节点)
			c = s.top();
			if(c->left && head != c->left && head != c->right){//说明左孩子没有遍历完成就继续遍历
				s.push(c->left);
			}
			else if(c->right && head != c->right){//说明右孩子没有遍历完成就继续遍历右孩子
				s.push(c->right);
			}
			else{
				cout<<c->val<<endl;
				h = c;
				s.pop();
			}
		}
	}
	return;
}
