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
    Purpose: Part 2 of 3 of assignment 5 over prolog. A prolog predicate to determine if X is a sublist of Y
*/

/** Taken from https://stackoverflow.com/questions/7051400/prolog-first-list-is-sublist-of-second-list  
    and https://stackoverflow.com/questions/42455589/how-to-get-all-consecutive-sublists-subsets-in-prolog  */ 

sub([], _).   /** Empty list is always a sublist of all lists */
sub([X], [X]).      /** If the list are identical, X is a sublist of Y */ 
sub([X|TailX], [_|TailY]) :- sub([X|TailX], TailY).    /** If the next part of the list does not contain what we are looking for (sublist X) */
sub([X|TailX], [X|TailY]) :- sub(TailX, TailY).  /** Check for matches and sublists */
