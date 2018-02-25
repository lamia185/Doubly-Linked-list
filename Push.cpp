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
    node *last;
    cout<<"Front direction"<<endl;
    while(n!=NULL){
        cout<<n->id<<endl;
        last=n;
        n=n->next;
    }

    cout<<"Last direction"<<endl;
    while(last!=NULL){
        cout<<last->id<<endl;
        last=last->prev;
    }
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

}
