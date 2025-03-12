#include<stdio.h>
#include<stdlib.h>



struct linked_list
{
    int data;
    struct linked_list *link;
};



void insert (struct linked_list *head,int item[]){
struct linked_list *current = malloc(sizeof(struct linked_list));


    head->data = item;
    head->link = NULL;

    current->data = item;
    current->link = NULL;
    head->link = current;
    
}

int main(){
    struct linked_list *head = malloc(sizeof(struct linked_list));

    int item[2];
    printf("Enter the Etem you want to Insert: ");
    for(int i=0;i<=1;i++){
    scanf("%d",&item);
    insert(&head,item);
    }

    printf("head is %d\n",head->data);
    printf("current is %d",head->link->data);
    return 0;
}
