#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,string argv[])
{
    string ptext;
    int c,flag=0;
    if(argc==1||argc>2)
    {
       printf("Usage: ./vigenere k\n");
       return 1;
    }
    else
    {
    string k=argv[1];
    for(c=0;c<strlen(k);c++)
    {
        if(isalpha(k[c]))
        {
            flag=0;
            
        }
        else 
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }    
    }
    if(flag==0)
    {
    printf("plaintext: ");
    ptext=get_string();
    int l1=strlen(ptext);
    int l2=strlen(k);
    for(int a=0;a<l2;a++)
    {
        k[a]=toupper(k[a]);
        
    }
    printf("ciphertext: ");
    for(int i=0,j=0;i<l1;i++)
    {
        if(isalpha(ptext[i]))
        {
          if(isupper(ptext[i]))
          {
              
              c=(ptext[i]-65+k[j%l2]-65)%26+65;
              printf("%c",c);
          }
          else
          {
              c=(ptext[i]-97+k[j%l2]-65)%26+97;
              printf("%c",c);
          }
        
            j++;
        }
        else
        printf("%c",ptext[i]);
    
        
    }
    
    
    printf("\n");
        return 0;
    }
    
    }
    
}
