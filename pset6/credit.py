import cs50
import math
print('Number: ',end='')
n=cs50.get_float()
n1=n
l=0
while n1!=0:
    n1=n1//10
    l+=1
n1=n
sum1=0
sum2=0
while n1!=0:
    temp=n1%100
    temp1=temp//10
    temp1=temp1*2
    while temp1!=0:
        t1=temp1%10
        sum1=sum1+t1
        temp1=temp1//10
    temp2=temp%10
    sum2=sum2+temp2
    n1=n1//100
if (sum1+sum2)%10==0:
    flag=0
else:
    flag=1

k=math.pow(10,l-2)
p=math.pow(10,l-1)
if flag==0:
    if l==15 and (n//k==35 or n//k==37): 
        print('AMEX')
    elif l==16 and (n//k==51 or n//k==52 or n//k==53 or n//k==54 or n//k==55):
        print('MasterCard')
    elif (l==16 or l==13) and (n//p==4) :
        print('Visa')
    else:
        print('Invalid')
elif flag==1:
    print('Invalid')