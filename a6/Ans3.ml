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
    Purpose: Part 3 of 3 of assignment 6 over ML. A SML program that performs insertion sort on a list. 
*)

fun insert x []= [x]     (* If the list is empty *)
    | insert x (y::tailY)=  if x < y 
                            then x :: y :: tailY        (* If x is less than the head of the list, put x at the head of the list *)
                            else y :: (insert x tailY);       (* If x is greater than the front of the list keep calling the insert funciton until x can be put in the proper place*)


fun sort([]) = []       (* Base Case: Do the sorting until the original list is empty *)
    | sort (x::tailX) = insert x (sort tailX); (* Take the values of the list off until all the values have been removed from the list, then begin inserting them *)