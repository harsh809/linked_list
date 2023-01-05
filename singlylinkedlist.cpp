#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
    node(int data){
        this -> data = data;
        this -> next = NULL; 
    }
    ~node(){
        int value = this -> data;
        //memory free
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;

        }
        cout<<"memory is free for node with data"<<value<<endl;
    }
};

void insert_at_head(node* &head,int data){
    node* temp = new node(data);
    temp -> next = head;
    head = temp;
}
void insert_at_tail(node* &tail,int data){
    node* temp = new node(data);
    tail -> next = temp;
    tail = temp;
     
}
void insert_at_position(node* &tail,node* &head,int position , int data){
    if(position==1){
        insert_at_head(head,data);
        return;
    }
    node* temp = head;
    int cnt = 1;
    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }
    if(temp -> next==NULL){
        insert_at_tail(tail,data);
        return;
    }
    node* node_to_insert = new node(data);
    node_to_insert -> next = temp->next;
    temp -> next = node_to_insert;

}
void delete_at_position(node* &head,node* &tail,int position){
    // if(head == NULL){
    //     cout<<"empty";
    //     return;
    // }
    if(position == 1){
        node*temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        node* curr = head;
        node* prev = NULL;
        int cnt =1;
        while(cnt<position){
            prev = curr;
            curr = curr -> next;           
            cnt++;
    }
    if(curr -> next == NULL){
        node* temp = prev;
        prev -> next = curr -> next;
        tail = temp;
    }else{
        prev -> next = curr -> next;

    }
    curr -> next = NULL;
    delete curr;
}
}
void print(node* &head){
    node*temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

}
int main(){
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;
    insert_at_tail(tail,12);
    insert_at_tail(tail,15);
    insert_at_tail(tail,18);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;
    print(head);
    insert_at_position(tail,head,3,22);
    print(head);
    insert_at_position(tail,head,1,7);
    print(head);
    insert_at_position(tail,head,7,4);
    print(head);
    delete_at_position(head,tail,1);
    print(head);
    delete_at_position(head,tail,6);
    print(head);
    delete_at_position(head,tail,5);
    print(head);
    cout<<"tail "<<tail -> data;
    cout<<"head "<<head -> data;
    cout<<endl;
}