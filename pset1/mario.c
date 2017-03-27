#include<cs50.h>
#include<stdio.h>
int main(void)
{
    int h;
    do{
    printf("Height: ");
    h=get_int();
    }while(h<0 || h>23);
    
    if(h>0 || h<=23)
    {
        
    for(int i=1;i<=h;i++)
    {
        for(int j=h-1;j>=i;j--)
        {
            printf(" ");
        }
        for(int j=1;j<=i;j++)
        {
            printf("#");
        }
        printf("  ");
        for(int j=1;j<=i;j++)
        {
            printf("#");
        }
        printf("\n");
        
    }
    }
}