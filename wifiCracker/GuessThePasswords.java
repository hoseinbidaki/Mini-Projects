import java.io.IOException;
import java.util.Scanner;

public class GuessThePasswords
{
    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        while (true)
        {
            System.out.println("Please enter your selection : (1-4)");
            System.out.println("1. Crack With one PassWordList");
            System.out.println("2. Crack With one PassWordList & Symbol ");
            System.out.println("3. Crack With two PassWordList");
            System.out.println("4. Exit");
            int choose = in.nextInt();
            if (choose == 1)new BruteForce().ModeA();
            else if (choose == 2)new BruteForce().ModeB();
            else if (choose == 3)new BruteForce().ModeC();
            else if (choose == 4)System.exit(0);
        }
    }
}
