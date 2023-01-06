#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct node{
	int data;
	node* left;
	node* right;
} node;

node* root = NULL;



node* GetNewNode(int data){
	node* temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

node* Insert(node* root,int data){
	if(root == NULL){
		root = GetNewNode(data);
	}
	else if(data<=root->data){
		root->left = Insert(root->left,data);
	}
	else{
		root->right = Insert(root->right,data);
	}
	return root;
}

bool Search(node* root,int data){
	if(root == NULL){
		return false;
	}
	else if(data == root->data){
		return true;
	}
	else if(data<=root->data){
		return Search(root->left,data);
	}
	else{
		return Search(root->right,data);
	}
}

int FindMin(node* root){
	if(root==NULL){
		cout<<"List Empty"<<endl;
		return -1;
	}
	else if(root->left==NULL){
		return root->data;
	}
	else{
		return FindMin(root->left);
	}
}

node* FindMinNode(node* root){
	if(root==NULL){
		cout<<"List Empty"<<endl;
		return NULL;
	}
	else if(root->left==NULL){
		return root;
	}
	else{
		return FindMinNode(root->left);
	}
}

int FindMax(node* root){
	if(root==NULL){
		cout<<"List Empty"<<endl;
		return -1;
	}
	else if(root->right==NULL){
		return root->data;
	}
	else{
		return FindMax(root->right);
	}
}

int FindHeight(node* root){
	if(root==NULL)
		return -1;
	else
		return max(FindHeight(root->left),FindHeight(root->right))+1;
}

void LevelOrder(node* root){
	if(root==NULL){
		return;
	}
	else{
		queue<node*> Q;
		Q.push(root);
		while(!Q.empty()){
			node* current = Q.front();
			cout<<current->data<<" ";
			if(current->left!=NULL) Q.push(current->left);
			if(current->right!=NULL) Q.push(current->right);
			Q.pop();
		}
	}
	
}

void PreOrder(node* root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(node* root){
	if(root==NULL) return;
	InOrder(root->left);
	cout<<root->data<<" ";
	InOrder(root->right);
}

void PostOrder(node* root){
	if(root==NULL) return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout<<root->data<<" ";
}

bool IsBinarySearchTree(node* root,int min_value, int max_value){
	if(root == NULL) return true;
	if(root->data>=min_value
		&& root->data<max_value
		&& IsBinarySearchTree(root->left,min_value,root->data)
		&& IsBinarySearchTree(root->right,root->data,max_value))
	return true;
	else return false;
}

node* Delete(node* root,int data){
	if(root==NULL) return root;
	else if(data<root->data) root->left = Delete(root->left,data);
	else if(data>root->data) root->right = Delete(root->right,data);
	else{
		if(root->left==NULL && root->right==NULL){
			delete root;
			root = NULL;
			return root;
		}
		else if(root->left==NULL){
			node* temp = root;
			root = root->right;
			delete temp;
			return root;
		}
		else if(root->right==NULL){
			node* temp = root;
			root = root->left;
			delete temp;
			return root;
		}
		else{
			node* temp = FindMinNode(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
			return root;		
		}
	}
}

//bool IsBST(node* root){
//		bool InOrder(node* root,int data){
//		if(root==NULL) return;
//		InOrder(root->left,root->data);
//		if(root->data>data) return true;
//		else return false;
//		InOrder(root->right,root->data);
//	}
//	
//}

node* SearchNode(node* root,int data){
	if(root==NULL) return root;
	else if(root->data==data) return root;
	else if(root->data>data) return SearchNode(root->left,data);
	else return SearchNode(root->right,data);
}

//node* DeleteUsingSearch(node* root,int data){
//	node* temp = SearchNode(root,data);
//	if(temp==NULL) cout<<"Data not found"<<endl;
//	if(temp->left==NULL && temp->right==NULL){
//		delete temp;
//		temp = NULL;
//		return temp;
//	}
//	else if(temp->left==NULL){
//		node* temp1 = temp;
//		temp = temp->right;
//		delete temp1;
//		return temp;
//	}
//	else if(temp->right==NULL){
//		node* temp1 = temp;
//		temp = temp->left;
//		delete temp1;
//		return temp;
//	}
//	else{
//		node* temp1 = FindMinNode(temp->right);
//		temp->data = temp1->data;
//		temp->right = DeleteUsingSearch(temp->right,temp1->data);
//		return temp;
//	}
//}


int FindSucessor(node* root, int data){
	node* current = SearchNode(root,data);
	if(current == NULL ) cout<<"NOt found"<<endl;
	if(current->right!=NULL){
		return FindMin(current->right);
	}
	else{
		node* sucessor = NULL;
		node* ancestor = root;
		while(ancestor!=current){
			if(current->data<ancestor->data){
				sucessor = ancestor;
				ancestor = ancestor->left;
			}
			else{
				ancestor = ancestor->right;
			}
		}
		return sucessor->data;
	}
}
int Sucessor(node* root,int data){
	node* current = SearchNode(root,data);
	if(current==NULL) cout<<"NOt found"<<endl;;
	if(current->right!=NULL){
		return FindMin(current->right);
	}
	else{
		node* sucessor = NULL;
		node* ancestor = root;
		while(current!=ancestor){
			if(current->data<ancestor->data){
			sucessor = ancestor;
			ancestor = ancestor->left;
			}
			else ancestor = ancestor->right;
		}
		
	return sucessor->data;
	}
}

int main(void){
	int data = 0;
	while(1){
		cout<<"Enter the nodes (Press 0 to exit) "<<endl;
		cin>>data;
		if(data==0){
			break;
		}
		else{
			root = Insert(root,data);
		}
	}
//	cout<<"Enter the number to be searched "<<endl;
//	cin>>data;
//	if(Search(root,data)==true) cout<<"Found"<<endl;
//	else cout<<"Not found"<<endl;
//	cout<<"Minimun Value is "<<FindMin(root)<<endl;
//	cout<<"Maximum Value is "<<FindMax(root)<<endl;
	cout<<"Height of The tree is ";
	cout<<FindHeight(root);
	cout<<endl;
//	cout<<"Level Order Traversal ";
//	LevelOrder(root);
//	cout<<endl;
//	cout<<"Pre order traversal ";
//	PreOrder(root);
//	cout<<endl;
	cout<<"Inorder Traversal ";
	InOrder(root);
	cout<<endl;
	while(1){
		if(data == -1) exit(1);
		cout<<"Find Successor of which element?"<<endl;
		cin>>data;
		cout<<"The successor of "<<data<<" is "<< Sucessor(root,data)<<endl;;
	}
//	cout<<"Post order Traversal ";
//	PostOrder(root);
//	cout<<endl;
//	cout<<"Is Binary Search Tree?? "<<IsBinarySearchTree(root,INT_MIN,INT_MAX)<<endl;
//	cout<<"Enter the element to be deleted: "<<endl;
//	cin>>data;
//	root = DeleteUsingSearch(root,data);
//	cout<<"Level Order Traversal ";
//	LevelOrder(root);
//	cout<<endl;
}
