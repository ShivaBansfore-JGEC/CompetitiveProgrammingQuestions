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

//=========== DELETE DUPLICATES FROM THE SORTED LIST  ============//


void remove_duplicates(Node* head){
    Node* current=head;
    Node* next_next;

    while(current->next!=NULL){
        if(current->data==current->next->data){
            next_next=current->next->next;
            free(current->next);
            current->next=next_next;

        }else{
            current=current->next;
        }
    }
}

// Recurssive approach

void delete_duplicates(Node* head){

    Node* to_free;
    if(head==NULL){
        return;
    }

    if(head->next!=NULL){
        if(head->data==head->next->data){
            to_free=head->next;
            head->next=head->next->next;
            free(to_free);
            delete_duplicates(head);
        }else{
            delete_duplicates(head->next);
        }

    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    Node* head1=NULL;
    insert_atfront(&head1,1);
    insert_atfront(&head1,1);
    //insert_atfront(&head1,6);
    insert_atfront(&head1,3);
    insert_atfront(&head1,5);
    print_list(head1);
    //remove_duplicates(head1);
    delete_duplicates(head1);
    print_list(head1);
    return 0;
}