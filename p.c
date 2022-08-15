//include header files
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//keeps a track of the number of marked for deleted elements
//will be used when recalling the last marked node
int countdel = 0;

//define the structure of node
struct NODE
{
    double data;
    struct NODE *next;
    int flag;    //stores 1 if the node is unmarked and 0 if the node is marked
    int deltime; //stores the order in which the elements are deleted
};

//define the structure of the list
struct LIST
{
    struct NODE *head;
    struct NODE *tail;
};

//function to create a node with data as item
struct NODE *createNode(double item)
{
    struct NODE *nn = (struct NODE *)malloc(sizeof(struct NODE));
    nn->data = item;
    nn->next = NULL;
    nn->flag = 1;
    nn->deltime = -1;
    return nn;
}

//add element to the beginning of the SLL
void addFirst(struct LIST *lst, double item)
{
    struct NODE *nn = createNode(item);
    if (lst->head == NULL)
    {
        lst->head = nn;
        lst->tail = nn;
        return;
    }
    nn->next = lst->head;
    lst->head = nn;
    return;
}

//add element to the end of the SLL
void addLast(struct LIST *lst, double item)
{
    struct NODE *nn = createNode(item);
    if (lst->head == NULL)
    {
        lst->head = nn;
        lst->tail = nn;
        return;
    }
    lst->tail->next = nn;
    lst->tail = nn;
}

//this function is called whenever the number of marked nodes exceeds the number of unmarked elements
//this function actually deletes and deallocates the memory of the marked nodes
void deletemarked(struct LIST *lst)
{
    printf("\nMarked elements actually deleted");
    struct NODE *temp;
    struct NODE *prev; //keeps track of node prior to temp
    //we create a new node with data INFINITY
    //the next of this node is the head of the SLL
    //then we make this node as the new node of the SLL
    prev = createNode(INFINITY);
    prev->next = lst->head;
    lst->head = prev;
    for (temp = lst->head->next; temp != NULL; temp = prev->next)
    {
        if (temp->flag == 0)
        {
            //changes the address of the next of the previous element to the next of the current element
            //deallocates the memory allocated for the current element
            prev->next = temp->next;
            free(temp);
        }
        else
        {
            prev = temp;
            lst->tail = temp;
        }
    }
    //now we change the delete the head that we had created in the beginning and change it to the new head
    prev = lst->head;
    lst->head = lst->head->next;
    free(prev);
    //restore the countdel value to 0, as now no nodes are marked
    countdel = 0;
    return;
}

//this function checks if the number of marked nodes exceeds the number of unmarked nodes
//calls the deletemarked function in case the condition is met
void check(struct LIST *lst)
{
    int count1 = 0, count2 = 0; //keeps track of the number of marked and unmarked elements respectively
    struct NODE *temp = NULL;
    for (temp = lst->head; temp != NULL; temp = temp->next)
    {
        if (temp->flag == 0)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }
    if (count1 > count2)
    {
        deletemarked(lst);
    }
    return;
}

//this function marks the first unmarked element in the SLL and calls the check function
double delFirst(struct LIST *lst)
{
    double todel = INFINITY;
    if (lst->head == NULL) //returns infinity if the SLL is empty
    {
        return todel;
    }
    else if (lst->head == lst->tail)
    {
        //we directly delete the element and deallocate the memory because the condtion is already met and so, we need not mark it
        todel = lst->head->data;
        free(lst->head);
        lst->head = NULL;
        lst->tail = NULL;
        return todel;
    }
    else
    {
        struct NODE *temp = lst->head;
        //this loop runs till we get a flag of 1 and breaks out
        //hence after this loop, temp stores the address of the first unmarked element
        for (temp = lst->head; temp != NULL; temp = temp->next)
        {
            if (temp->flag == 1)
            {
                break;
            }
        }
        todel = temp->data;
        temp->flag = 0;
        //we increment the value of the number of marked elements
        countdel++;
        //we store this order in deltime
        temp->deltime = countdel;
        //we call the check function to check for the condtion
        check(lst);
        return todel;
    }
}

//this function marks the last unmarked element in the SLL and calls the check function
double delLast(struct LIST *lst)
{
    double todel = INFINITY;
    if (lst->head == NULL) //returns infinity if the SLL is empty
    {
        return todel;
    }

    //we directly delete the element and deallocate the memory because the condtion is already met and so, we need not mark it
    else if (lst->head == lst->tail)
    {
        todel = lst->head->data;
        free(lst->head);
        lst->head = NULL;
        lst->tail = NULL;
        return todel;
    }
    else
    {
        struct NODE *temp = lst->head;
        struct NODE *last = NULL; //stores the address of the last unmarked element
        for (temp = lst->head; temp != NULL; temp = temp->next)
        {
            if (temp->flag == 1)
            {
                last = temp;
            }
        }
        todel = last->data;
        last->flag = 0;
        //we increment the total number of marked elements
        countdel++;
        //we store this order in deltime
        last->deltime = countdel;
        //we call the check function to check for the condition
        check(lst);
        return todel;
    }
}

