import cs50
import sys
k=int(sys.argv[1])
print('plaintext: ',end='')
ptext=cs50.get_string()
l=len(ptext)
print('ciphertext: ',end='')
for c in ptext:
    if c.isalpha:
        if ord(c)>=65 and ord(c)<=90:
            i=(ord(c)-65+k)%26+65
            print(chr(i),end='')
        else:
            i=(ord(c)-97+k)%26+97
            print(chr(i),end='')
    else:
        print(c,end='')
print()        