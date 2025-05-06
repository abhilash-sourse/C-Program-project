#include <stdio.h>

unsigned long long factorial(int n)
{
    unsigned long long fact =1;
    for(int i=2;i<=n;i++)
    {
        fact *=i;
    }
    return fact;
}

int main()
{
    int num;
    char choice;
    printf("\tFactorial Calculator\n");

    do{
       printf("Enter a non-negative integer:") ;
       scanf("%d",&num);

       if(num < 0)
       {
        printf("Invalid input! plase enter a non-negitive intager number\n");
        }else{
            unsigned long long result = factorial(num);
            printf("Factorial of %d is %llu\n",num, result);
        }

        printf("Calculate another factorinal?(y/n):");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    
    printf("Exiting Factorial calculator.\n");
    return 0;
}