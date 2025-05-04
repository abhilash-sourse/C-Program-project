#include <stdio.h>
# include <stdlib.h>
#include <string.h>

#define MAX_ANIMALS 50

typedef struct{
    int Animal_id;
    char Name[50];
    char species[50];
    int age;
    char enclosure[50];
} Animal;

Animal zoo[MAX_ANIMALS];
int Animal_count = 0;

void initialize_zoo()
{
    zoo[0] = (Animal) {1.,"Tiger","Panthera Tigris",20,"Tiger Jungle"};
    zoo[1] = (Animal) {2.,"Lion","Panthera leo",18,"A Den"};
    zoo[2] = (Animal) {3.,"Giraffa","Giraffa Camelopardalis",17,"Giraffe Safari"};
    Animal_count = 3;
}

void display_animal()
{
    if(Animal_count == 0)
    {
        printf("No Animal in the zoo currently.\n");
        return;
    }

    printf("List of the Animal:\n");
    for(int i=0;i<Animal_count;i++)
    {
        printf("Animal ID:%d\tAnimal Name:%s\tAnimal Species:%s\tAnimal Age:%d\tAnimal Enclosure:%s\n",zoo[i].Animal_id,zoo[i].Name,zoo[i].species,zoo[i].age,zoo[i].enclosure);
    }
}

void add_animal()
{
    if(Animal_count >= MAX_ANIMALS)
    {
        printf("Zoo is fully!Cannot add more Animal.\n");
        return;
    }

    Animal new_Animal;
    new_Animal.Animal_id = Animal_count +1;

    printf("Enter Name of Animal:");
    getchar();
    fgets(new_Animal.Name,sizeof(new_Animal.Name),stdin);
    new_Animal.Name[strcspn(new_Animal.Name,"\n")] = 0;

    printf("Enter Species Name:");
    getchar();
    fgets(new_Animal.species,sizeof(new_Animal.species),stdin);
    new_Animal.species[strcspn(new_Animal.species, "\n")] =0;

    printf("Enter Age:");
    scanf("%d",&new_Animal.age);

    printf("Enter enclosure:");
    getchar();
    fgets(new_Animal.enclosure,sizeof(new_Animal.enclosure),stdin);
    new_Animal.enclosure[strcspn(new_Animal.enclosure, "\n")] =0;

    zoo[Animal_count] = new_Animal;
    Animal_count ++;
    printf("Animal Add Successfully ID details %d.\n",new_Animal.Animal_id);
}

void view_animail_detials()
{
    int id;
    printf("Enter Animal Id to view details:");
    scanf("%d",&id);

    for(int i=0;i<Animal_count;i++)
    {
        if(zoo[i].Animal_id == id)
        {
            printf("Animal details\n");
            printf("Animal ID:%d\t",zoo[i].Animal_id);
            printf("Animal Name:%s\t",zoo[i].Name);
            printf("Animal species:%s\t",zoo[i].species);
            printf("Animal Age:%d\t",zoo[i].age);
            printf("Animal Enclosure:%s\n",zoo[i].enclosure);
            return;
        }
    }
    printf("Ainmal Id %d not found.\n",id);
}

int main()
{
    int choice;
    initialize_zoo();
    do{
        printf("\n\tZoo Management System\n");
        printf("1.Display All Animal\n");
        printf("2.Add New Animal\n");
        printf("3.view Animal details\n");
        printf("4.Exit\n");
        printf("Enter your Choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            display_animal();
            break;

            case 2:
            add_animal();
            break;

            case 3:
            view_animail_detials();
            break;

            case 4:
            printf("Exiting zoo Management System\n");
            break;

            default:
            printf("Invalid choice tyr again.\n");
        }
    }while(choice!=4);
    return 0;
}