#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
class node{
  public:
  node* next;
  int data; 
  node (int val){
    next=NULL;
    data=val;
  }
};

void insertAtHead(node* &head,int val){
  node* n=new node(val);
  n->next=head;
  head=n;
}
void insertAtTail(node* &head, int val){
 
  if(head==NULL){
    insertAtHead(head,val);
    return;
  }
  node* n=new node(val);
  node* temp=head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=n;

}

void insertAtNode(node* &head, int val,int x){
   
    node* n=new node(val);
    if(head==NULL){
      head=n;
      return;
    }
    node* temp=head;
    while(temp->data!=x){
      temp=temp->next;
    }

    n->next=temp->next;
    temp->next=n;
}

void display(node* head){
  node* temp=head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}


void todelete(node* &head,int val){
  if(head==NULL){
    return;
  }
  if(head->data==val){
    node* todel=head;
    head=todel->next;
    delete todel;
    return;
  }
  node* temp=head;
  while(temp->next->data!=val){
    temp=temp->next;
  }
  node* todel=temp->next;
  temp->next=todel->next;
  delete todel;
}


int main(){
  node* head=NULL;
  int x;
  insertAtTail(head,1);
  insertAtTail(head,2);
  insertAtTail(head,3);
  insertAtTail(head,4);
  insertAtTail(head,5);

  display(head);
  todelete(head,1);
  display(head);

  return 0;
}
