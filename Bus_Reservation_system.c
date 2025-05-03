#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUSES 10
#define MAX_SEATS 30

typedef struct{
    int bus_no;
    char bus_name[50];
    int total_seats;
    int reserved_seats;
    int seat_status[MAX_SEATS];
} Bus;

Bus buses[MAX_BUSES];
int bus_count = 0;

//Initialize some buse
void initialize_buses()
{
    buses[0] = (Bus){1,"Bus A",MAX_SEATS,0,{0}};
    buses[1] = (Bus){2,"BUS B",MAX_SEATS,0,{0}};
    bus_count = 2;
}

void display_buses()
{
    int i;
    printf("Available Buses:\n");
    for(i=0;i < bus_count;i++)
    {
        printf("Bus_no:%d\nname:%s\nTotal_seats:%d\nReserved_seats:%d\n",buses[i].bus_no,buses[i].bus_name,buses[i].total_seats,buses[i].reserved_seats);        
    }
}

void reseve_seat()
{
    int bus_no,seat_number;
    printf("Enter bus number:");
    scanf("%d",&bus_no);

    //find the bus
    Bus *selected_bus = NULL;
    int i;
    for(i=0;i<bus_count;i++)
    {
        if(buses[i].bus_no == bus_no)
        {
            selected_bus = &buses[i];
            break;
        }
    }

    if(selected_bus == NULL)
    {
        printf("Bus not found!\n");
        return;
    }

    printf("Enter Seat Number (1 to %d):",selected_bus->total_seats);
    scanf("%d",&seat_number);

    if(seat_number < 1 || seat_number > selected_bus->total_seats)
    {
        printf("Invalid Seat Number\n");
        return;
    }

    if(selected_bus->seat_status[seat_number - 1] == 1)
    {
        printf("Seat alread reserved!\n");
    }else{
        selected_bus->seat_status[seat_number -1] == 1;
        selected_bus->reserved_seats++;
        printf("seat %d\nReserved successfully on %s\n",seat_number,selected_bus->bus_name);
    }
}

void display_reservation()
{
    int bus_no;
    printf("Enter Bus Number to view reservation:");
    scanf("%d",&bus_no);

    int i;
    Bus *selected_bus = NULL;
    for(i=0;i<bus_count;i++)
    {
        if(buses[i].bus_no == bus_no)
        {
            selected_bus = &buses[i];
            break;
        }
    }

    if(selected_bus == NULL)
    {
        printf("Bus not found!");
        return;
    }

    printf("Reservations for %s:\n",selected_bus->bus_name);
    for(int i=0;i<selected_bus->total_seats;i++)
    {
        if(selected_bus->seat_status[i] ==1)
        {
            printf("seat %d is reserved.\n",i=1);
        }
    }
}

//over input
int main()
{
    int choice;
    initialize_buses();

    do{
        printf("\nBus Reservation System\n");
        printf("1.Display Buses\n");
        printf("2.Reserve Seat\n");
        printf("3.Display Reservations\n");
        printf("4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            display_buses();
            break;

            case 2:
            reseve_seat();
            break;

            case 3:
            display_reservation();
            break;

            case 4:
            printf("Enter the system.\n");
            break;

            default:
            printf("Invalid choice! Plase try again.\n");
        }
    }while(choice != 4);
        return 0;
}