#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node* prev;
    node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL; 
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
void insert_at_head(node* &head,node* &tail,int data){
    node* temp = new node(data);
    if(head==NULL){
        head = temp;
        tail = temp;
        return;
    }
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}
void insert_at_tail(node* &tail,node* &head,int data){
    node* temp = new node(data);
    if(tail==NULL){
        tail = temp;
        head = temp;
        return;
    }
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
}
void insert_at_position(node* &tail,node* &head,int position , int data){
    if(position==1){
        insert_at_head(head,tail,data);
        return;
    }
    node* curr = head;
    int cnt = 1;
    while(cnt<position-1){
        curr = curr->next;
        cnt++;
    }
    if(curr -> next==NULL){
        insert_at_tail(tail,head,data);
        return;
    }
    node* node_to_insert = new node(data);
    node_to_insert -> next = curr -> next;
    curr -> next -> prev = node_to_insert;
    curr -> next = node_to_insert;
    node_to_insert -> prev = curr;

}
void delete_at_position(node* &head,node* &tail,int position){
    if(head==NULL){
        cout<<"NOTHING TO DELETE"<<endl;
        return;
    }
    if(position == 1){
        node*temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next =NULL;
        delete temp;
        return ;
    }
    else{
        node* curr = head;
        node* piche = NULL;
        int cnt =1;
        while(cnt<position){
            piche = curr;
            curr = curr -> next;           
            cnt++;
        }
        if(curr -> next == NULL){
            piche -> next = curr -> next;
            tail = piche;
            curr -> prev = NULL;
            delete curr;
            return;
        }
        piche -> next = curr -> next;
        curr ->next -> prev = piche;
        curr -> next = NULL;
        curr -> prev = NULL;
    }
}
void print(node* &head){
    if(head==NULL){
        cout<<"NOTING TO PRINT"<<endl;
        return;
    }
    node*temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

}
int length(node* head){
    node* temp = head;
    int len = 0;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}
int main(){
    node* head = NULL;
    node* tail = NULL;
    int ch;
    while(ch!=0){
        cout<<"1. insert at position\n2. delete at position\n3.length\n4. Print\n5. For exit enter 0"<<endl;
        cout<<"*************ENTER CHOICE**************"<<endl;
        cin>>ch;
        if(ch==1){
            int data;
            cout<<"Enter data:";
            cin>>data;
            int position;
            cout<<"Enter position:";
            cin>>position;
            insert_at_position(tail,head,position,data);
            print(head);
        }
        else if(ch==2){
            int position;
            cout<<"Enter position for deletion:";
            cin>>position;
            delete_at_position(head,tail,position);
            print(head);
        }
        else if(ch==3){
            int ans = length(head);
            cout<<ans<<endl;
        }
        else if(ch==4){
            print(head);
        }
        else{
            cout<<"****WRONG CHOICE****"<<endl;
        }
        cout<<"HEAD:"<<head -> data<<endl;
        cout<<"tail:"<<tail -> data<<endl;

        cout<<endl<<endl;
    }
    return 0;
}
