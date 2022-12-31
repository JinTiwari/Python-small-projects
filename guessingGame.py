from random import random, randrange

n = randrange(101)
attempts = 0
print ("Please guess the randomly genrated number in between 0 to 100!! ", "\nEnter your guess here:" , end="")

uInput = int(input())
if uInput > 100 or uInput<0:
    print("Please neter a valid number in your given range of guessing!!")
    exit(0)

while (True):
    if uInput>n:
        attempts = attempts + 1
        print ("Your number is greater than the gennerated number please enter a smaller value now: ")
        uInput = int (input())
    elif uInput<n:    
        attempts = attempts + 1
        print ("Your number is lesser than the gennerated number please enter a greater value now: ")
        uInput = int (input())
    else:
        attempts = attempts + 1
        print("Yayyy you have guessed it correctly!! ")
        break

print ("The number of attempts required by you to do this task is:",attempts)
