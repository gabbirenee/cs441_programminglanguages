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
    Purpose: Part 2 of 3 of assignment 6 over ML. A SML program to reverse the elements of a list.
*)

fun reverse([]) = []
    | reverse (x::tailX) = reverse(tailX) @ [x];
