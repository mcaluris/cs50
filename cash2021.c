// Michael Caluris
// pset1

#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main (void)
{
    float change;

    do
    {
        change = get_float ("Changed owed: ");
    }
    while (change < 0);

    int cents = round (change * 100);
    int coins = 0;

    while (cents != 0)
    {
    
    coins += cents / 25;
    cents = cents % 25;
    
    coins += cents / 10;
    cents = cents % 10;
    
    coins += cents / 5;
    cents = cents % 5;
    
    coins += cents / 1;
    cents = cents % 1;
    
    }
    
    printf("%i\n", coins);
}
