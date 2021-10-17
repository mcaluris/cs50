/*Harvard cs50 2020
Problem set 1 Mario 2 
Michael Caluris*/


#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height=0;
    do {
        height = get_int("Height: ");
    }
    while(height<1 || height>8);
    
    if (height>0 && height<9) {
        
        for (int row=0;row<height;row++) {
            
            for (int space=(height-1)-row;space>0;space--) {
                
                printf(" ");
                
            }
            
            for (int hash=0;hash<=row;hash++) {
                
                printf("#");
            }
            
            printf(" ");
            
            for (int hash2=0;hash2<=row;hash2++) {
                
                printf("#");
            }
            
            printf("\n");
        }
    }
}
