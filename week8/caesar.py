import sys
if sys.argv!=2:
    print(" enter key")
key=sys.argv[1]
key=int(key)
if key>=26:
    key=key%26
plaintext=(input("Plain Text:"))
i=0
avail=0;avail2=0
key=int(key)
cipher=[]
while i <= len(plaintext)-1:
    if (ord(plaintext[i])>=97 and (ord(plaintext[i]))<=122):
        avail = 122 - ord(plaintext[i])
        if avail==0:
            cipher.append(chr(122+avail))
        elif avail>key:
            asc=ord(plaintext[i])
            cipher.append(chr(ord(plaintext[i])+key))
        else:
            avail=key-avail
            cipher.append(chr(97+avail-1))
    elif (ord(plaintext[i]) >= 65 and (ord(plaintext[i])) <= 90):
        avail = 90 - ord(plaintext[i])
        if avail==0:
            cipher.append(chr(90+avail))
        elif avail > key:
            asc = ord(plaintext[i])
            cipher.append(chr(ord(plaintext[i]) + key))
        else:
            avail = key - avail
            cipher.append(chr(65 + avail - 1))
    else:
        cipher.append(plaintext[i])
    i=i+1
print("Cipher Text :",end="")
for i in cipher:
    print(i,end="")
print(" ")