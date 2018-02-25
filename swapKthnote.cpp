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
        cout<<n->id<<" ";
        n=n->next;
    }
    cout<<endl;
}

int count_nodes(node *n){
    int coun=0;
    while(n!=NULL){
        coun++;
        n=n->next;
    }
    return coun;
}

void swap_node(node **head_ref,int k){
    int n=count_nodes(*head_ref);

    if(n<k)
        return;

    if(2*k-1==n)
        return;

    node *x=*head_ref;
    node *x_prev=NULL;

    for(int i=1;i<k;i++){
        x_prev=x;
        x=x->next;
    }

    node *y=*head_ref;
    node *y_prev=NULL;

    for(int j=1;j<n-k+1;j++){
        y_prev=y;
        y=y->next;
    }

    if(x_prev!=NULL)
        x_prev->next=y;

    if(y_prev!=NULL)
        y_prev->next=x;

    node *temp=x->next;
    x->next=y->next;
    y->next=temp;

       if(k==1)
        (*head_ref)=y;
    if(k==n)
        (*head_ref)=x;
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

    for(int i=1;i<=8;i++){
        swap_node(&head,i);
        cout<<"Modified lists for i= "<<i<<endl;
        printlist(head);
    }

}

