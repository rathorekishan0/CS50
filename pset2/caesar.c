#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,string argv[])
{
    string ptext;
    int c;
    if(argc==1||argc>2)
    {
       printf("Usage: ./caesar k\n");
       return 1;
    }
    else
    {
    int k=atoi(argv[1]);
    printf("plaintext: ");
    ptext=get_string();
    int l=strlen(ptext);
    printf("ciphertext: ");
    for(int i=0;i<l;i++)
    {
        if(isalpha(ptext[i]))
        {
          if(ptext[i]>=65&&ptext[i]<=90)
          {
              c=(ptext[i]-65+k)%26+65;
              printf("%c",toupper(c));
          }
          else
          {
              c=(ptext[i]-97+k)%26+65;
              printf("%c",tolower(c));
          }
        }
        else
        printf("%c",ptext[i]);
    }
    printf("\n");
    
        return 0;
    }
 
}