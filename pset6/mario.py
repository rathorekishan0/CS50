import cs50
n=cs50.get_int()
for i in range(2,n+2):
    print(' '*(n-i-1+2),end='')
    print('#'*i,end='')
    print()
