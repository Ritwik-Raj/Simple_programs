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
    printf("Element deleted\n");
    head->data--;
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
int main()
{
    NODE head;
    int choice, data;
    head = getNode();
    head->data = 0;
    head->left = head->right = NULL;
    while (1)
    {
        printf("\n1.Insert first\n2.Insert last\n3.Delete first\n4.Delete last\n5.Display\n6.Exit\nEnter the choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted :");
            scanf("%d", &data);
            head = insertFirst(head, data);
            break;

        case 2:
            printf("Enter the data to be inserted :");
            scanf("%d", &data);
            head = insertLast(head, data);
            break;

        case 3:
            head = deleteFirst(head);
            break;

        case 4:
            head = deleteLast(head);
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