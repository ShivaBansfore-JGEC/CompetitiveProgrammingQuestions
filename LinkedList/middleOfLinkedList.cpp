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
}

//=========== MIDDDLE OF THE LINKEDLIST ============//

void middleList(Node* head){
    Node* fastptr=head;
    Node* slowptr=head;

    while(fastptr!=NULL && fastptr->next!=NULL){
        fastptr=fastptr->next->next;
        slowptr=slowptr->next;
    }
    cout<<slowptr->data<<endl;
}


int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    Node* head1=NULL;
    insert_atfront(&head1,1);
    insert_atfront(&head1,4);
    insert_atfront(&head1,6);
    insert_atfront(&head1,3);
    insert_atfront(&head1,5);
    middleList(head1);
    return 0;
}