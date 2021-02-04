from cs50 import get_float

dollar = get_float("Change owed: ")
if dollar < 0:
    print ("Enter non-negative value")
    dollar = get_float("Change owed: ")
    
total_change = dollar * 100

coins = 0

while total_change > 0: 
    if total_change >= 25:
        total_change = total_change - 25
        coins += 1
    elif total_change >= 10: 
        total_change = total_change - 10
        coins += 1
    elif total_change >= 5:
        total_change = total_change - 5
        coins += 1
    else:
        total_change = total_change - 1
        coins += 1
    
print(coins)