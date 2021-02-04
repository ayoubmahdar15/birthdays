from cs50 import get_int

while True:
    ## User input for Height 
    height = get_int("Height: ") 
    if height < 1 or height > 8:
        height = get_int("Height: ")
    
    ## Pattern for printing 
for i in range(height):
    print ((height - 1 - i) * " ", end="")
    print ((i + 1) * "#")




