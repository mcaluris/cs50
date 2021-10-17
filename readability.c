// Michael Caluris
// pset2 Readability

#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    string text;
    int letters = 0;
    int words = 0;
    float floatwords = 0;
    int sentences = 0;
    int i;
    int len;
    float l = 0;
    float s = 0;
    float index = 0;

    
    //prompt user for text
    text = get_string("Text: ");
    
    //count total # of sentences, letters & (words - 1)
    for (i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;      
        }
        else if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentences++;     
        }
        else if (text[i] == ' ' && text[i + 1] != ' ')
        {
            words++;
        }
    }
        //change words to float value for Coleman-Liau index & add 1 total 
        floatwords = words + 1.0;
        
        //cmpute average number of letters per 100 words
        l = (letters / floatwords) * 100;
        
        //compute average number of sentences per 100 words
        s = (sentences / floatwords) * 100;
        
        //compute Coleman-Liau index for grade level
        index = 0.0588 * l - 0.296 * s - 15.8;
        
        //round final result
        index = round(index);
            
        //print grade level  
       if (index < 1)
       {
           printf("Before Grade 1\n");
       }
       else if (index > 15)
       {
           printf("Grade 16+\n");
       }
       else
       {
           printf("Grade %i\n", (int)index);
       }
        
}
