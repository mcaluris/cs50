/*Harvard cs50 2020
Problem set 1 cash
Michael Caluris*/

#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    float input_change;
    int change;
    
    do {
        input_change = get_float("Change: ");
        change = round (input_change * 100);
    }
    while (change <= 0);
        
        int quarters = change / 25;
        int dimes = (change % 25) / 10;
        int nickles = ((change % 25) % 10) / 5;
        int pennies = (((change % 25) % 10) % 5);
        
        printf("%i\n" ,quarters + dimes + nickles + pennies);
}
