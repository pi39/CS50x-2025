/*
Author: pi39
This is the feeling comfortable one
*/
#include <stdio.h>

void pyrmad(int n);

int main(void)
{
    int hight;

    do
    {   //Asking the user for input & repating if its invalid.
        printf("Hight: ");
        scanf("%d",&hight);
    } while (hight < 1 || hight > 8);  

  //Function that prints the pyrmad
    pyrmad(hight);

}

void pyrmad(int rows)
{
    char hash = '#';
    char space = ' ';

    for(int current_row = 1; current_row <= rows; current_row++)
    {   
        int num_space = rows - current_row;
        int num_hash = current_row;

        //the amount of spaces in each row
        for(int j = 0; j < num_space; j ++)
        {
            printf("%c", space);
        }

        //the amount of brick in the firt tower
        for(int i = 0; i < num_hash; i++)
        {
            printf("%c",hash); 
        }

        //space between towers
        printf("  ");

        //the amount of brick in the second tower
        for(int k = 0; k < num_hash; k++)
        {
            printf("%c",hash); 
        }

        printf("\n");
    }

}
