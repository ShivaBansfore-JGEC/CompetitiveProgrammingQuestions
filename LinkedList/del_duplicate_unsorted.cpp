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

//============= Remove duplicates in unsorted list ====================

//method 1 : using two loop

void delete_dupl(Node* head){

    Node* ptr1,*ptr2,*dup;
    ptr1=head;
    while(ptr1!=NULL && ptr1->next!=NULL){
        ptr2=ptr1;
        while(ptr2->next!=NULL){
            if(ptr1->data==ptr2->next->data){
                dup=ptr2->next;
                ptr2->next=ptr2->next->next;
                delete(dup);
            }else 
                ptr2=ptr2->next;
        }

        ptr1=ptr1->next;
    }
}

//method 2: using hashing 
void delete_duplicates(Node* head){

    Node * temp=head;
    Node * prev=NULL;
    unordered_set<int> s;
    while(temp!=NULL){

        if(s.find(temp->data)!=s.end()){
            prev->next=temp->next;
            delete(temp);
        }else{
            s.insert(temp->data);
            prev=temp;
        }
        temp=temp->next;
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    Node* head1=NULL;
    insert_atfront(&head1,2);
    insert_atfront(&head1,2);
    //insert_atfront(&head1,6);
    insert_atfront(&head1,3);
    insert_atfront(&head1,5);
    print_list(head1);
    //remove_duplicates(head1);
    delete_duplicates(head1);
    print_list(head1);
    return 0;
}