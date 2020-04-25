#include <stdio.h>
#include<stdlib.h>

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void search();
void reverse();

struct node{
    int data;
    struct node *next;
};

struct node *head;

int main(){
    int choice;
        while(1){
                printf(" \n               MENU                             \n");
                printf(" 1.Create     \n");
                printf(" 2.Display    \n");
                printf(" 3.Insert at the beginning    \n");
                printf(" 4.Insert at the end  \n");
                printf(" 5.Insert at specified position       \n");
                printf(" 6.Delete from beginning      \n");
                printf(" 7.Delete from the end        \n");
                printf(" 8.Delete from specified position     \n");
                printf(" 9.Search \n");
                printf(" 10. Reverse \n");
                printf(" 11.Exit       \n");
                printf("--------------------------------------\n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice){
                        case 1:
                                        create();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3: 
                                        insert_begin();
                                        break;
                        case 4:
                                        insert_end();
                                        break;
                        case 5:
                                        insert_pos();
                                        break;
                        case 6:
                                        delete_begin();
                                        break;
                        case 7:
                                        delete_end();
                                        break;
                        case 8:
                                        delete_pos();
                                        break;
                        case 9: 
                                        search();
                                        break;
                        case 10:    
                                        reverse();
                                        break;
                        case 11:
                                        exit(0);
                                        break;
                             
                        default:
                                        printf("\n Wrong Choice:");
                                        break;
                }
        }
        return 0;
}

void create(){
    struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL) {
                printf("\nOut of Memory Space:\n");
                exit(0);
        }
        printf("\nEnter the data value for the node:\t");
        scanf("%d",&temp->data);
        temp->next=NULL;
        if(head==NULL) {
                head=temp;
        } else {
                ptr=head;
                while(ptr->next!=NULL) {
                        ptr=ptr->next;
                }
                ptr->next=temp;
        }
}

void display(){
    struct node *ptr;
    if(head == NULL){
        printf("Linked List is Empty\n");
        return;
    } else {
        ptr = head;
        printf("\nThe Numbers in the list are: ");
        while(ptr!= NULL){
            printf("%d",ptr->data);
            ptr = ptr->next;
        }
    }
}

void insert_begin() {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("\nOut of Memory");
        return;
    }
    printf("\nEnter the data value to be inserted in the node");
    scanf("%d",&temp->data);
    temp->next = NULL;
    if(head==NULL){
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void insert_end(){
    struct node *temp,*ptr;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("\nOut of Memory");
        return;
    }
    printf("\nEnter the data value to be inserted in the node");
    scanf("%d",&temp->data);
    if(head==NULL){
        head = temp;
    } else {
        ptr = head;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next =temp;
    }
}

void insert_pos(){
    struct node *temp,*ptr;
    int i,pos;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL) {
                printf("\nOut of Memory Space:");
                return;
        }
        printf("\nEnter the position for the new node to be inserted:\t");
        scanf("%d",&pos);
        printf("\nEnter the data value of the node:\t");
        scanf("%d",&temp->data);
        temp->next = NULL;
        if(pos==0){
            temp->next = head;
            head = temp;
        } else {
            for(i=0;i<pos-1;i++){
                ptr = ptr->next;
                if(ptr==NULL){
                    printf("Position Not Found \n");
                    return;
                }
            }
            temp->next = ptr->next;
            ptr->next = temp;
        }
}

void delete_begin(){
    struct node *ptr;
    if(ptr==NULL){
        printf("\nOut of Memory Space:");
        return;
    } else {
        ptr = head;
        head = head->next;
        printf("Deleted the element\t%d",ptr->data);
        free(ptr);
    }
}

void delete_end(){
    struct node *ptr,*temp;
    if(ptr==NULL){
        printf("\nOut of Memory Space:");
        return;
    } else if(head->next == NULL){
        ptr = head;
        head = NULL;
        printf("\nDeleted the element\t%d",ptr->data);
        free(ptr);
    } else {
        ptr = head;
        while(ptr->next!= NULL){
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next=NULL;
        printf("nThe deleted element is:%dt",ptr->data);
        free(ptr);
    }
}

void delete_pos(){
    int i,pos;
        struct node *temp,*ptr;
        if(head==NULL){
            printf("\nThe List is Empty:n");
            exit(0);
        } else {
            printf("Enter the pos where you want do delete");
            scanf("%d",&pos);
            if(pos==0){
                ptr = head;
                head = head -> next;
                printf("\nThe deleted element is:%d\t",ptr->data);
            }
            else{
                ptr = head;
                for(i=0;i<pos;i++){
                    temp = ptr;
                    ptr = ptr->next;
                    if(ptr==NULL){
                        printf("\nPosition not Found:");
                        return;
                    }
                }
                temp->next=ptr->next;
                printf("\nThe deleted element is:%d\t",ptr->data);
                free(ptr);
            }
        }
}

void search(){
    int element;
    struct node *ptr;
    ptr = head;
    printf("\nEnter teh Element which you want to search");
    scanf("%d",&element);
    while(ptr!= NULL){
        int i = 0;
        i++;
        if(ptr->data == element){
            printf("\nElement found at Position : %d",i);
            return;
        }
        head = head->next;
    }
    printf("Key Not Found\n");
}

void reverse() {
    struct node *prevnode,*currnode;
    if(head!=NULL){
        prevnode = head;
        currnode =  head->next;
        head = head->next;
        prevnode->next = NULL;
    }
    while(head!=NULL){
        head = head-> next;
        currnode-> next = prevnode;
        prevnode = currnode;
        currnode = head;
    }
    head = prevnode;
    printf("Linked List Reversed");
}
