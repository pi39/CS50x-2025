#include <stdio.h>
#include <math.h> 

int checksum( long number);
void card_type(long n);

int main(void)
{  
     // Ask  the user for credit number and store it
    long credit_number;
    printf("Number: ");
    scanf("%li", &credit_number);
    
    //checks if the card is valid or no
    checksum(credit_number);
     
    if (checksum(credit_number) % 10 != 0)
    {
        printf("\nINVALID\n");
    }

    else
    {
      card_type(credit_number);
    }
}

int checksum(long number)    
{   //Function checks if the card number is gas or ass by an eqation and other bullshit

    int second_to_last = 0;
    int first_to_beforelast = 0;


   for(int i = 16; i >= 1; i--)
   {    
         long first = pow(10,i);
         long second = pow(10,i-1);
         long base = pow(10,i-1);

         // Equation for isolating each digit
         long digit = ((number % first) - (number % second))/base;
        
         // Take the second to last digit, then multiply by 2, then adding them.
         if (i % 2 == 0 && i != 1)
         { 
            // For slpiting digits of n * 2 if two digit, then adding each digit to the rest.
            if ((digit * 2) > 9)
            {   
                for(int j = 1; j <= 2; j++)
                {
                     int third = pow(10,j);
                     int fourth = pow(10,j-1);
                     int base2 = pow(10,j-1);
                     int digit2 = ((digit * 2 % third) - (digit * 2 % fourth))/base2;

                     second_to_last += digit2;
                }
            }

            // just adding them.
            else if (digit * 2 <= 9)
            {
                 second_to_last += digit*2;
            }
         }

         // Take the rest (first to second last) and just adding them.
         else
         {
            first_to_beforelast += digit;
         }

   } //4003600000000014 5299999999999990

   // Final number, if first digit is 0, then card is valid
   int check = second_to_last + first_to_beforelast;
   
   return check;
}

void card_type(long n)
{
    int first_digit = 0, second_digit = 0, control = 15;

    for(int k = 16; k >= control; k--)
         {
             long third = pow(10,k);
             long fourth = pow(10,k-1);
             long base3 = pow(10,k-1);
             long digit3 = ((n % third) - (n % fourth))/base3;

             if(digit3 == 0)
               {
                control--;
               }

             if(k == control + 1)
                {   
                        first_digit += digit3;
                }

             else if(k == control)
                {
                        second_digit += digit3;
                }
        }

    if (first_digit == 5 && (second_digit == 1 || second_digit == 2 || second_digit == 3 || second_digit == 4 || second_digit == 5))
    {
        printf("MasterCard\n");
    }

    else if(first_digit == 3 && (second_digit == 4 || second_digit == 7))
    {
        printf("American Express\n");
    }
    
    else if (first_digit == 4)
    {
        printf("VISA\n");
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