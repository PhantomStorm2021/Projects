#Souvik Kar
#Roll A Dice
#5/18/2020

import random

choice = str(input("Roll The Dice Answer Yes Or No In Caps Please:"))

while choice == "Yes":
    dice1 = random.randint(1,6)
    dice2 = random.randint(1,6)
    total = dice1 + dice2 
    
    print("Dice 1:", dice1)
    print("Dice 2:", dice2)
    print("Total:", total)

    if total == 12:
        print("Boxcars!")
    if total == 2:
        print("Snake Eyes!")
    choice = str(input("Roll The Dice AGAIN Answer Yes Or No In Caps Please:"))
    if choice == "No":
        break 
   


