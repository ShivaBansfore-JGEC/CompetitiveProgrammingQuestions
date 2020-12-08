#include<bits/stdc++.h>
using namespace std;


struct Node{
    int key;
    Node *left, *right;

    Node(int data){
        key=data;
        left=right=NULL;
    }
};

void inorder(Node* root){
    if(root==NULL) return;
    
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}


// Vertical order traversal 1st method 
void find_min_max(Node *root,int *min,int *max,int hd){
    if(root == NULL) return;
    if(hd<*min){
        *min=hd;
    }else if(hd>*max) *max=hd;

    find_min_max(root->left,min,max,hd-1);
    find_min_max(root->right,min,max,hd+1);

}

void printVerticalLine(Node * root,int line_no,int hd){
    if(root==NULL) return;
    if(hd==line_no) cout<<root->key<<" ";

    printVerticalLine(root->left,line_no,hd-1);
    printVerticalLine(root->right,line_no,hd+1);

}

void vertical_traversal(Node * root){
    int min=0,max=0;
    find_min_max(root,&min,&max,0);

    for(int line_no=min;line_no<=max;line_no++){
        printVerticalLine(root,line_no,0);
        cout<<endl;
    }
}

//vertical order traversal method 2
void getVerticalOrder(Node *root,map<int,vector<int>> &m,int hd){

    if(root==NULL) return;
    m[hd].push_back(root->key);

    getVerticalOrder(root->left,m,hd-1);
    getVerticalOrder(root->right,m,hd+1);

}

void verticalOrder_traversal(Node *root){
    map<int ,vector<int>> m;
    int hd=0;
    getVerticalOrder(root,m,0);

    map<int ,vector<int>> ::iterator it;
    for(it=m.begin();it!=m.end();++it){
        for(int j=0;j<it->second.size();j++){
            cout<<it->second[j]<<" ";
        }
        cout<<endl;
    }


}



int main() {
    	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	    #endif

    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
    root->right->left->right = new Node(8); 
    root->right->right->right = new Node(9); 
    vertical_traversal(root);
    cout<<"-------------#####-------------------"<<endl;
    verticalOrder_traversal(root);


    return 0;
}