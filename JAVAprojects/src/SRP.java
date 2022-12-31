import java.util.Random;
import java.util.Scanner;

public class SRP {
    public static char randomizer() {
        Random rand = new Random();
        int n = rand.nextInt( 0,3);

        if (n == 0)
            return 'r';
        else if ( n == 1)
            return 'p';
        else if (n == 2)
            return 's';

        return 's';
    }
    public static char input ()
    {
        Scanner input = new Scanner(System.in);
        System.out.println("Please enter your choice of Rock, paper or scissor here: ");
        String consoleInput = input.next();
        char uChoice = 'n';
        if (consoleInput.equalsIgnoreCase("Rock") || consoleInput.equalsIgnoreCase("Stone"))
            uChoice = 'r';
        else if (consoleInput.equalsIgnoreCase("Paper")) {
            uChoice='p';
        }
        else if (consoleInput.equalsIgnoreCase("Scissor"))
            uChoice = 's';
        else {
            System.out.println("Please enter a valid input!! ");
            input();
        }
        return uChoice;
    }
    public static void message(char c)
    {
        if (c == 'r')
            System.out.println("The computer chose Rock");
        else if (c == 'p')
            System.out.println("The computer chose paper");
        else
            System.out.println("The computer chose scissor ");
    }
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.println("Enter Play to play rock paper scissors with computer or enter any shit: ");
        String choice = input.next();
        if(choice.equalsIgnoreCase("Play"))
        {
            byte uCounter = 0 , cCounter = 0 , garbage=0;
            while (uCounter != 5 && cCounter != 5)
            {
                char uChoice = input();
                char cChoice = randomizer();
                if (uChoice =='r'){ //user -> rock
                    if (cChoice== 'r') {
                        message('r');
                        garbage++;
                    }
                    else if (cChoice == 's') {
                        message('s');
                        uCounter++;
                    }
                    else {
                        message('p');
                        cCounter++;
                    }
                } else if (uChoice == 'p') { // user -> paper
                    if (cChoice == 'r') {
                        message('r');
                        uCounter++;
                    }
                    else if(cChoice == 'p') {
                        message('p');
                        garbage++;
                    }
                    else {
                        message('s');
                        cCounter++;
                    }
                }else  // user ->scissor
                {
                    if(cChoice == 'r') {
                        message('r');
                        cCounter++;
                    }
                    else if(cChoice== 'p') {
                        message('p');
                        uCounter++;
                    }
                    else {
                        message('s');
                        garbage++;
                    }
                }
                System.out.println("Your score = " + uCounter);
                System.out.println("Computer's Score = " + cCounter + "\nTotal number of rounds played: "+ (garbage+uCounter+cCounter));

            }

            if (uCounter > cCounter)
                System.out.println("Congratulations for winning the game!!!\nYou have defeated the computer by a score" +
                        "difference of: " + (uCounter - cCounter) );
            else
                System.out.println("Alas you have lost this game to computer by a score difference of: "
                        + (cCounter - uCounter));

        }
        else
            System.out.println("Thank you for your response. ");
    }
}
