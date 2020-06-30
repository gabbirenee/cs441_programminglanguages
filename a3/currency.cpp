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
    Purpose: A C++ program that will give the amount of change that a user gets when a cost of an item, and the amount paid are entered into the program
*/

#include <iostream>

// function to round decimals to the hundredths place 
float round (float n) {
    float num;
    num = (int) (n*100+0.5);
    num = num / 100.00;
    return num; 
}

    // the function that will take care of doing the calculations for the change
    void calcChange (int c, int index) {  
        enum money {
        dollar = 100, 
        quarter = 25, 
        dime = 10, 
        nickel = 5, 
        penny = 1
    };

        int changeNum, changeLeft; 
        changeNum = changeLeft = 0;
        money m; 
        m = penny;    // give default value to m

        // match the index to the value
        if(index == dollar) m = dollar;
        else if(index == quarter) m = quarter;
        else if(index == dime) m = dime;
        else if(index == nickel) m = nickel;
        else { m = penny;}

        changeNum = c/m;   // find the change that needs to be given for this piece of currency
        
        if(changeNum < 0) {
            changeNum = 0;  // if there is no currency of that type to be given as change, set it to 0
        }

        switch(m) {
            case dollar :  
                std::cout<<changeNum <<" - dollars, ";
                index = 25;     // after dollar, quarters will be passed as the index 
                break;
            case quarter : 
                std::cout<<changeNum<<" - quarters, ";
                index = 10;     // after quarter, dime will be passed as the index
                break;
            case dime : 
                std::cout<<changeNum<<" - dimes, ";
                index = 5;  // after dime, the nickel will be passed as the index
                break;
            case nickel : 
                std::cout<<changeNum<<" - nickels, ";
                index = 1;      // after nickel, pennies will be passed as the index
                break;
            case penny : 
                std::cout<<changeNum<<" - pennies";
                index = -1;     // after pennies, all the pieces of currency will have been traversed, and the index will be set to -1 to stop the recursive call
                break;
        }

        changeLeft = c - (changeNum * m);  // calculate the amount of Change left

        if(index > 0) {
            calcChange(changeLeft, index);      // recursive call
        }
        else {
            std::cout<<std::endl;
        }
    }


// main function of the program
int main () {
    float cost, paid;
    cost = paid = 0.00; 

    int change;
    change = 0;
    // get the input for cost
    do {
        std::cout<<"Please enter the cost of an item: $";
        std::cin>>cost; 
    } while (cost < 0.0);

    std::cout<<std::endl; 
    cost = round(cost); // round the cost to the hundredths place in case user input was bad

    // get the input for amount paid
    do {
        std::cout<<"Please enter the amount paid: $";
        std::cin>>paid;
    } while (paid < 0.0);

    std::cout<<std::endl; 
    paid = round(paid);     // round the amount paid to the hundredths place in case user input was bad
    
    change = 100 * (round(paid-cost));  // calculating the full amount of change that needs to be given

    if(change <= 0) {
        std::cout<<"No change given."<<std::endl;
    }
    else {
        std::cout<<"Change returned: ";
        calcChange(change, 100);        // pass 100 as index to represent dollar
    }
    
    return 0;
}