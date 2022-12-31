import java.util.Random;
import java.util.Scanner;

class Game
{
    private
    byte noGuess=1;
    Scanner input = new Scanner(System.in);
    int uNum,randNum;
    public
    Game(){
        Random rand = new Random();
        randNum = rand.nextInt(0,101);
    }
    void getInput(){
        System.out.println("Please enter your guess of number in between 0 to 100 here: ");
        uNum = input.nextInt();
        errorCheck();
    }
    void errorCheck()
    {
        if (uNum>100 || uNum<0) {
            System.out.println("Please enter a valid argument bruhh!!" + "Enter Again!!");
            uNum = input.nextInt();
            noGuess++;
            errorCheck();
        }
    }
    void check (){
        if (uNum > randNum) {
            System.out.println("The number to be matched is smaller than "+uNum+" please enter a smaller number now: ");
            uNum = input.nextInt();
            noGuess++;
            errorCheck();
            check();
        }
        else if(uNum < randNum){
            System.out.println("The number to be matched is greater then "+uNum+" please enter a greater number now:");
            uNum = input.nextInt();
            noGuess++;
            errorCheck();
            check();
        }
        else
            System.out.println("Yay correct guess!!" + "\nThe number of attempts required by you to guess the number are: " + noGuess);

    }
}


public class GuessNumber {
    public static void main(String[] args) {
        Game newGame = new Game();
        newGame.getInput();
        newGame.check();
    }
}