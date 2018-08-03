#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int size;
    int *queue = NULL;
    int front, rear;
    int i, choice;

    printf("Enter size of queue: ");
    scanf("%u", &size);

    queue = (int *)calloc(size, sizeof(int));

    rear = front = -1;
    do
    {
        system("cls");

        printf("Size of queue = %u\n\n", size);

        printf("1. Enqueue element\n");
        printf("2. Dequeue element\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if ((rear + 1)%size == front)
            {
                printf("\nQueue is FULL.\n\n");
                system("pause");
            }
            else
            {
                printf("\nEnter element to enqueue: ");
                if (front == -1)
                    front = 0;
                rear = (rear + 1)%size;
                scanf("%d", &queue[rear]);
            }
            break;
        case 2:
            if (front == -1)
                printf("\nQueue is EMPTY.\n\n");
            else
            {
                printf("\nElement dequeued: %d\n\n", queue[front]);

                if (front == rear)
                    front = rear = -1;
                else if (front == size - 1)
                    front = 0;
                else
                    front++;
            }
            system("pause");
            break;
        case 3:
            if (front == -1)
                printf("\nQueue is EMPTY.\n");
            else
            {
                printf("\nElements in queue are:\n");
                for (i = front; i != rear; i = (i + 1)%size)
                    printf("%d: %d\n", i, queue[i]);
                printf("%d: %d\n", i, queue[i]);          //talako ko jastai ho
                //printf("%d: %d\n", rear, queue[rear]);
            }
            printf("\n");
            system("pause");
            break;
        case 4:
            free(queue);
            break;
        default:
            printf("\nWrong option\n\n");
            system("pause");
        }
    }while (choice != 4);

    return 0;
}
