#include<stdio.h>
#include<cs50.h>
int main(void)
{
    int count=0,n;
    double m;
    do
    {
        printf("O hai! How much change is owed?\n");
        m=get_double();
    }while(m<0);

    m*=100;
    n=m;
    while(n>0)
    {
        if(n>=25)
        {
            count+=n/25;
            n=n%25;

        }
        else if(n>=10)
        {
            
            count+=n/10;
            n=n%10;

        }
        else if(n>=5)
        {
            count+=n/5;
            n%=5;

        }
        else if(n>=1)
        {
            
            count+=n/1;
            n%=1;

        }

    }
                printf("%i\n",count);
}