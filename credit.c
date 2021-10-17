// Michael Caluris
// pset1 credit

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int length (long digit);
int checksum (long digit);
int prefix (long digit);

int main (void)
{

    long digit;

    do
    {
        digit = get_long ("Number: ");
    }
    while (digit < 0);
    
    if (checksum(digit) && prefix(digit) == 1 && length(digit))
    {
        printf("AMEX\n");
    }
    else if (checksum(digit) && prefix(digit) == 2 && length(digit))
    {
        printf("MASTERCARD\n");
    }
    else if (checksum(digit) && prefix(digit) == 3 && length(digit))
    {
        printf("VISA\n");
    }
    else 
    {
        printf("INVALID\n");
    }
    
}


int i = 0;

int length (long digit)
{
    while (digit > 0)
    {
        digit = digit / 10;
        i++;
    }
    if (i == 13 || i == 15 || i == 16)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

int sum = 0;
int temp = 0;
int temp2 = 0;

int checksum (long digit)
{
    while (digit > 0)
    {
        sum += digit % 10;
        digit = digit / 10;
        
        temp = digit % 10;
        temp2 = temp * 2;
        sum += temp2 % 10;
        sum += temp2 / 10;
        digit = digit / 10;
        
    }
    if (sum % 10 == 0)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

int prefix (long digit)
{
    while (digit > 100)
    {
        digit = digit / 10;
    }
    if (digit >= 40 && digit <= 49)
    {
        return 3;
    }
    else if (digit >=51 && digit <= 55)
    {
        return 2;
    }
    else if (digit == 34 || digit == 37)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
