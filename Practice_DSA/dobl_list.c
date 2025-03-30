#include<stdio.h>
#include<stdlib.h>

struct DDL{
    struct DDL *prev;
    int data;
    struct DDL *next;
};

struct DDL *createNode(int value){
    struct DDL *head = malloc(sizeof(struct DDL));
    head->prev = NULL;
    head->data = value; 
    head->next = NULL;
    return head;

}

struct DDL *addFromStart(struct DDL * head, int value){
    struct DDL *temp; 
    temp = malloc(sizeof(struct DDL));
    temp = createNode(value);
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

struct DDL *addFromEnd(struct DDL * head, int value){
    struct DDL *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = createNode(value);
    temp->next->prev = temp;
    return head;
}

struct DDL *addAtPos(struct DDL *head, int value, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return head;
    }

    if (position == 1)
        return addFromStart(head, value);

    struct DDL *temp = head;
    int count = 1;

    // Traverse to the node before the desired position
    while (temp->next != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    struct DDL *newNode = createNode(value);
    
    // If inserting at the end
    if (temp->next == NULL) {
        temp->next = newNode;
        newNode->prev = temp;
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;

    return head;
}

void display(struct DDL *head){
    struct DDL *temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int value,size,pos;
    struct DDL *head = NULL;
    printf("Enter the Number of Element you want to add in to linked list: \n");
    scanf("%d",&size);
    printf("Enter the position where you want to add the element: \n 1=Start \n 2=End \n 3=Any Position \n");
    scanf("%d",&pos);
    if(pos==1 || pos==2 || pos==3){
    printf("Add elements: \n");
    for(int i=0;i<size;i++){
        scanf("%d",&value);
        if(head==NULL){
            head = createNode(value);
    }else{
        if(pos==1){
            head = addFromStart(head,value);
        }else if(pos==2){
            head = addFromEnd(head,value);
        }else if(pos==3){
            printf("Enter the position: \n");
            int position;
            scanf("%d",&position);
            if(position>0 && position<=size){
                // printf("Enter the value: \n");
                // scanf("%d",&value);
        head = addAtPos(head,value,position);
    }else{
        printf("Invalid Position");
        return 0;
    }
    }}}}else{
        printf("Invalid Position");
        return 0;
    }
    
    printf("Your List is: ");
    display(head);
    return 0;
}
