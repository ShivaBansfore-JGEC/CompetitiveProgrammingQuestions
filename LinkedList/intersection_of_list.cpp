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

//============= Intersection of two sorted linkedlist ====================

Node* intersection(Node *  head1,Node *head2){
    Node * new_head=NULL;
    Node* a=head1,*b=head2;
    if(a==NULL) cout<<"head is null"<<endl;
    while(a!=NULL && b!=NULL){
        if(a->data==b->data){
            insert_atfront(&new_head,a->data);
            a=a->next;
            b=b->next;

        }else if(a->data < b->data){
            a=a->next;
        }else{
            b=b->next;
        }
    }

    return new_head;
}




int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    Node* head1=NULL;
    Node* head2=NULL;
    Node* head3=NULL;

    insert_atfront(&head1,6);
    insert_atfront(&head1,5);
    //insert_atfront(&head1,6);
    insert_atfront(&head1,4);
    insert_atfront(&head1,3);
    insert_atfront(&head1,2);
    insert_atfront(&head1,1);
    print_list(head1);

    insert_atfront(&head2,8);
    insert_atfront(&head2,6);
    //insert_atfront(&head1,6);
    insert_atfront(&head2,4);
    insert_atfront(&head2,2);

    print_list(head2);
    head3=intersection(head1,head2);
    print_list(head3);

    return 0;
}