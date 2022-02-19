#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *NODE;
//NODE first = NULL; //no global declaration
NODE getNode()
{
    NODE x;
    x = (NODE)malloc(sizeof(NODE));
    if (x == NULL)
    {
        printf("Couldn't create a node\n");
        exit(0);
    }
    return x;
}
void printList(NODE first)
{
    NODE temp;
    temp = first;
    if (temp == NULL)
    {
        printf("List Empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
NODE insertLast(NODE first, int key)
{
    NODE temp;
    NODE ptr;
    ptr = first;
    temp = getNode();
    temp->data = key;
    temp->next = NULL;
    if (first == NULL)
    {
        //first = temp;
        //printf("Element is inserted\n");
        return temp;
    }
    while (ptr->next != NULL) //ptr->next is used here because there may be data part but the next part might be null so in order to find the link NUll part (next), we use ptr->next instead of ptr != NULL in while loop
    {
        ptr = ptr->next;
    }
    ptr->next = temp;

    //printf("Element inserted successfully\n");
    return first;
}
NODE deleteFirst(NODE first)
{
    NODE temp;
    temp = first;
    first = temp->next;
    printf("Node is deleted\n");
    return first;
}
void insertLocation(NODE first, int pos, int key)
{
    NODE prev, ptr, current;
    ptr = getNode();
    ptr->data = key;
    ptr->next = NULL;
    if (pos == 1)
    {
        ptr->next = first;
        first = ptr;
        printf("Element insertion successful");
        return;
    }
    current = first;
    prev = NULL;
    int count = 1;
    while (current != NULL && count != pos)
    {
        prev = current;
        current = current->next;
        count++;
    }
    if (count == pos)
    {
        prev->next = ptr;
        ptr->next = current;
        first = current;
        printf("Node inserted successfully\n");
    }
}
/*
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* prev, *ptr, *current;
    ptr = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
    ptr->data = data;
    ptr->next = NULL;
    if (position == 0)
    {
        ptr->next = llist;
        llist = ptr;
        //printf("Element insertion successful");
        return ptr;
    }
    prev = llist;
            ptr->data = data;
            for(int i = 0; i < position-1; i++) {
                prev = prev->next;
            }
            ptr->next = prev->next;
            prev->next = ptr;
    return llist;
}*/
NODE unite(NODE first, NODE second)
{
    NODE l1, l2, l3 = NULL;
    l1 = first;
    l2 = second;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data < l2->data)
        {
            l3 = insertLast(l3, l1->data);
            l1 = l1->next;
        }
        else if (l1->data > l2->data)
        {
            l3 = insertLast(l3, l2->data);
            l2 = l2->next;
        }
        else
        {
            l2 = l2->next;
        }
    }
    while (l1 != NULL)
    {
        l3 = insertLast(l3, l1->data);
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        l3 = insertLast(l3, l2->data);
        l2 = l2->next;
    }
    return l3;
}
NODE intersection(NODE first, NODE second)
{
    NODE t1, t2, t3=NULL;
    t1 = first;
    while (t1 != NULL)
    {
        t2 = second;
        while (t2 != NULL)
        {
            if (t1->data == t2->data)
            {
                t3 = insertLast(t3, t1->data);
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    return t3;
}

int main()
{
    NODE first, second, third;
    first = second = NULL;
    printf("Program to realize the union and intersection of linked lists\n");
    while (1)
    {
        int choice;
        int data, pos;
        printf("\n1: Insert to list 1\n2: Insert to list 2\n3: Delete from list 1\n4: Delete from list 2\n5: Display\n6: Union of the lists\n");
        printf("7: Intersection of the lists\n8: Exit");
        printf("\nEnter the choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the integer to be pushed to list 1:");
            scanf("%d", &data);
            first = insertLast(first, data);
            break;

        case 2:
            printf("\nEnter the integer to be pushed to list 2:");
            scanf("%d", &data);
            second = insertLast(second, data);
            break;

        case 3:
            first = deleteFirst(first);
            break;

        case 4:
            second = deleteFirst(second);
            break;

        case 5:
            printf("\nDisplaying the elements of list 1 :\n");
            printList(first);
            printf("\nDisplaying the elements of list 2 :\n");
            printList(second);
            break;

        case 6:
            printf("The ordered union of the lists is\n");
            printList(unite(first, second));

            break;

        case 7:
            printf("The intersection of the lists is\n");
            printList(intersection(first, second));
            break;

        case 8:
            printf("Program Terminated....\n");
            exit(0);

        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}