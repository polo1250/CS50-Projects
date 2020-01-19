# Get the right value for the height
while True:
    height = input("height: ")
    if (height.isdigit()) and (1 <= int(height) <= 8):
        height = int(height)
        break

# Print the pyramid
for i in range(1, height+1):
    print(" " * (height-i) + "#"*i + "  " + "#"*i)

