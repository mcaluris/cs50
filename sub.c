// Michael Caluris
// pset2 substitution

#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool allalpha (string key);
int checkforrepeats (string key);
char encript (string key, char x);

int main(int argc, string argv[])
{
    string key;
    if(argc == 2)
    {
        key = argv[1];
        string plaintext;
        int len;
        int p;
        int q;
        int s;
        int t;
        string x;
        int cun;
        int counter=0;
        if(allalpha(key))
        {
            if(strlen(key) == 26)
            {
                if(checkforrepeats(key))
                {
                    plaintext = get_string("plaintext: ");
                    string alpha = "abcdefghijklmnopqrstuvwxyz";
                    cun = strlen(plaintext);
                    char ciphertext[cun+1];
                    ciphertext[cun] = '\0'; 
                    int a;
                    int b;
                    int c;
                    string final;
                    for (a=0, b=strlen(plaintext);a<=b;a++)
                    {
                        if(b==a)
                        {   
                            final = ciphertext;
                            printf("ciphertext: %s", final);
                            printf("\n");
                        }
                         else if(isalpha(plaintext[a])==0)
                        {
                            ciphertext[a] = plaintext[a];
                        }
                        else if(isupper(plaintext[a])==0) 
                        {
                            ciphertext[a] = tolower (encript(key, plaintext[a]));
                        }
                        else
                        {
                            ciphertext[a] = toupper (encript(key, plaintext[a]));       
                        }
                    }

                }
                else
                {
                    printf("Key must contain 26 different characters.\n");
                    return 1;
                }
            }
            else
            {
                printf("Key must contain 26 characters.\n");
                return 1;
            }
        }
        else
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    
}

bool allalpha (string key)
{
    int i;
    int k;
    int g=0;
    for (i = 0,k = strlen(key);i < k;i++)
    {
        if (isalpha(key[i])==0)
        {
            g++;
        }
    }
    if(g != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int checkforrepeats (string key)
{
    int z;
    int y;
    int m;
    int n;
    int total=0;
    for (z='a', y = 'z'; z <= y; z++)
    {
        for (m=0, n = strlen(key); m < n; m++)
        {
            if (z == tolower(key[m]))
            {
                total++;
                break;
            }
        }
    }
    if (total == 26)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



char encript (string key, char x)
{
    int f;
    int g;
    int store=0;
    int a;
    int b;
    string alph = "abcdefghijklmnopqrstuvwxyz";
    char out=0;
    for(g=0,f=strlen(key);g<f;g++)
    {
        if(toupper(x) == toupper(alph[g]))
        {
            break;
        }
        else
        {
            store++;
        }
    }
    out = key[store];
    return out;
}   
