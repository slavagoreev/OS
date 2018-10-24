#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *head = NULL;
struct Node *list = NULL;
int size = 0;

void insert_node(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        list = newNode;
    }
    list->next = newNode;
    list = list->next;
    printf("Inserted: %d\n", value);
    size++;
}

void delete_node(int value){
    struct Node *temp = head;
    printf("Deleted: %d\n", value);
    if (temp->data == value) {
        head = head->next;
        free(temp);
        return;
    }
    while(temp->next!= NULL) {
        if (temp->next->data == value) {
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
}

void print_list(){
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int ex3() {
    printf("\nEX 3\n");

    insert_node(1);
    insert_node(2);
    insert_node(3);
    delete_node(2);
    delete_node(1);
    print_list();

    printf("\n-----\n");
    return 0;
}