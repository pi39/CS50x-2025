/*
Author: pi39
*/
#include <stdio.h>
#include <math.h>
#include <stdbool.h> 

int credit_length(long credit_number);
bool checksum(long credit_number);
void credit_type(long credit_number);

int main(void)
{
    long credit_number;
    printf("Enter Credit Number: ");
    scanf("%li", &credit_number);
    
    credit_type(credit_number);
    
}

int credit_length(long credit_number)
{   // finds the length of credit number in digits

    long i = 1;
    int length = 0;

    while (credit_number / i != 0)
    {
        i *= 10;
        length++;
    }

    return length;
}

bool checksum(long credit_number)
{ // checks wether a credit number is vaild by luhn algorithm 

    int length = credit_length(credit_number);
    int even_pos_digits = 0;
    int odd_pos_digits = 0;

    for (int i = 2; i <= length; i += 2)
    { // for spliting each even postioned digit then multiply by 2 then adding it 
         long first = pow(10,i);
         long second = pow(10,i-1);
         long base = pow(10,i-1);

         int digit = ((credit_number % first) - (credit_number % second))/base;
			
         if (digit * 2 > 9)
         { // spliting it after multipling it if necceary
            even_pos_digits += (digit * 2) / 10;
            even_pos_digits += (digit * 2) % 10;
         }

         else
         {
            even_pos_digits += digit * 2;
         } 
    }

    for (int i = 1; i <= length; i += 2)
    { // for spliting each odd postioned digit then adding it 
         long first = pow(10,i);
         long second = pow(10,i-1);
         long base = pow(10,i-1);

         int digit = ((credit_number % first) - (credit_number % second))/base;

         odd_pos_digits += digit;
    }
    
    if ((even_pos_digits + odd_pos_digits) % 10 == 0)
    {
        return true;
    }

    else
    {
        return false;
    }
}

void credit_type(long credit_number)
{ //This function identify the type of card by the last two or one digit
	
    int length = credit_length(credit_number);

    if (checksum(credit_number) == false)
    {
        printf("INVALID");
    }

    else if (checksum(credit_number) == true)
    {
        int last_two_digit = credit_number / pow(10,length - 2);

        if (last_two_digit >= 51 && last_two_digit <= 55)
        {
            printf("MasterCard\n");
        }
        
        else if (last_two_digit == 34 || last_two_digit == 37)
        {
            printf("American Express\n");
        }
        
        else if (last_two_digit / 10 == 4)
        {
            printf("VISA\n");
        }
    }
}

/*
Tested Numbers: 
visa                4003600000000014    (Success)
invalid             6176292929          (Success)
invalid             4222220022222       (Success)
American Express 	378282246310005     (Success)
American Express 	371449635398431     (Success)
American Express  	378734493671000     (Success)
Mastercard 	        5555555555554444    (Success)
Mastercard 	        5105105105105100    (Success)
Visa 	            4111111111111111    (Success)
Visa 	            4012888888881881    (Success)
Visa 	            4222222222222       (Success)
*/
