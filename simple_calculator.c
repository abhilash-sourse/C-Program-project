#include <stdio.h>
int main()
{
    double num1,num2,result;
    char operator;
    char choice;
    

    printf("\n\tSimple Calculator\n");
    do{
        printf("Enter first Number:");
        scanf("%lf",&num1);

        printf("Enter Operator(+,,-,*,/):");
        scanf(" %c", &operator);

        printf("Enter Second Number:");
        scanf("%lf",&num2);

        switch(operator)
        {
            case '+':
            result = num1 + num2;
            printf("Result=%.2lf\n",result);
            break;

            case '-':
            result = num1 - num2;
            printf("Result=%.2lf\n",result);
            break;

            case '*':
            result = num1 * num2;
            printf("Result=%.2lf\n",result);
            break;

            case '/':
            if(num2 == 0)
            {
                printf("Error:Division by zero is undefined.");
            }else{
                result = num1 / num2;
                printf("Result=%d\n",result);
            }
            break;

            default:
            printf("Invalid operator! Please Enter (+ - * /)\n");
        }
        printf("Do you want to perform another calculater(y/n):");
        scanf(" %c", &choice);
    }while(choice == 'y' || choice == 'Y');

    printf("Exiting Calculator \nGood Bye!");
    return 0;
}