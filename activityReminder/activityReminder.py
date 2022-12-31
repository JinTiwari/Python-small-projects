#for 8 hours job 3.5 l of water , eye exer every 30 min and physical activity every 45min so scale it to whatever time u need
# 8    3.5 
# x    y     => y = 3.5 (x) / 8 litres of water evry 1 one hour we need to drink 500 ml approx 
# 1 hour water , 30 min eye and 45 min exer
import time

logList = ["WaterLog.txt" , "EyeLog.txt" , "ExerciseLog.txt"]

def date ():
    from datetime import datetime
    now = datetime.now()
    date_time = now.strftime("%m/%d/%Y, %H:%M:%S")
    return f"Date and time: {date_time}"

def numErrorcheck(var):
    var = str(var)
    if var.isnumeric():
        return float(var)
    else :
        print ("Please enter a valid number and not any character or anything else!! ")
        exit()

def UserChoice():
    print ("Please enter the time for which are going to work and then accordingly our pre planed structure will implemenet the number of breaks you will be getting",
            "the number of glasses of water to drink etc!! ")

    inputStr = input("Please enter the number of hours of work here: ")
    inputStr = numErrorcheck(inputStr)
    return inputStr

def makeTimeList(numHours ):
    numMin = 60*numHours
    value = numMin / 15.0
    TimeList = []
    for i in range (int(value)):
        TimeList.append((15*(i+1)*60) )
    TimeList = TimeList[::-1]
    return TimeList
    
def timematchCheck(check , startTime):
    time.sleep(check - (time.time() - startTime) - 30)
    start = time.time()
    diff = 0
    while (diff < 60):
        if (int(time.time()) - int(startTime)) == check:
            return True
        diff = time.time() - start
    return False

def playCheck(name , length , logname):
    import pygame
    pygame.mixer.init()
    bool = True
    while bool:
        pygame.mixer.music.load(name)
        pygame.mixer.music.play()
        time.sleep(length)
        if (takeLog(logname)):
            bool == False

def takeLog(name):
    s1 = time.time()
    print("Please eneter that you have done the thing you were asked to do be it water or exercise or anything write what you did here: ")
    while ((time.time() - s1 ) < 5):
        with open(name , "a") as f:
            loginput = input()
            if len(loginput) > 2:
                dateTime = date() 
                f.write(f"{dateTime} {loginput}")
                return True
    return False


if __name__ == "__main__":
    numHours = UserChoice()
    startTime = time.time()
    TimeList = makeTimeList(numHours )
    for i in range (len(TimeList)):
        check = TimeList.pop()
        if (timematchCheck(check , startTime)):
            if (check % 60):
                playCheck("water.mp3", 6 , logList[0])
            if (check % 45 ):
                playCheck("exer.mp3" , 9 , logList[1])
            if (check % 30):
                playCheck("eye.mp3" , 6 , logList[2])
    
    while True:
        import pygame
        pygame.mixer.init()
        pygame.mixer.music.load("music.mp3")
        pygame.mixer.music.play()
        time.sleep(233)
