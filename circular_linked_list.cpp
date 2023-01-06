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

void insert(node* &tail,int data,int key){
    if(tail==NULL){
        node* temp = new node(data);
        tail = temp;
        temp -> next = temp;
        return;
    }
    node* curr = tail;
    while(curr -> data != key && curr -> next != tail){
        curr = curr -> next;
    }
    if(curr -> data != key){
        cout<<"NOT FOUND"<<endl;
        return;
    }
    node* temp = new node(data);
    temp->next = curr->next;
    curr->next = temp;
}
void delete_node(node* &tail,int key){
    if(tail == NULL){
        cout<<"list is empty";
        return;
    }
    node* prev = tail;
    node* curr = prev -> next;
    while(curr -> data!=key && curr != tail){
        prev = curr;
        curr = curr -> next;
    }
    if(curr->data!=key){
        cout<<"not found"<<endl;
        return;
    }
    if(prev==curr){
        tail=NULL;
    }
    if(tail==curr){
        tail = prev;
    }
    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;
}
void print(node* &tail){
    if(tail==NULL){
        return;
    }
    cout<<"****printing****"<<endl;
    node* temp = tail;
    do{
        cout<<tail -> data<<" ";
        tail = tail -> next;
    }while(tail!=temp);
    cout<<endl;
}
int main(){
    node* tail = NULL;
    int ch;
    while(ch!=0){
        cout<<"1.INSERTION\n2.PRINTING\n3.DELETION\n";
        cout<<"ENTER CHOICE:";
        cin>>ch;
        if(ch==1){
            int data,key;
            cout<<"ENTER DATA:";
            cin>>data;
            cout<<"ENTER KEY:";
            cin>>key;
            insert(tail,data,key);
            print(tail);
        }
        else if(ch==2){
            print(tail);
        }
        else if(ch==3){
            int data;
            cout<<"enter data to delete:";
            cin>>data;
            delete_node(tail,data);
            print(tail);
        }
        else{
            cout<<"WRONG CHOICE"<<endl;
        }
        //cout<<"tail  "<<tail->data;
        cout<<endl<<endl;
    }
}