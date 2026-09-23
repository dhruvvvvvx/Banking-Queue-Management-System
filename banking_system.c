// banking system using circular queue : Printing the current queue and the waiting time of the customers in the queue

#include <stdio.h>

#define SIZE 5
int front = -1;
int rear = -1;
int queue[SIZE];
int waiting_time[SIZE];
int token = 100;

int enqueue(int choice, int prev_choice)
{
    int time;
    if ((rear + 1) % SIZE == front)
    {
        printf("---REQUEST FULL! PLEASE TRY LATER!---\n");
        token++;
        printf("Token number : %d\n", token);
        return 0;
    }
    if (front == -1)
    {
        front = 0;
        rear = (rear + 1) % SIZE;
        queue[rear] = choice;
        waiting_time[rear] = 0;
        return 1;
    }
    int prev_rear = rear;
    rear = (rear + 1) % SIZE;
    queue[rear] = choice;

    if (prev_choice == 1)
        time = 10;
    else if (prev_choice == 2)
        time = 20;
    else if (prev_choice == 3)
        time = 30;

    waiting_time[rear] = waiting_time[prev_rear] + time;
    return 1;

    // return 0 -> customer not inserted
    // return 1 -> customer inserted
}

int dequeue()
{
    if (front == -1)
    {
        printf("---NO CUSTOMER IN QUEUE---\n");
        return -1;
    }

    int del_cust = queue[front];

    int served_time;
    if (del_cust == 1)
        served_time = 10;
    else if (del_cust == 2)
        served_time = 20;
    else if (del_cust == 3)
        served_time = 30;

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
        int j = front;
        while (1)
        {
            waiting_time[j] = waiting_time[j] - served_time;
            if (j == rear)
                break;
            j = (j + 1) % SIZE;
        }
    }
    return del_cust;
}

void current_status()
{
    if (front == -1)
    {
        printf("---NO CURRENT REQUEST---\n");
        return;
    }
  
    printf("CURRENT QUEUE : \n");
    printf("Request NO.\tWaiting Time\n");
    int j = front;
    while (1)
    {
        printf("%d\t%d\n", queue[j], waiting_time[j]);

        if (j == rear)
        {
            break;
        }
        j = (j + 1) % SIZE;
    }
    printf("\n");
}

int main()
{
    int choice, result, prev_choice = -1;

    do
    {
        printf("\n1.Balance Check \n2.Loan Enquiry \n3.Deposit \n4.Dequeue \n5.Current Status \n6.Exit \nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (enqueue(choice, prev_choice))
            {
                prev_choice = choice;
            }
            break;
        case 2:
            if (enqueue(choice, prev_choice))
            {
                prev_choice = choice;
            }
            break;
        case 3:
            if (enqueue(choice, prev_choice))
            {
                prev_choice = choice;
            }
            break;
        case 4:
            result = dequeue();
            printf("CUSTOMER EXITED : %d\n", result);
            if (front == -1)
            {
                prev_choice = -1;
            }
            break;
        case 5:
            current_status();
            break;
        case 6:
            printf("---THANK YOU! YOU'VE SUCCESSFULLY EXITED!---\n");
            break;
        default:
            printf("---INVALID CHOICE---\n");
            break;
        }
    } while (choice != 6);
}