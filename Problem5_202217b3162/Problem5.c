#include<stdio.h>
#include<stdlib.h> // For exit() function

#define n 5

void main()
{
    int queue[n], ch = 1, front = 0, rear = 0, i, j = 1;
    printf("Queue using Array\n");
    printf("1.Insertion \n2.Deletion \n3.Display \n4.Exit\n");

    while(ch)
    {
        printf("\nEnter the Choice:");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                if(rear == n)
                    printf("\nQueue is Full\n");
                else
                {
                    printf("\nEnter number %d:", j++);
                    scanf("%d", &queue[rear++]);
                }
                break;

            case 2:
                if(front == rear)
                    printf("\nQueue is empty\n");
                else
                {
                    printf("\nDeleted Element is %d\n", queue[front++]);
                    // Decrementing 'x' as we dequeue an element
                    // x++;
                }
                break;

            case 3:
                printf("\nQueue Elements are:\n");
                if(front == rear)
                    printf("\nQueue is Empty\n");
                else
                {
                    for(i = front; i < rear; i++)
                    {
                        printf("%d\n", queue[i]);
                    }
                }
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Wrong Choice: please see the options\n");
                break;
        }
    }
}
