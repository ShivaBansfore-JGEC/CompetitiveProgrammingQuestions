#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
};

//create a node

Node* getNode(int data){
    Node * new_node=new Node();
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}
void insert_atfront(Node** head,int new_data){
    Node * new_node=new Node();
    new_node->data=new_data;
    new_node->next=*head;
    *head=new_node;
}

void print_list(Node* head){
    Node * temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//============= SWAP TWO NODES IN LINKED LIST ====================

void swap_nodes(Node** head,int x,int y){

    if(x==y) return;

    Node* currX=*head,*prevX=NULL;
    // search for x in the list
    while(currX!=NULL && currX->data!=x){
        prevX=currX;
        currX=currX->next;
    }

    Node *currY=*head,*prevY=NULL;
    //search y in the list

    while(currY!=NULL && currY->data!=y){
        prevY=currY;
        currY=currY->next;
    }

    if (currX == NULL || currY == NULL)  
        return; 

    //if node is not head 
    if(prevX!=NULL){
        prevX->next=currY;
    }else{
        *head=currY;
    }

    if(prevY!=NULL){
        prevY->next=currX;
    }else{
        *head=currX;
    }

    //swap other pointers
    Node* temp=currY->next;
    currY->next=currX->next;
    currX->next=temp;


}


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    Node* head1=NULL;
    insert_atfront(&head1,2);
    insert_atfront(&head1,1);
    //insert_atfront(&head1,6);
    insert_atfront(&head1,3);
    insert_atfront(&head1,5);
    print_list(head1);
    swap_nodes(&head1,3,1);
    print_list(head1);
    return 0;
}