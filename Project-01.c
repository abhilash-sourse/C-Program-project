#include <stdio.h>
#include <stdlib.h>

char arr[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; 
void displayBoard();
int checkWin();
int checkDraw();

int main()
{
    int player = 1; 
    int choice, i;
    char mark;

    do {
        displayBoard(); 
        player = (player % 2) ? 1 : 2; 
        printf("Player %d, enter your move (1-9): ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';
        if(choice == 1 && arr[1] =='1')
        {
            arr[1] = mark;
        }else if(choice == 2 && arr[2] == '2')
        {
            arr[2] = mark;
        }else if(choice == 3 && arr[3] == '3')
        {
            arr[3] = mark;
        }else if(choice == 4 && arr[4] == '4')
        {
            arr[4] = mark;
        }else if(choice == 5 && arr[5] == '5')
        {
            arr[5] = mark;
        }else if(choice == 6 && arr[6] == '6')
        {
            arr[6] = mark;
        }else if(choice == 7 && arr[7] == '7')
        {
            arr[7] = mark;
        }else if(choice == 8 && arr[8] == '8')
        {
            arr[8] = mark;
        }else if(choice == 9 && arr[9] == '9')
        {
            arr[9] = mark; 
        } else {
            printf("Invalid move! Try again.\n");
            player--; 
            getchar(); 
            getchar();
            getchar();
        }

        i = checkWin();
        if (i == -1 && checkDraw()) {
            i = 0; 
        }
        player++; 
    } while (i == -1);

    displayBoard(); 

    if (i == 1) {
        printf("Player %d wins!\n", --player); 
    } else {
        printf("Game Draw!\n");
    }

    getchar(); 
    return 0;
}

void displayBoard()
{
    system("cls"); 
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", arr[1], arr[2], arr[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", arr[4], arr[5], arr[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", arr[7], arr[8], arr[9]);
    printf("     |     |     \n\n");

}


int checkWin()
{
 
    if ((arr[1] == arr[2] && arr[2] == arr[3]) || 
        (arr[4] == arr[5] && arr[5] == arr[6]) || 
        (arr[7] == arr[8] && arr[8] == arr[9]) || 
        (arr[1] == arr[4] && arr[4] == arr[7]) ||
        (arr[2] == arr[5] && arr[5] == arr[8]) || 
        (arr[3] == arr[6] && arr[6] == arr[9]) ||
        (arr[1] == arr[5] && arr[5] == arr[9]) ||
        (arr[3] == arr[5] && arr[5] == arr[7])) 
        
    {
        return 1; 
    }
    return -1;
}

int checkDraw()
{
    for (int i = 1; i <= 9; i++) {
        if (arr[i] == ('0' + i)) {
            return 0; 
        }
    }
}