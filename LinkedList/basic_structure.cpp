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

void insert_at_end(Node** head,int new_data){
    //create new node
    Node* new_node=new Node();
    new_node->data=new_data;
    new_node->next=NULL;
    if(head==NULL){
        *head=new_node;
    }else{
        Node * temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }

        temp->next=new_node;
    }
}


//insert before any particular node
void insert_before(Node ** head,int new_data,int key){




    //create a new node first
    Node* new_node=new Node();
    new_node->data=new_data;

    //travers upto one node before key

    Node * temp=*head;
    //if key is head
    if(temp->data==key){
        new_node->next=temp;
        *head=new_node;
        return;
    }
    Node * prev=NULL;
    while(temp->next!=NULL && temp->data!=key){
        prev=temp;
        temp=temp->next;
    }

    new_node->next=temp;
    prev->next=new_node;

}

//insert after any particular node 

void insert_after(Node** head,int new_data,int key){
    // create a node
    Node * new_node=getNode(new_data);

    Node* temp=*head;
    Node * next=NULL;
    while(temp->next!=NULL && temp->data!=key){
        temp=temp->next;
    }
    if(temp->data!=key){
        cout<<"invlid key"<<endl;
        return;
    }else{
        next=temp->next;
        new_node->next=next;
        temp->next=new_node;
    }


}


void delete_node(Node **head,int key){
    //case if deleted node is  head node

    Node* temp=*head;
    Node* prev=NULL;
    if(temp->data==key){
        *head=temp->next;
        free(temp);
        return;
    }


    while(temp->next!=NULL && temp->data!=key){
        prev=temp;
        temp=temp->next;
    }

    prev->next=temp->next;
    free(temp);
    
}


bool search_node(Node* head,int key){

    if(head==NULL){
        return false;
    }

    if(head->data==key) return true;

    return search_node(head->next,key);

}

void print_list(Node* head){
    Node * temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
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
    insert_atfront(&head1,1);
    insert_atfront(&head1,4);
    insert_atfront(&head1,6);
    insert_at_end(&head1,5);
    insert_before(&head1,7,6);
    insert_after(&head1,2,5);
    delete_node(&head1,7);
    cout<<search_node(head1,7)<<endl;
    cout<<"inserting at beginning"<<endl;
    print_list(head1);

    return 0;
}