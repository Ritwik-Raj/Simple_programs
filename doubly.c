#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *right, *left;
};
typedef struct node *NODE;
NODE getNode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("Node Cannot be created\n");
        exit(0);
    }
    return x;
}
NODE insertFirst(NODE head, int key)
{
    NODE temp;
    temp = getNode();
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    if (head->right == NULL)
    {
        head->right = temp;
        temp->left = head;
        printf("Element inserted successfully\n");
        head->data++;
        return head;
    }
    temp->right = head->right;
    head->right = temp;
    temp->left = head;
    printf("Element inserted successfully\n");
    head->data++;
    return head;
}
NODE insertLast(NODE head, int key)
{
    NODE temp, ptr;
    ptr = getNode();
    ptr->data = key;
    ptr->right = NULL;
    ptr->left = NULL;
    temp = head;
    if (head->right == NULL)
    {
        head->right = ptr;
        ptr->left = head;
        printf("Element inserted successfully\n");
        head->data++;
        return head;
    }
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    temp->right = ptr;
    ptr->left = temp;
    printf("Element inserted successfully\n");
    head->data++;
    return head;
}
NODE insertPos(NODE head, int data, int pos)
{
    NODE temp, ptr;
    int i = 1; //to go to the previous node of the position and to start position from 1
    temp = head->right;
    ptr = getNode();
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    if (pos == 1)
    {
        insertFirst(head, data);
        return head;
    }
    else
    {
        /*for (int i = 1; i < pos-1; i++)    // same use of i=1
        {
            if (temp != NULL)
            {
                temp=temp->right;
            }
            
        }*/
        //another iterative method for the same thing

        while (i < pos - 1 && temp != NULL)
        {
            temp = temp->right;
            i++;
        }
        //work by traversing to the previous node to the position
        //adjust the links accordingly
        ptr->right = temp->right;
        ptr->left = temp;
        temp->right = ptr;
        temp->right->left = ptr;                   //both temp->right->left = ptr; and ptr->right->left = ptr; will work;
        printf("Element inserted successfully\n"); //ptr->right->left = ptr;
        head->data++;
        return head;
    }

    return head;
}
void display(NODE head)
{
    NODE temp;
    if (head->right == NULL)
    {
        printf("%d<-List Empty\n", head->data);
        return;
    }
    temp = head->right;
    printf("%d<-", head->data);
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->right;
    }
}
NODE deleteFirst(NODE head)
{
    NODE temp;
    temp = head->right;
    if (head->right == NULL)
    {
        printf("Nothing to delete....List empty\n");
        return head;
    }
    head->right = temp->right;
    head->data--;
    printf("Element deleted\n");
    free(temp);
    return head;
}
NODE deleteLast(NODE head)
{
    NODE temp, ptr;
    temp = ptr = head->right;
    if (temp == NULL)
    {
        printf("Nothing to delete.....List Empty\n");
        return head;
    }

    else if (temp->right == NULL)
    {
        head->right = NULL;
        printf("Element deleted\n");
        free(temp);
        head->data--;
        return head;
    }
    while (temp->right != NULL)
    {
        ptr = temp;
        temp = temp->right;
    }
    ptr->right = NULL;
    printf("Element deleted\n");
    free(temp);
    head->data--;
    return head;
}
void deletePos(NODE head, int data)
{
    NODE temp, p;
    p = head;
    if (p->right == NULL)
    {
        printf("Empty list\n");
        return;
    }
    else
    {

        while (p->right != NULL)
        {
            if (p->right->data == data)
            {
                temp = p->right;
                p->right = temp->right;

                printf("%d is deleted\n", data);

                head->data--;
                free(temp);
            }
            p = p->right;
        }
    }
}
/*NODE deletepos(NODE head,int pos){
    NODE temp;
    temp = head->right;
    if (temp == NULL)
    {
        printf("Nothing to delete\n");
        return head;
    }
    if (pos == 1)
    {
        head = deleteFirst(head);
        return head;
    }
    for (int i = 1; i < pos-1; i++)
    {
        if (temp != NULL)
        {
            temp=temp->right;
        }
    }
    temp->right = temp->right->right;
    temp->right->left = temp;
    return head;
}*/
int main()
{
    NODE head;
    int choice, data, pos;
    head = getNode();
    head->data = 0;
    head->left = head->right = NULL;
    while (1)
    {
        printf("\n1.Insert Last\n2.Insert at position\n3.Delete first\n4.Delete position\n5.Display\n6.Exit\nEnter the choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted :");
            scanf("%d", &data);
            head = insertLast(head, data);
            break;

        case 2:
            printf("Enter the data to be inserted :");
            scanf("%d", &data);
            printf("Enter position to insert :");
            scanf("%d", &pos);
            head = insertPos(head, data, pos);
            break;

        case 3:
            head = deleteFirst(head);
            break;

        case 4:
            printf("Enter position to delete :");
            scanf("%d", &pos);
            deletePos(head, data);
            break;

        case 5:
            display(head);
            break;

        case 6:
            exit(0);
            break;

        default:
            printf("Invalid Input....\n");
            break;
        }
    }
    return 0;
}