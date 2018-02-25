#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int id;
    struct node *prev;
    struct node *next;
};

void push(node **head_ref,int id){
    node *new_node=(node*)malloc(sizeof(node));
    new_node->id=id;

    new_node->next=*head_ref;
    new_node->prev=NULL;

    if(*head_ref!=NULL){
        (*head_ref)->prev=new_node;
    }
    *head_ref=new_node;
}

void insert_after(node *prev_node,int id){
    if(prev_node==NULL)
        return;

    node *new_node=(node*)malloc(sizeof(node));
      new_node->id=id;
      new_node->next=prev_node->next;
      prev_node->next=new_node;
      new_node->prev=prev_node;

      if(new_node->next!=NULL){
        new_node->next->prev=new_node;
      }

}

void end_insertion(node **head_ref,int id){
    node *last=*head_ref;
    node *new_node=(node*)malloc(sizeof(node));

    new_node->id=id;
    new_node->next=NULL;

    while(last->next!=NULL){
        last=last->next;
    }

    new_node->prev=last;
    last->next=new_node;
}

void printlist(node *n){
    while(n!=NULL){
        cout<<n->id<<endl;
        n=n->next;
    }
}

void delete_node(node **head_ref,int k){
    node *del=*head_ref;

    if(*head_ref==NULL)
        return;

    if(k==1){
        del->next->prev=NULL;
        *head_ref=del->next;
        free(del);
    }

    for(int i=2;i<=k;i++){
        del=del->next;
    }

    if(del->prev!=NULL){
        del->prev->next=del->next;

    }
    if(del->next!=NULL){
        del->next->prev=del->prev;
    }

    if(del->next==NULL){
        del->prev->next=NULL;
    }
    free(del);
}

int main(){
    node *head=NULL;
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    insert_after(head,7);
    end_insertion(&head,6);
    printlist(head);
    cout<<"After delete"<<endl;
    delete_node(&head,3);
    printlist(head);

}
