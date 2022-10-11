#include<stdio.h>
#include<stdlib.h>
 
// structure of the node
struct node
{
    struct node* prev;
    int data;
    struct node* next;
};
 

struct node* head = NULL;
 

struct node* create(int);
void insert_begin(int);
void insert_end(int);
void insert_mid(int, int);
void delete_begin();
void delete_end();
void delete_mid();
int search(int);
void update(int, int);
void sort();
int list_size();
void display();
void display_reverse(struct node*);
int get_data();
int get_position();
 
int main()
{
    char user_active = 'Y';
    int user_choice;
    int data, position;
 
    while(user_active == 'Y' || user_active == 'y')
    {
        printf("\n\n------ Circular Doubly Linked List -------\n");
        printf("\n1. Insert a node at beginning");
        printf("\n2. Insert a node at end");
        printf("\n3. Insert a node at given position");
        printf("\n\n4. Delete a node from beginning");
        printf("\n5. Delete a node from end");
        printf("\n6. Delete a node from given position");
        printf("\n\n7. Print list from beginning");
        printf("\n8. Print list from end");
        printf("\n9. Search a node data");
        printf("\n10. Update a node data");
        printf("\n11. Sort the list");
        printf("\n12. Exit");
        printf("\n\n------------------------------\n");
 
        printf("\nEnter your choice: ");
        scanf("%d", &user_choice);
 
        printf("\n------------------------------\n");
        switch(user_choice)
        {
            case 1:
                printf("\nInserting a node at beginning");
                data = get_data();
                insert_begin(data);
                break;
 
            case 2:
                printf("\nInserting a node at end");
                data = get_data();
                insert_end(data);
                break;
 
            case 3: 
                printf("\nInserting a node at the given position");
                data = get_data();
                position = get_position();
                insert_mid(position, data);
                break;
 
            case 4: 
                printf("\nDeleting a node from beginning\n");
                delete_begin();
                break;
 
            case 5: 
                printf("\nDeleting a node from end\n");
                delete_end();
                break;
 
            case 6: 
                printf("\nDelete a node from given position\n");
                position = get_position();
                delete_mid(position);
                break;
 
            case 7: 
                printf("\nPrinting the list from beginning\n\n");
                display();
                break;
 
            case 8: 
                printf("\nPrinting the list from end\n\n");
                if (head == NULL)
                {
                    printf("\n\tList is Empty!\n");
                } else {
                    display_reverse(head);
                }
                break;
 
            case 9:
                printf("\nSearching the node data");
                data = get_data();
                if (search(data) == 1) {
                    printf("\n\tNode Found\n");
                } else {
                    printf("\n\tNode Not Found\n");
                }
                break;
 
            case 10:
                printf("\nUpdating the node data");
                data = get_data();
                position = get_position();
                update(position, data);
                break;
 
            case 11:
                sort();
                printf("\nList was sorted\n");
                break;
            case 12:
                printf("\nProgram was terminated\n\n");
                return 0;
 
            default:
                printf("\n\tInvalid Choice\n");
        }
 
        printf("\n...............................\n");
        printf("\nDo you want to continue? (Y/N) : ");
        fflush(stdin);
        scanf(" %c", &user_active);
    }
 
    return 0;
}
 

struct node* create(int data)
{
    struct node* new_node = (struct node*) malloc (sizeof(struct node));
 
    if (new_node == NULL)
    {
        printf("\nMemory can't be allocated\n");
        return NULL;
    }
 
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
 
    return new_node;
}
 
