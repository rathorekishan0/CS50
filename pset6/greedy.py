import cs50
count=0
print("O hai! How much change is owed?")
m=cs50.get_float();
m=m*100
while m>0:
    if m>=25:
        count+=m//25
        m%=25
    elif m>=10:
        count+=m//10
        m%=10
    elif m>=5:
        count+=m//5
        m%=5
    elif m>=1:
        count+=m//1
        m%=1
print(count)        