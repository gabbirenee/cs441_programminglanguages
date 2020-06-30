// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth


/*
    Name: Gabbi Forsythe
    Date: 9/20/2019
    Class: CS441 
    Purpose: A C++ program that will get an array of ten numbers from a user, sort it using insertion sort and print the sorted array on the screen. 
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Function that handles getting a number as user input
int getNumber () {
    string input;
    int number;
    bool isInt = false;

    try {       // C++ automatically uses 0 if what is entered is not a valid integer, so the catch statement here is unecessary
        cin>>input;
        istringstream(input) >> number;
    } catch(exception ex) {
        cout<<"Invlaid integer. 0 will be used instead"<<endl;
        number = 0;
    }

    return number;
}

// this function will print out the array all nice and pretty
void printArray (int theArray [], int size) {
    cout<<"[";
    for(int i = 0; i<size; i++) {
        if(i != size - 1) {         // if it is not the last number in the array
            cout<<theArray[i]<<", ";
        } else {
            cout<<theArray[i]<<"]"<<endl;
        }
    }
}

// insertion sort function to sort that array
void sortArray (int theArray [], int size) {
    for(int j=1; j<size; j++)       // this for loop compares every item of the array to all the items before it and inserts it accordingly
    {
        int old = theArray[j];	
        for(int i=j-1; i>=0; i--)
        {
            if(theArray[i] > old)       // if the number is bigger than the saved number, we gonna shift everyting up
                theArray[i+1]=theArray[i];
            else        // else insert the number
            {
                theArray[i+1]=old; 
                i = -1;     // equivalent of break statement -- possibly questionable programming habit
            } 
        }
        //this is if the old item is smaller than everything else
        if(theArray[0] > old)
            theArray[0]=old;
    }
}

int main()
{
    bool again = true;
    char userInput;
    int theArray [10];      // the array that will be sorted
    
    cout<<endl;
    // cout<<"Welcome to the C++ array sorter thing aka part 1 of assignment 1 for CS441"<<endl;
    cout<<"Welcome to the C++ array sorter!"<<endl;;
    do {
        cout<<endl;
        cout<<"Please enter in 10 integers pressing enter after each one."<<endl;
        cout<<endl;

        // int size = size(theArray);
        int size = 10;  // size of the array

        int i;
        for(i=0; i<size; i++){      // this for loop will ask the user for input 10 times
            int temp;
            cout<<"Integer "<<i+1<<": ";
            temp = getNumber(); 
            theArray[i] = temp; 
        }
        cout<<"Original Array: ";
        printArray(theArray, size);

        // sort that array!!
        sortArray(theArray, size);
        cout<<"Sorted Array: ";
        printArray(theArray, size);

        cout<<endl;
        cout<<"Would you like to sort MORE numbers? (y/n)"<<endl;
        cin>>userInput;
        if(userInput == 'y') {
            again = true;
        }
        else {
            again = false; 
        }
        
    } while(again == true);     // sort until the user don't want to sort no more

    cout<<"The End!"<<endl;
    return 0;
}
