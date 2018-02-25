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

void pairsum(node *head,int x){
        node *first=head;
        node *sec=head;

        while(sec->next!=NULL){
            sec=sec->next;
        }

        bool found=false;

        while(first!=NULL && sec!=NULL && first!=sec &&sec->next!=first){
            if((first->id+sec->id)==x){
                found=true;
                cout<<"Found"<<endl;

            first=first->next;
            sec=sec->prev;
            }
        else{
            if((first->id+sec->id)<x)
                first=first->next;

            else
                sec=sec->prev;

        }
    }
        if(!found)
            cout<<"Not found"<<endl;

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
    pairsum(head,5);
    printlist(head);

}

