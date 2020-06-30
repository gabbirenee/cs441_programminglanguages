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
    Purpose: Part 1 of 3 of assignment 5 over prolog. A prolog predicate to determine what person has which aunts
*/

/** Put in all the names of the people in the family tree */
mom(barbara, monica).
mom(barbara, yvonne).
mom(barbara, sharon).
mom(monica, caroline).
mom(yvonne, emily).
mom(yvonne, courtney).
mom(sharon, maddy).
mom(sharon, samantha).
mom(emily, julie).
mom(emily, lauren). 

sister(X, Y) :- mom(Z, X), mom(Z, Y), X \= Y.
aunt(X, Y) :- sister(X, Z), mom(Z, Y).
