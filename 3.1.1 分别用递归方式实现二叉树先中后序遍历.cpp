struct Node{
	int val;
	Node* left;
	Node* right;
	Node(int x = 0):val(x),left(NULL),right(NULL){}
};

//递归方式实现先、中、后序树的遍历
void preOrder(Node* head){
	if(!head){
		return;
	}
	cout<<head->val<<endl;
	preOrder(head->left);
	preOrder(head->right);
}

void inOrder(Node* head){
	if(!head){
		return;
	}
	inOrder(head->left);
	cout<<head->val<<endl;
	inOrder(head->right);
}

void posOrder(Node* head){
	if(!head){
		return;
	}
	posOrder(head->left);
	posOrder(head->right);
	cout<<head->val<<endl;
}



