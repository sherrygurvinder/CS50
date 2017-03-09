n=int(input("Height:"))
for i in range(0,n):
    for j in range(0,n+2):
        if j+i<n:
            print(" ",end="")
        else:
            print("#",end="")
    print("")


