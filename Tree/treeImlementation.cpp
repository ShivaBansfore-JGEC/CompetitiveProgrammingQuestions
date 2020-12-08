#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node{
    int key;
    Node *left,*right;

    Node(int x){
        key=x;
        left=right=NULL;
    }
};

//insert operation 
void insertNode(Node* temp,int key){
    queue<Node*> q;
    q.push(temp);
    while (!q.empty())
    {
        Node * temp=q.front();
        q.pop();

        if(!temp->left){
            temp->left=new Node(key);
            break;
        }else{
            q.push(temp->left);
        }

        if(!temp->right){
            temp->right=new Node(key);
            break;
        }else{
            q.push(temp->right);
        }
    }
    
}

void deleteDepestNode(Node * root ,Node * d_node){

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node * temp=q.front();
        q.pop();
        if(temp==d_node){
            temp=NULL;
            delete(d_node);
            return;
        }

        if(temp->right){
            if(temp->right==d_node){
                temp->right=NULL;
                delete(d_node);
                return;
            }else
            {
                 q.push(temp->right);
            }
        }

        if(temp->left){
            if(temp->left==d_node){
                temp->left=NULL;
                delete(d_node);
                return;
            }else q.push(temp->left);
        }


    }
}


Node* deletion(Node* root,int key){

    if(root==NULL) return NULL;

    if (root->left==NULL && root->right==NULL){
        if(root->key==key){
            return NULL;
        }else
        {
            return root;
        }
        
    }


    queue<Node*> q;
    q.push(root);

    Node* temp;
    Node* keynode=NULL;


    while (!q.empty())
    {
        temp=q.front();
        q.pop();

        if(temp->key==key) keynode=temp;

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);

    }

    if(keynode!=NULL){
            int x=temp->key;
            deleteDepestNode(root,temp);
            keynode->key=x;
        } 
  return root;  
}



//level order traversal


int height(Node * root){
    if(root==NULL) return 0;

    int lheight=height(root->left);
    int rheight=height(root->right);

    if(lheight>rheight){
        return lheight+1;
    }else
    {
         return rheight+1;
    }
    
}

void printLevelOrder(Node * root,int level){
    if(root==NULL) return;

    
    if(level==1){
        cout<<root->key<<" ";
    }else if(level>1){
        printLevelOrder(root->left,level-1);
        printLevelOrder(root->right,level-1);
    }
}

void levelOrder(Node* root){
    int h = height(root);
    int i;
    for(i=1;i<=h;i++){
        printLevelOrder(root,i);
    }

    
}


void inorder(Node * temp){
    if(!temp) return;
    inorder(temp->left);
    cout<<temp->key<<" ";
    inorder(temp->right);
}

//preorder
void preorder(Node * root){
    if(root==NULL) return;

    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
}

//void postorder

void postorder(Node * root){
    if(root==NULL){
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->key<<" ";
}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif


    Node* root = new Node(10); 
    root->left = new Node(11); 
    root->left->left = new Node(7); 
    root->right = new Node(9); 
    root->right->left = new Node(15); 
    root->right->right = new Node(8); 
  
    cout << "Inorder traversal before insertion:"; 
    inorder(root); 
    cout<<endl;
    int key = 12; 
    insertNode(root, key); 
  
    cout << endl; 
    cout << "Inorder traversal after insertion:"; 
    inorder(root); 


    root=deletion(root,11);

    cout << endl; 
    cout << "Inorder traversal after deletion:"; 
    inorder(root); 
    cout<<endl;
    cout<<"height of tree:"<<height(root);
    cout<<endl;

    cout<<"level order traversal:";
    levelOrder(root);

    cout<<endl;
    cout<<"preorde traversal:";
    preorder(root);
    cout<<endl;
    cout<<"postorder traversal:";
    postorder(root);

    return 0; 

}