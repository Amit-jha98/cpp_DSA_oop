#include<stdio.h>
#include<stdlib.h>

struct Doubly_list{
    struct Doubly_list* prev;
    int data;
    struct Doubly_list* next;
};

struct Doubly_list *createNode(int value){
    struct Doubly_list *head = malloc(sizeof(struct Doubly_list));
    head->prev = NULL;
    head->data = value;
    head->next = NULL;
    return head;
}

struct Doubly_list *addFromStart(struct Doubly_list *head,int value){
    struct Doubly_list *temp;
    temp = createNode(value);
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

struct Doubly_list *addFromLast(struct Doubly_list *head, int value){
    struct Doubly_list *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = createNode(value);
    temp->next->prev = temp;
    return head;
}

struct Doubly_list *addAtPos(struct Doubly_list *head,int value,int pos){
    struct Doubly_list *temp = head;
    if(temp->next == NULL){
        temp->next = createNode(value);
    }else if(temp->prev == NULL){
        temp->prev = createNode(value);
    }

    for(int i = 0; i < pos-1; i++){
        temp = temp->next;
    }
    temp->next = createNode(value);
    temp->next->prev = temp;
    temp->next->next =

}

void printList(struct Doubly_list *head){
    struct Doubly_list *temp = head;
    while(temp != NULL){
    printf("%d ",temp->data);
    temp = temp->next;
    }
    printf("\n");

}

int main(){
    int value,size,choice,pos;
    struct Doubly_list *head = NULL;
    printf("Enter Number of Elements You want to add: \n");
    scanf("%d",&size);

    printf("Enter type of insertion: \n1=From start \n2=From End \n3=At given Position \n");
    scanf("%d",&choice);
    if(choice == 1 || choice == 2 || choice == 3){
        if(choice == 3){
            printf("Enter the position where You Want to add Value: \n");
            scanf("%d",&pos);
        }

    printf("Enter the Elements: \n");
    for(int i = 0; i < size; i++){
        scanf("%d",&value);
        if(head == NULL){
            head = createNode(value);
        }else{
            if(choice==1){
           head = addFromStart(head,value);
        }else if(choice == 2){
            head = addFromLast(head,value);
        }else if(choice == 3){
            // printf("Enter the position where You Want to add Value:  \n");
            // scanf("%d",&pos);
        head = addAtPos(head,value,pos);
    }}}}else{
        printf("Enter Valid choice \n");
        return 0;
    }

    printf("Your List is: \n");
    printList(head);
    return 0;
}