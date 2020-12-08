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

//============= INTERSECTION POINT OF TWO SORTED LINKEDLIST ====================

int get_count(Node* head){
    Node* temp=head;
    int cnt=0;
    while(temp){
        cnt++;
        temp=temp->next;
    }

    return cnt;
}

int _intersection_point(int d,Node* head1,Node* head2){

    Node *curr1=head1,*curr2=head2;
    for(int i=0;i<d;i++){
        if(curr1==NULL) return -1;
        curr1=curr1->next;
    }
    while(curr1 and curr2){
        if(curr1->data==curr2->data){
            return curr2->data;
        }
        curr1=curr1->next;
        curr2=curr2->next;
    }
    return -1;
}

int intersection_point(Node* head1,Node* head2){
    int c1=get_count(head1);
    int c2=get_count(head2);

    int d;
    if(c1>c2){
        d=c1-c2;
        return _intersection_point(d,head1,head2);
    }else{
        d=c2-c1;
        return _intersection_point(d,head2,head1);
    }

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

    insert_atfront(&head1,3);
    insert_atfront(&head1,6);
    insert_atfront(&head1,9);
    insert_atfront(&head1,15);
    print_list(head1);

    insert_atfront(&head2,8);
    insert_atfront(&head2,6);
    insert_atfront(&head2,9);
    insert_atfront(&head2,15);
    cout<<intersection_point(head1,head2)<<endl;
    print_list(head2);

    return 0;
}