//this function marks the ith node amongst all unmarked nodes in the SLL and calls the check function
double delNode(struct LIST *lst, int n)
{
    double todel = INFINITY;
    if (lst->head == NULL) //returns infinity if the SLL is empty
    {
        return todel;
    }

    //we directly delete the element and deallocate the memory because the condtion is already met and so, we need not mark it
    else if (lst->head == lst->tail && n == 1)
    {
        todel = lst->head->data;
        free(lst->head);
        lst->head = NULL;
        lst->tail = NULL;
        return todel;
    }
    else
    {
        int count = 0;
        struct NODE *temp = NULL;
        for (temp = lst->head; temp != NULL; temp = temp->next)
        {
            if (temp->flag == 1)
            {
                count++; //increments the value of count till count becomes equal to n
            }
            if (count == n)
            {
                //marks the nth node amongst all the unmarked nodes
                temp->flag = 0;
                //increments the value of countdel which stores the count of marked elements
                countdel++;
                //define the order of deletion of temp to countdel
                temp->deltime = countdel;
                todel = temp->data;
                break;
            }
        }
        //calls the check function
        check(lst);
        return todel;
    }
}

//this function returns the size of the SLL, only including the unmarked elements
int size(struct LIST *lst)
{
    int count = 0;
    for (struct NODE *temp = lst->head; temp; temp = temp->next)
    {
        if (temp->flag == 1)
        {
            count++;
        }
    }
    return count;
}

//this function prints all the unmarked elements of the SLL
void display(struct LIST *lst)
{
    printf("\n{");
    struct NODE *temp = NULL;
    for (temp = lst->head; temp != NULL; temp = temp->next)
    {
        if (temp->flag == 1)
        {
            printf(" %.2lf ", temp->data);
        }
    }
    printf("}\n");
}

//this function restores the last marked for deleted element back to the SLL and prints its data
//this function unmarkes the last marked node
//incase there are nodes to recall or the deleted nodes have already been deallocated, we simply display an error message
void recallNode(struct LIST *lst)
{
    if (countdel == 0)
    {
        printf("\nno nodes left to recall\n");
        return;
    }
    struct NODE *temp = NULL;
    for (temp = lst->head; temp != NULL; temp = temp->next)
    {
        if (temp->deltime == countdel) //if the order of deletion of the marked element equals the total number of marked elements
        {

            temp->flag = 1;
            temp->deltime = -1;
            //we decrease the value of the number of marked element
            countdel--;
            printf("\nRecalled element is: %.2lf\n", temp->data);
            display(lst);
            return;
        }
    }
}

int main()
{
    struct LIST lst; //initialize the SLL
    lst.head = NULL; //initialize the head of the SLL to NULL
    lst.tail = NULL; //initialize the tail of the SLL to NULL
    int inp, idx;
    double val;
    printf("Enter 1 for addFirst\n");
    printf("Enter 2 for addLast\n");
    printf("Enter 3 for delFirst\n");
    printf("Enter 4 for delLast\n");
    printf("Enter 5 for Delete ith node\n");
    printf("Enter 6 for Display\n");
    printf("Enter 7 for Size\n");
    printf("Enter 8 for Recall\n");
    printf("Enter 9 for Exit\n");
    while (1)
    {
        printf("\nEnter Menu Option: ");
        scanf("%d", &inp);
        switch (inp)
        {
        case 1:
            printf("\nEnter value to add in the beginning: ");
            scanf("%lf", &val);
            addFirst(&lst, val);
            display(&lst);
            printf("\nElement added");
            break;
        case 2:
            printf("\nEnter value to add in the end: ");
            scanf("%lf", &val);
            addLast(&lst, val);
            display(&lst);
            printf("\nElement added");
            break;
        case 3:
            delFirst(&lst);
            display(&lst);
            printf("\nElement deleted");
            break;
        case 4:
            delLast(&lst);
            display(&lst);
            printf("\nElement deleted");
            break;
        case 5:
            printf("\nEnter position of node to be deleted where position 1 means 1st node and so on: ");
            scanf("%d", &idx);
            delNode(&lst, idx);
            display(&lst);
            printf("\nElement deleted");
            break;
        case 6:
            printf("\nCurrent list is: ");
            display(&lst);
            break;
        case 7:
            printf("\nCurrent size of list is: %d", size(&lst));
            break;
        case 8:
            recallNode(&lst);
            break;
        case 9:
            printf("\nExiting...");
            return 0;
        default:
            printf("\nExiting...");
            return 0;
        }
    }
}