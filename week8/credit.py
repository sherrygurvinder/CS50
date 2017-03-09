while 1:
	try:
		n =int(input("Number:"))
		break
	except ValueError:
		print("Retry")
i =1
temp1= 0;temp = 0;
sum = 0;sum1=0;sum2=0
result=0;final=0;count = 0
n1=0;n3=0;n4=0
n3 = n;n1 = n;n4 = n
while n3 != 0:
    count=count+1
    n3 = n3 // 10
while n1 != 0:
    n = n1 % 10
    n1 = n1 // 10
    if i % 2 == 0:
        temp=0
        temp=temp+n
        temp=temp*2
        if temp >= 10:
            sum1=temp // 10
            sum2=temp % 10
            sum=sum1+sum2
            result=result+sum
        else:
            result=result+temp
    else:
        temp1=temp1+n
    i=i+1
final = temp1 + result
if final % 10 == 0:
    if count == 15 and (n4 // 10 ** 13 == 34 or n4 // 10 ** 13 == 37):
        print("Amex\n")
    elif count == 16 and(n4 // 10 ** 14 == 51 or n4 // 10 ** 14 == 52 or n4 // 10 ** 14 == 53 or n4 // 10 ** 14 == 54 or n4 // 10 ** 14 == 55):
        print("Master Card\n")
    elif (count == 13 or count == 16) and (n4 // 10 **12 == 4 or n4 // 10 ** 15 == 4):
        print("Visa\n")
    else:
        print("INVALID")
print(final)
