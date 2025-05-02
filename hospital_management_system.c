#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_DOCTORS 50

//paticent details
typedef struct{
    int id;
    char name[50];
    int age;
    char disease[100];
} Patient;

//doctor details
typedef struct{
    int id;
    char name[50];
    char specialization[50];
} Doctor;
 
Patient patients[MAX_PATIENTS];
Doctor doctor[MAX_DOCTORS];
int patientcount = 0;
int doctorcount = 0;

//patient input
void addpatient()
{
    if(patientcount >= MAX_PATIENTS)
    {
        printf("patient liment reached\n");
        return;
    }
    Patient p;
    p.id = patientcount + 1;
    printf("Enetr patient name:");
    scanf("%s",p.name);
    printf("Enter patient age:");
    scanf("%d",&p.age);
    printf("Enter disease:");
    scanf("%s",p.disease);
    patients[patientcount ++] = p;
    printf("Patient added sucessfully\n");
}

void viewpatients()
{
    if(patientcount == 0)
    {
       printf("No patients found!\n");
       return;
    }
    int i;
    printf("List of Patients:\n");
    for(i=0;i<patientcount;i++)
    {
        printf("ID:%d\nName:%s\nAge:%d\nDisease:%s\n",patients[i].id,patients[i].name,patients[i].age,patients[i].disease);
    }
}

//doctor input
void addDoctor()
{
    if(doctorcount >= MAX_DOCTORS)
    {
        printf("Doctor limit reached\n");
        return;
    }
    Doctor d;
    d.id = doctorcount + 1;
    printf("Enter Doctor Name:");
    scanf("%s",d.name);
    printf("Enter specialization:");
    scanf("%s",d.specialization);
    doctor[doctorcount++] = d;
    printf("Doctor added successfully!\n");
}

void viewDoctor()
{
    if(doctorcount ==0)
    {
        printf("No doctors found!\n");
        return;
    }
    int i;
    printf("List of Doctors:\n");
    for(i=0;i<doctorcount;i++)
    {
        printf("ID:%d\nName:%s\nSpecialization:%s\n",doctor[i].id,doctor[i].name,doctor[i].specialization);
    }
}

//over input
int main()
{
    int choice;
    do{
        printf("\nHostital Management System\n");
        printf("1.Add Patients\n");
        printf("2.View Patients\n");
        printf("3.Add Doctor\n");
        printf("4.View Doctors\n");
        printf("5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            addpatient();
            break;

            case 2:
            viewpatients();
            break;

            case 3:
            addDoctor();
            break;

            case 4:
            viewDoctor();
            break;

            case 5:
            printf("Exiting the system.\n");
            break;

            default:
            printf("Invalid choice! please try again.\n");
        }
    }while(choice != 5);
    return 0;
}
