#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* root;

Node *new_node(int data){
    Node *new_node = new Node();
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node; 
}
Node* insert(Node *root,int data){
    if(root == NULL){
        root = new_node(data);
    }
    else if(data<=root->data){
        root->left = insert(root->left,data);
    }
    else{
        root->right = insert(root->right,data);
    }
    return root;
}

bool replace(Node* root,int data,int replce){
    if(root==NULL){
        return false;
    }
    else if(data == root->data){
        root->data = replce;
        return true;
    }
    else if(data<=root->data){
        return replace(root->left,data,replce);
    }
    else{
        return replace(root->right,data,replce);
    }
}

Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

struct Node* Delete(struct Node *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			struct Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct Node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			struct Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
 
 
void inorder(Node *root){
    if(root==NULL) return;
    
    inorder(root->left);
    cout<<root->data;
    cout<<" ";
    inorder(root->right);
}
void preorder(Node *root){
    if(root==NULL) return;
    cout<<root->data;
    cout<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root){
    if(root==NULL) return;
    
    postorder(root->left);
    postorder(root->right);
     cout<<root->data<<"";
     cout<<" ";
}
int main(){
root = NULL;
root=insert(root,4);
root=insert(root,57);
root=insert(root,23);
root=insert(root,2);
inorder(root);
replace(root,57,9);
inorder(root);
Delete(root,4);
inorder(root);
return 0;

}