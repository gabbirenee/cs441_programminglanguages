(**
// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth 
*)

(**
    Name: Gabbi Forsythe
    Date: 12/13/2019
    Class: CS441 
    Purpose: Part 1 of 3 of assignment 6 over ML. A SML program to compute the Greatest Common Divisor
        of two positive integer values. 
*)

fun gcd (x:int, y:int)= if x = 0
                        then y
                        else if y = 0   (* if one of the numbers is equal to 0 then the other one is the GCD because math *)
                        then x
                        else if x = y (* Base Case - when the numbers are the same, that is the greatest common divisor *)
                        then x
                        else if x > y   (* Subtract big number from small number until you reach the base case *)
                        then gcd(x-y, y)
                        else gcd(x, y-x);