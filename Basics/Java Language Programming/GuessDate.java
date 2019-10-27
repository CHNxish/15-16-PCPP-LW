/* 根据二进制原理，猜生日日期 */
/* 
** OPTION == 0 CLI模式
** OPTION == 1 GUI模式
** OPTION == 2 错误  
*/
import java.util.Scanner;
import javax.swing.JOptionPane;

public class GuessDate{
	public static void main(String[] args){
		String set1 =
            " 1  3  5  7\n" +
            " 9 11 13 15\n" +
            "17 19 21 23\n" +
            "25 27 29 31";

        String set2 =
            " 2  3  6  7\n" +
            "10 11 14 15\n" +
            "18 19 22 23\n" +
            "26 27 30 31";

        String set3 =
            " 4  5  6  7\n" +
            "12 13 14 15\n" +
            "20 21 22 23\n" +
            "28 29 30 31";

        String set4 =
            " 8  9 10 11\n" +
            "12 13 14 15\n" +
            "24 25 26 27\n" +
            "28 29 30 31";

        String set5 =
            "16 17 18 19\n" +
            "20 21 22 23\n" +
            "24 25 26 27\n" +
            "28 29 30 31";

        int day = 0;
        int answer;
        int option;

        // Create a Scanner
        Scanner input = new Scanner(System.in);

        // Input Option
        System.out.println("Input Option:\n" +
        	"0: Command Line Interface\n" +
        	"1: Graphical User Interface\n");
        option = input.nextInt();

        if(option == 0){
        	// Prompt the user to answer questions
        	System.out.print("Is your birthday in Set1?\n");
        	System.out.print(set1);
        	System.out.print("\nEnter 0 for No and 1 for Yes: ");
        	answer = input.nextInt();

        	if(answer == 1)
            	day += 1;

        	System.out.print("Is your birthday in Set2?\n");
        	System.out.print(set2);
        	System.out.print("\nEnter 0 for No and 1 for Yes: ");
        	answer = input.nextInt();

        	if(answer == 1)
          	  day += 2;

        	System.out.print("Is your birthday in Set3?\n");
        	System.out.print(set3);
        	System.out.print("\nEnter 0 for No and 1 for Yes: ");
        	answer = input.nextInt();

        	if(answer == 1)
            	day += 4;

        	System.out.print("Is your birthday in Set4?\n");
        	System.out.print(set4);
        	System.out.print("\nEnter 0 for No and 1 for Yes: ");
        	answer = input.nextInt();

        	if(answer == 1)
            	day += 8;

        	System.out.print("Is your birthday in Set5?\n");
        	System.out.print(set5);
        	System.out.print("\nEnter 0 for No and 1 for Yes: ");
        	answer = input.nextInt();

        	if(answer == 1)
            	day += 16;
    	}
    	else if(option == 1){
    		answer = JOptionPane.showConfirmDialog(null, "Is your birthday in Set1?\n" + set1);

    		if(answer == JOptionPane.YES_OPTION)
    			day += 1;

    		answer = JOptionPane.showConfirmDialog(null, "Is your birthday in Set2?\n" + set2);

    		if(answer == JOptionPane.YES_OPTION)
    			day += 2;

    		answer = JOptionPane.showConfirmDialog(null, "Is your birthday in Set3?\n" + set3);

    		if(answer == JOptionPane.YES_OPTION)
    			day += 4;

    		answer = JOptionPane.showConfirmDialog(null, "Is your birthday in Set4?\n" + set4);

    		if(answer == JOptionPane.YES_OPTION)
    			day += 8;

    		answer = JOptionPane.showConfirmDialog(null, "Is your birthday in Set5?\n" + set5);

    		if(answer == JOptionPane.YES_OPTION)
    			day += 16;
    	}
    	else{
    		System.err.println("\nOption value input error!\n");
    		System.exit(1);
    	}

    	if(option == 0){
        	System.out.println("\nYour birthday is " + day + "!");
    	}	
    	else{
    		JOptionPane.showMessageDialog(null, "Your birthday is " + day + "!");
    	}
    }
}
