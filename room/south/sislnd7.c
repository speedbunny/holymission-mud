
/* sislnd7.c */

inherit "/room/south/island";
#include "_defs.h"

string add_long()
{
     return (
     "You are standing on the shore of the Isle of the Magi. The\n" +
	  "The shore of the island continues northeast and northwest from\n" +
	  "To the north, a hill rises up to the ancient ruins of the Tower\n" +
	  "of Arcanarton, the archmage who used to live on this island.\n"); 
}

string *add_items()
{
    return ({
    "ruin","The ruins of the tower of Arcanarton",
    "ruins","The ruins of the tower of Arcanarton",
    });
}

string *add_dirs()
{
    return ({
    PATH+"sislnd16","north",
    PATH+"sislnd6","northeast",
    PATH+"sislnd8","northwest",
   });
}


