#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left,*right;
    Node(int data){
        key=data;
        left=right=NULL;
    }
};

Node* insert(Node *root,int val){
    Node *newNode=new Node(val);
    if(root==NULL){
     root=newNode;
     return root;
    }

    Node *current=root;
    while(1){
        
        if(current->key>val){
            if(current->left){
                current=current->left;
            }else{
                current->left=newNode;
                break;
            }
        }else{

            if(current->right){
                current=current->right;
            }else{
                current->left=newNode;
                break;
            }

        }
    }
    return root;
}

Node* search(Node *root,int key){
    if(root==NULL || root->key==key){
        return root;
    }

    if(root->key>key) return search(root->left,key);
    
    return search(root->right,key);

}

Node* minVal(Node * root){
    Node *current=root;
    while (current && current->left !=NULL)
    {
        current=current->left;
    }
    return current;
    
}

Node* deleteNode(Node* root,int key){
    if(root==NULL) return root;
    else if(root->key>key){
        deleteNode(root->left,key);
    }else if(root->key<key){
        deleteNode(root->right,key);
    }else
    {
        // single child

        if(root->left==NULL){
            Node *temp=root->right;
            free(root);
            return temp;
        }

        if(root->right==NULL){
            Node *temp=root->left;
            free(root);
            return temp;
        }
        Node *temp=minVal(root->right);

        root->key=temp->key;
        root->right=deleteNode(root->right,temp->key);

    }
    return root;
    
}


void inorder(Node *root){
    if(root==NULL) return;
    cout<<root->key<<" ";
    inorder(root->left);
    inorder(root->right);

}

int main(){
    	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	    #endif
    Node *root=insert(NULL,3);

    insert(root,2);
    Node *temp=insert(root,4);
    cout<<temp->key<<" "<<temp->left->key;
    insert(root,6);
    inorder(temp);
    cout<<endl;
    cout<<search(root,2)->key;
    //deleteNode(root,2);
    cout<<endl;
    inorder(root);
    return 0;
}