#include<stdio.h>
#include<string.h>

char STR[100], PAT[100], REP[100], ANS[100];
int s, p, r, a, flag = 0;

void read() 
{
    printf("Enter the MAIN string: \n");
    scanf("%[^\n]", STR);  // Read entire line of text, including spaces
    
    printf("Enter a PATTERN string: \n");
    scanf("%s", PAT);

    printf("Enter a REPLACE string: \n");
    scanf("%s", REP);
}

void replace() 
{
    s = p = a = 0;
    while (STR[s] != '\0') 
    {
        // Checking for Match
        if (STR[s] == PAT[p]) 
        {
            p++;
            s++;
            // If the first character is matched, check for the entire PAT string
            if (PAT[p] == '\0') 
            {
                flag = 1;
                for (r = 0; REP[r] != '\0';) {
                    ANS[a] = REP[r];
                    a++;
                    r++; 
                }
                
                p = 0;  // Reset pattern index after replacement
            }
        } 
        else // Mismatch
        {
            ANS[a] = STR[s];
            s++;
            a++;
            p = 0;
        }
    }
}

void display() 
{
    if (flag == 0)
        printf("Pattern not found!!!\n");
    else 
    {
        printf("\nThe RESULTANT string is:\n%s\n", ANS);
    }
}

void main() 
{
    read();
    replace();
    display();  // Fixed this line by calling the correct function (display)
}