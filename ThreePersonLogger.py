
def getDate():
    import datetime
    var = str(datetime.datetime.now())
    return var

Jinendra = "Jin.txt"
Ramesh = "Ramesh.txt"
Kaartik = "Kaartik.txt"

def numErrorcheck(var):
    if var.isnumeric():
        return int(var)
    else :
        print ("Please enter a valid number and not any character or anything else!! ")
        exit()


def selection():    
    print ("Please choose your selection out of: " , "\n1.Log data" , "\n2.Get information")
    choice1 = input("Please enter your choice of number corresponding to you choice in the menu over here: ")

    choice1 = numErrorcheck(choice1)

    if choice1 == 1 or choice1 == 2:
        print ("Please select the person out of the given options ", "\n1.Jinendra" , "\n2.Ramesh" , "\n3.Kaartik")
        name = input("Please enter the number corresponding to your choice from the menu above: ")
        name = numErrorcheck(name)
        if name == 1 or name == 2 or name == 3:
            junction(choice1 , name)
        else:
            print ("Please enter a number from the options provided to you bro!! ")
            selection()
    else:
        print ("Please neter the number you are given in the option's list!! ")
        selection()

        
def junction(choice1 , name):
    if name == 1:
        name=Jinendra
    elif name == 2:
        name = Ramesh
    else:
        name = Kaartik

    if choice1 == 1:
        Log(name)
    else:
        getInfo(name)


def Log(name):
    with open (name , "a") as f1:
        log= input("Please enter what you want to log in: ")
        f1.write(getDate() + ":  " + log + "\n")
        print ("To continue you edit and information retrieve please enter any number")
        contInp = input()
        contInp = numErrorcheck(contInp)
        selection()

def getInfo(name):
    with open (name , "r" ) as f1:
        print ("The information currently in the file is: ")    
        content = f1.read()
        print (content)
        print ("To continue you edit and information retrieve please enter any number")
        contInp = input()
        contInp = numErrorcheck(contInp)
        selection()
        
selection()
