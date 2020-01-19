from cs50 import *
# Get the value from the user
while True:
    value = get_float("Change owed: ")
    if (int(value) >= 0):
        break

# Compute the total number of coins
value = int(value * 100)
coins = 0

while (value > 0):
    if (value >= 25):
        coins += (value // 25)
        value %= 25
    elif (value >= 10):
        coins += (value // 10)
        value %= 10
    elif (value >= 5):
        coins += (value // 5)
        value %= 5
    elif (value >= 1):
        coins += (value // 1)
        value %= 1

# Print out the number of coins
print(coins)
