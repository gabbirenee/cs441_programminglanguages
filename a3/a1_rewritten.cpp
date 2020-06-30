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
    Purpose: A C++ program that will get an array of ten numbers from a user, sort it using insertion sort and print the sorted array on the screen. -- Rewritten from assignment 1 to use pointers i think!
*/

#include <iostream>
#include <string>
#include <sstream>

// Function that handles getting a number as user input
int getNumber () {
    std::string input;
    int number;
    bool isInt = false;

    try {       // C++ automatically uses 0 if what is entered is not a valid integer, so the catch statement here is unecessary
        std::cin>>input;
        std::istringstream(input) >> number;
    } catch(std::exception ex) {
        std::cout<<"Invlaid integer. 0 will be used instead"<<std::endl;
        number = 0;
    }

    return number;
}

// this function will print out the array all nice and pretty
void printArray (int *ptr, int size) {
    std::cout<<"[";
    for(int i = 0; i<size; i++) {
        if(i != size - 1) {         // if it is not the last number in the array
            std::cout<<ptr[i]<<", ";
        } else {
            std::cout<<ptr[i]<<"]"<<std::endl;
        }
    }
}

// insertion sort function to sort that array
void sortArray (int *ptr, int size) {
    for(int j=1; j<size; j++)       // this for loop compares every item of the array to all the items before it and inserts it accordingly
    {
        int old = ptr[j];	
        for(int i=j-1; i>=0; i--)
        {
            if(ptr[i+1] > old)       // if the number is bigger than the saved number, we gonna shift everyting up
                ptr[i+1]=ptr[i];
            else        // else insert the number
            {
                ptr[i+1]=old; 
                i = -1;     // equivalent of break statement -- possibly questionable programming habit
            } 
        }
        //this is if the old item is smaller than everything else
        if(ptr[0] > old)
            ptr[0]=old;
    }
}

int main()
{
    bool again = true;
    char userInput;    // the array that will be sorted
    int *ptr = new int[10];
    // std::cout<<ptr;
    
    std::cout<<std::endl;
    // std::cout<<"Welcome to the C++ array sorter thing aka part 1 of assignment 1 for CS441"<<std::endl;
    std::cout<<"Welcome to the C++ array sorter!"<<std::endl;;
    do {
        std::cout<<std::endl;
        std::cout<<"Please enter in 10 integers pressing enter after each one."<<std::endl;
        std::cout<<std::endl;

        // int size = size(theArray);
        int size = 10;  // size of the array

        int i;
        for(i=0; i<size; i++){      // this for loop will ask the user for input 10 times
            int temp;
            std::cout<<"Integer "<<i+1<<": ";
            temp = getNumber(); 
            ptr[i] = temp; 
        }
        std::cout<<"Original Array: ";
        printArray(ptr, size);

        // sort that array!!
        sortArray(ptr, size);
        std::cout<<"Sorted Array: ";
        printArray(ptr, size);

        std::cout<<std::endl;
        std::cout<<"Would you like to sort MORE numbers? (y/n)"<<std::endl;
        std::cin>>userInput;
        if(userInput == 'y') {
            again = true;
        }
        else {
            again = false; 
        }
        
    } while(again == true);     // sort until the user don't want to sort no more

    std::cout<<"The End!"<<std::endl;

    delete [] ptr;     // avoid memory leaks i think 

    return 0;
}
