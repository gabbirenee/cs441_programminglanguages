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
    Purpose: A java program that will get an array of ten numbers from a user, sort it using insertion sort and print the sorted array on the screen. -- Uses Heap memory
*/

import java.io.*;
import java.util.Scanner;

class a1_rewritten {
    // function that gets the input from the user and returns it
    public static int getInput () {
        String str;
        int number; 
        boolean isInt = false;

        //use the scanner, get that input
        Scanner input = new Scanner(System.in);

        try {
            str = input.nextLine();
            number = Integer.parseInt(str);
        } catch (Exception ex) {        // if the user doesn't enter a valid integer it will just use 0 instead
            return 0;
        }
        return number;
    }

    // function that prints the arrays all nice and pretty
    public static void printArray (int [] arr) {
        System.out.print("[");
        for(int i = 0; i < arr.length; i++) {
            if(i != arr.length - 1) {         // if it is not the last number in the array
                System.out.print(arr[i]+", ");
            } else {
                System.out.print(arr[i]+"]");
            }
        }
        System.out.println("");
    }

    // insertion sort function to sort the array
    public static void sortArray (int [] arr) {
        for(int j=1; j<arr.length; j++)       // this loop compares every item of the array to all the items before it and inserts it accordingly
        {
            int old = arr[j];	
            for(int i=j-1; i>=0; i--)
            {
                if(arr[i] > old)       // if the number is bigger than the saved number, we gonna shift everyting over
                    arr[i+1]=arr[i];
                else        // else insert the number in its proper place
                {
                    arr[i+1]=old; 
                    i = -1;     // will end the loop immediately -- equivalent of a break statement :/
                } 
            }
            // Case for if the "old" number is smaller than everything else
            if(arr[0] > old)
                arr[0]=old;
        }
    }

    public static void main (String [] args) {
        char userInput;         // used to control the do while loop
        int[] theArray;         // the array that will be sorted
        theArray = new int[10];     // new keyword stores it on the Heap

        // scanner to get some user input
        Scanner input = new Scanner(System.in);
        
        System.out.println("");
        System.out.println("Welcome to the Java array sorter!");

        do {
            System.out.println("");
            System.out.println("Please enter in 10 integers pressing enter after each one.");
            System.out.println("");

            int size = theArray.length;     // size of the array

            //get all the user input
            for(int i=0; i<size; i++){
                System.out.print("Integer "+(i+1)+": ");
                theArray[i] = getInput();   // putting the user input in the array 
            }
            // printing the original array 
            System.out.println("");
            System.out.print("Original Array: ");
            printArray(theArray);
            
            // sort that array
            sortArray(theArray); 
            System.out.print("Sorted Array: ");
            printArray(theArray);

            // ask if the user wants to do it again
            System.out.println("");
            System.out.println("Would you like to sort MORE numbers? (y/n)");
            userInput = input.next().charAt(0);

        } while(userInput == 'y');

        System.out.println("The end!");
    }
}