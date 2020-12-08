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

//=========== FIND LOOP IN LINKED LIST ============//

bool find_loop(Node* head){
    Node* fastptr=head;
    Node* slowptr=head;
    while(slowptr && fastptr && fastptr->next){
        fastptr=fastptr->next->next;
        slowptr=slowptr->next;
        if(fastptr==slowptr){
            return 1;
        }
    }

    return 0;
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
    //insert_atfront(&head1,6);
    insert_atfront(&head1,3);
    insert_atfront(&head1,5);
    print_list(head1);

    //create a loop for testing 
    head1->next->next->next->next=head1;
    cout<<find_loop(head1)<<endl;
    return 0;
}