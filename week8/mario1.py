n=int(input("enter the value of n:"))
for x in range(0,n):
	for y in range(1,n+n+1):
		if y==n+1:
			print("  ",end="")
		if ((n+1)+x)<y or y+x<n:
			print(" ",end="")
		else:
			print("#",end="")

	print()		