// insert a new node at the beginning of the list
void insert_begin(int data)
{
    struct node* new_node = create(data);
 
    if (new_node)
    {
        // if list is empty
        if (head == NULL)
        {
            new_node->next = new_node;
            new_node->prev = new_node;
            head = new_node;
            return;
        }
        head->prev->next = new_node;
        new_node->prev = head->prev;
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}
 
// inserts a new node at the end 
void insert_end(int data)
{
    struct node* new_node = create(data);
 
    if (new_node)
    {
        if (head == NULL)
        {
            new_node->next = new_node;
            new_node->prev = new_node;
            head = new_node;
            return;
        }
        head->prev->next = new_node;
        new_node->prev = head->prev;
        new_node->next = head;
        head->prev = new_node;
    }
}
 
// inserts node at the given position
void insert_mid(int position, int data)
{
    // checking if the position is valid or not
    if (position <= 0)
    {
        printf("\nInvalid Position\n");
    } else if (head == NULL && position > 1) {
        printf("\nInvalid Position\n");
    } else if (head != NULL && position > list_size()) {
        printf("\nInvalid Position\n");
    } else if (position == 1) {
        insert_begin(data);
    } else {
        struct node *new_node = create(data);
 
        if (new_node != NULL) {
            struct node *temp = head, *prev = NULL;
            int i = 1;
 
            // traverse the list to the given position
            while (++i <= position) {
                prev = temp;
                temp = temp->next;
            }
 
            // update the prev node to the new noe
            prev->next = new_node;
 
            // update the new node to the temp (position node)
            new_node->next = temp;
        }
    }
}
 
void delete_begin()
{
    if (head == NULL) {
        printf("\nList is Empty\n");
        return;
    } else  if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
 
    struct node* temp = head;
    head->prev->next = head->next;
    head->next->prev = head->prev;
    head = head->next;
 
    free(temp);
    temp = NULL;
}   
 
// deletes the node from the end of the list
void delete_end()
{
    if (head == NULL) {
        printf("\nList is Empty\n");
        return;
    } else  if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
 
    struct node* last_node = head->prev;
 
    last_node->prev->next = head;
    head->prev = last_node->prev;
 
    free(last_node);
    last_node = NULL;
}
 
// deletes the node from the given position
void delete_mid(int position)
{
    if (position <= 0) {
        printf("\n Invalid Position \n");
    }
    else if (position > list_size()) {
        printf("\n Invalid position \n");
    }
    else if (position == 1) {
        delete_begin();
    }
    else if (position == list_size()) {
        delete_end();
    }
    else {
        struct node *temp = head;
        struct node *prev = NULL;
        int i = 1;
 
        while (i < position) {
            prev = temp;
            temp = temp->next;
            i += 1;
        }
        prev->next = temp->next;
        temp->next->prev = prev;
        free(temp);
        temp = NULL;
    }
}
 
// search the node with the given key item
int search(int key)
{
    if (head == NULL) {
        printf("\n Not Found \n");
        return 0;
    }
 
    struct node* temp = head;
    do
    {
        if (temp->data == key) {
            return 1;
        }
        temp = temp->next;
    } while (temp != head);
 
    return 0;
}
 
// updates the data of the given node position
void update(int position, int new_value)
{
    if (head == NULL) {
        printf("\n  List is Empty \n");
        return;
    } else if (position <= 0 || position > list_size()) {
        printf("\nInvalid position\n");
        return;
    } 
 
    struct node* temp = head;
    int i = 0;
 
    while (++i < position) {
        temp = temp->next;
    }
    temp->data = new_value;
}
 
 
// sorts the linked list data using insertion sort
void sort()
{
    if (head == NULL) {
       printf("\nList  is Empty\n");
       return;
    }
    struct node* temp1 = head;
    struct node* temp2 = head;
    int key = 0, value;
 
    do {
        temp2 = temp1->next;
 
        while(temp2 != head)
        {
            if (temp1->data > temp2->data)
            {
                value = temp1->data;
                temp1->data = temp2->data;
                temp2->data = value;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }while (temp1->next != head);
 
}
 
 
// display the list
void display()
{
    if (head == NULL) {
        printf("\nList is empty!\n");
        return;
    }
 
    struct node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}
 
// display the list from end to start
void display_reverse(struct node* temp)
{
    if (temp->next == head) {
        printf("%d ", temp->data);
        return;
    }
 
    display_reverse(temp->next);
    printf("%d ", temp->data);
}
 
// calculate the size of the list
int list_size()
{
    if (head == NULL) {
        return 0;
    }
 
    struct node* temp = head;
    int count = 0;
 
    do {
        count += 1;
        temp = temp->next;
    } while (temp != head);
 
    return count;
}
 
 
int get_data()
{
    int data;
    printf("\n\nEnter Data: ");
    scanf("%d", &data);
 
    return data;
}
 
int get_position()
{
    int position;
    printf("\n\nEnter Position: ");
    scanf("%d", &position);
 
    return position;
}
