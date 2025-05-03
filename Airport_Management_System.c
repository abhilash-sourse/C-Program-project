#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLIGHTS 10
#define MAX_SEATS 50

typedef struct{
    int flight_id;
    char flight_name[50];
    int total_seats;
    int reserved_seats;
    int seat_status[MAX_SEATS];
} Flight;

Flight flights[MAX_FLIGHTS];
int flight_count = 0;

//initialize flight
void initialize_flight()
{
    flights[0] = (Flight){1,"Flight AA246",MAX_SEATS, 0 , {0}};
    flights[1] = (Flight){2,"Flight AB426",MAX_SEATS, 0 , {0}};
    flights[2] = (Flight){3,"Flight AC892",MAX_SEATS, 0 , {0}};
    flight_count = 3;
}

void display_flight()
{
    printf("Available Flight:\n");
    for(int i=0;i<flight_count;i++)
    {
        printf("Flight ID:%d\tFlight Name:%s\tTotal Seats:%d\tReserved Seats:%d\n\n",flights[i].flight_id,flights[i].flight_name,flights[i].total_seats,flights[i].reserved_seats);
    }
}

void reserve_seat()
    {
    int flight_id, seat_number;
    printf("Enter Flight ID: ");
    scanf("%d", &flight_id);
    
    Flight *selected_flight = NULL;
    for (int i = 0; i < flight_count; i++)
    {
        if (flights[i].flight_id == flight_id) 
        {
            selected_flight = &flights[i];
            break;
        }
    }

    if (selected_flight == NULL)
    {
        printf("Flight not found!\n");
        return;
    }

    printf("Enter Seat Number (1 to %d): ", selected_flight->total_seats);
    scanf("%d",&seat_number);

    if (seat_number < 1 || seat_number > selected_flight->total_seats)
    {
        printf("Invalid seat number!\n");
        return;
    }

    if (selected_flight->seat_status[seat_number - 1] == 1)
    {
        printf("Seat already reserved!\n\n");
    } else {
        selected_flight->seat_status[seat_number - 1] = 1; 
        selected_flight->reserved_seats++;
        printf("Seat %d reserved successfully on %s!\n", seat_number, selected_flight->flight_name);
    }
}

void display_reservations()
{
    int flight_id;
    printf("Enter Flight ID to view reservations: ");
    scanf("%d", &flight_id);
    
    Flight *selected_flight = NULL;
    for (int i = 0; i < flight_count; i++)
    {
        if (flights[i].flight_id == flight_id)
        {
            selected_flight = &flights[i];
            break;
        }
    }

    if (selected_flight == NULL)
    {
        printf("Flight not found!\n");
        return;
    }

    printf("Reservations for %s:\n", selected_flight->flight_name);
    int reserved_found = 0;
    for (int i = 0; i < selected_flight->total_seats; i++)
    {
        if (selected_flight->seat_status[i] == 1)
        {
            printf("\tSeat %d is reserved.\n\n", i + 1);
            reserved_found = 1;
        }
    }
    if (!reserved_found)
    {
        printf("No reservations yet.\n");
    }
}

int main()
{
    int choice;
    initialize_flight();
    do{
        printf("\tAirport Management System\n");
        printf("1.Display Flight\n");
        printf("2.Reserve Seats\n");
        printf("3.Display Resevations\n");
        printf("4.Exit\n");
        printf("Enter Your Chioce:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            display_flight();
            break;

            case 2:
            reserve_seat();
            break;

            case 3:
            display_reservations();
            break;

            case 4:
            printf("Exiting the System.\n");
            break;

            default:
            printf("Invalid choice! please Try Again\n");
        }
    }while(choice != 4);
    return 0;
}
