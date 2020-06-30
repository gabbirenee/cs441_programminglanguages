// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth


/*
    Name: Gabbi Forsythe
    Date: 10/25/2019
    Class: CS441 
    Purpose: A Java program that will give the amount of change that a user gets when a cost of an item, and the amount paid are entered into the program
*/

import java.io.*;
import java.util.Scanner;

class currency {
    
    // creating the money enum class
    public enum money {
        dollar (100),
        quarter (25),
        dime (10),
        nickel (5),
        penny (1)
        ;
        private final int mValue;

        money(int mValue) {     // constructor
            this.mValue = mValue; 
        }

        public int getValue () {        // method to get the integer value
            return this.mValue;
        }
    }

    // function to round decimals to the hundredths place 
    public static float round (float n) {
        float num;
        num = (int) (n*100+0.5);
        num = num / (float)100.00;
        return num; 
    }

    // the function that will take care of doing the calculations for the change
    public static void calcChange (int c, int index) {  
        int changeNum, changeLeft; 
        changeNum = changeLeft = 0;
        money m; 
        m = money.penny;    // give default value to m

        for(money temp : money.values()) {
            if(temp.getValue() == index){       // match the index to the enum value
                m = temp; 
            }
        }

        int mValue = m.getValue();  // get the numerical value of m
        
        changeNum = c/mValue;   // find the change that needs to be given for this piece of currency
        
        if(changeNum < 0) {
            changeNum = 0;  // if there is no currency of that type to be given as change, set it to 0
        }

        switch(m) {
            case dollar :  
                System.out.print(changeNum + " - dollars, ");
                index = 25;     // after dollar, quarters will be passed as the index 
                break;
            case quarter : 
                System.out.print(changeNum + " - quarters, ");
                index = 10;     // after quarter, dime will be passed as the index
                break;
            case dime : 
                System.out.print(changeNum + " - dimes, ");
                index = 5;  // after dime, the nickel will be passed as the index
                break;
            case nickel : 
                System.out.print(changeNum + " - nickels, ");
                index = 1;      // after nickel, pennies will be passed as the index
                break;
            case penny : 
                System.out.print(changeNum + " - pennies");
                index = -1;     // after pennies, all the pieces of currency will have been traversed, and the index will be set to -1 to stop the recursive call
                break;
        }

        changeLeft = c - (changeNum * mValue);  // calculate the amount of Change left

        if(index > 0) {
            calcChange(changeLeft, index);      // recursive call
        }
        else {
            System.out.println();
        }
    }


    // main function of the program
    public static void main (String [] args) {

        float cost, paid;
        cost = paid = 0; 

        int change;
        change = 0;

        String str;
        str = ""; 
        
        Scanner input = new Scanner(System.in);

        try {
            // get the input for cost
            do {
                System.out.print("Please enter the cost of an item: $");
                str = input.nextLine(); 
                if(!str.isEmpty()) {
                    cost = Float.parseFloat(str);
                }
                else {
                    System.out.println("Enter in a valid number: $");
                }
            } while (cost < 0);

            System.out.println();
            cost = round(cost); // round the cost to the hundredths place in case user input was bad

            // get the input for amount paid
            do {
                System.out.print("Please enter the amount paid: $ ");
                str = input.nextLine(); 
                if(!str.isEmpty()) {
                    paid = Float.parseFloat(str);
                }
                else {
                    System.out.println("Enter in a valid number: $ ");
                }
            } while (paid < 0);
        } catch (Exception ex) {
            System.out.println();
        }

        System.out.println();
        paid = round(paid);     // round the amount paid to the hundredths place in case user input was bad

        input.close();      // close the Scanner after it is used
        
        change = (int)(100 * (round(paid-cost)));  // calculating the full amount of change that needs to be given

        if(change <= 0) {       // invalid numbers
            System.out.println("No change given.");
        }
        else {
            System.out.print("Change returned: ");
            calcChange(change, 100);
        }
        
    }
}