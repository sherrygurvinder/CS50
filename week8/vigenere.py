import sys
if sys.argv!=2:
    print("enter key")
key=sys.argv[1]
keyval=[]
index=0
count=0
while index<len(key):
    keyval.append(ord(key[index])-97)
    print(keyval[index])
    index+=1
    count+=1
plaintext=(input("Plain Text:"))
i=0;index=0
avail=0;avail2=0
cipher=[]
while i <= len(plaintext)-1:
    if index==count:
        print(index,count)
        index =0
    if (ord(plaintext[i])>=97 and (ord(plaintext[i]))<=122):
        avail = 122 - ord(plaintext[i])
        if avail==0:
            cipher.append(chr(122+avail))
        elif avail>=keyval[index]:
            asc=ord(plaintext[i])
            cipher.append(chr(ord(plaintext[i])+keyval[index]))
        else:
            avail=keyval[index]-avail
            cipher.append(chr(97+avail-1))
        index=index+1
    elif (ord(plaintext[i]) >= 65 and (ord(plaintext[i])) <= 90):
        avail = 90 - ord(plaintext[i])
        if avail==0:
            cipher.append(chr(122+avail))
        elif avail >= keyval[index]:
            asc = ord(plaintext[i])
            cipher.append(chr(ord(plaintext[i]) + keyval[index]))
        else:
            avail = keyval[index] - avail
            cipher.append(chr(65 + avail - 1))
        index = index + 1
    else:
        cipher.append(plaintext[i])
    i=i+1
print("Cipher Text :",end="")
for i in cipher:
    print(i,end="")
print(" ")
