/** 
// Honor Pledge:
//
// I pledge that I have neither given nor 
// received any help on this assignment.
//
// gforsyth 
*/ 

/**
    Name: Gabbi Forsythe
    Date: 11/22/2019
    Class: CS441 
    Purpose: Part 3 of 3 of assignment 5 over prolog. A prolog predicate to perform insertion sort on a list.
*/

sort([H|T], Sorted) :- sort(T, list), !, insertion(H, list, Sorted). /** [H|T] is sorted if, T is sorted and when H is inserted into T (list) it is sorted */
sort(finishedList, finishedList).   /** compares list to make sure they are sorted */

/** adapted from swap algorithm in class */ 
insertion(A, [B|C], [B|D]) :- A > B.    /** compares the value that is passed in (H) to the value in the list other parts of list don't matter */
insertion(A, C, [A|C]) :- insertion(A, C, D).   