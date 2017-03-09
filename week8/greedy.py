while 1:
	try:
		x = float(input("O hai! How much change is owed?\n"))
		amount=x*100
		break
	except ValueError:
		print("Retry")
CoinList=[25,10,5,1]
coin=0;temp=0;i=0
amount1=int(amount)
while amount1 != 0:
	if amount1 >= CoinList[i]:
		temp = (amount1 / CoinList[i])
		amount1 = (amount1 % CoinList[i])
		coin = coin + temp
	else:
		i+=1

print(int(coin))

