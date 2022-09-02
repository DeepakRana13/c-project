#include <stdio.h>
#include <stdlib.h>

int main()
{
    int roomno[10] = {11001, 11002, 11003, 11004, 11005, 11006, 9101, 9102, 9103, 9104};
    int time[10], slots[10];
    for (int i = 0; i < 10; i++)
    {
        time[i] = 1000;
        slots[i] = 100;
    }
    while (1)
    {
        int choice, choice2;
        printf("Press 1 to check room availability, 2 to exit\n");
        scanf("%d", &choice);
        if (choice == 2)
        {
            exit(1);
        }
        else
        {
            printf("Available rooms for Vaccination: ");
            for (int i = 0; i < 10; i++)
            {
                if (slots[i] == 0)
                {
                    continue;
                }
                else
                {
                    printf("%d | ", roomno[i]);
                }
            }
            printf("\n");
            printf("Press 1 to check availability in a particular room, 2 to find the earliest slot available\n");
            scanf("%d", &choice2);
            if (choice2 == 1)
            {
                int room;
                printf("Enter room number: ", &room);
                scanf("%d", &room);
                int check = 100;
                for (int i = 0; i < 10; i++)
                {
                    if (roomno[i] == room)
                    {
                        if (slots[i] == 0)
                        {
                            printf("No slots available in room no. %d", room);
                            break;
                        }
                        else
                        {
                            printf("Slot available at time %d, no. of slots available = %d\n", time[i], slots[i]);
                            check = i;
                            break;
                        }
                    }
                    else
                    {
                        printf("invalid room number\n");
                        break;
                    }
                }
                if (check != 100)
                {
                    int book, sap;
                    printf("Press 1 to book this room, 2 to go back to main menu\n");
                    scanf("%d", &book);
                    if (book == 1)
                    {
                        printf("Enter your SAP ID: ");
                        scanf("%d", &sap);
                        slots[check]--;
                        time[check] += 5;
                        printf("Your slot has been booked\n");
                    }
                }
            }
            else if (choice2 == 2)
            {
                int early = roomno[0], index;
                for (int i = 0; i < 10; i++)
                {
                    if (early > time[i] && slots[i] != 0)
                    {
                        early = time[i];
                        index = i;
                    }
                }
                printf("Earliest slot is available at room no %d, at time %d, no. of slots available = %d\n", roomno[index], time[index], slots[index]);
                int book, sap;
                printf("Press 1 to book this room, 2 to go back to main menu\n");
                scanf("%d", &book);
                if (book == 1)
                {
                    printf("Enter your SAP ID: ");
                    scanf("%d", &sap);
                    slots[index]--;
                    time[index] += 5;
                    printf("Your slot has been booked\n");
                }
            }
        }
    }
    return 0;
}