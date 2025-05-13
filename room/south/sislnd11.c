

/* sislnd11.c */

inherit "/room/south/island";
#include "_defs.h"


string add_long()
{
    return (
    "You are standing in a grove on the shore of the Isle of the Magi.\n" +
	 "All of the trees in the grove are either diseased, dead or heavily\n" +
    "mutated. The shore of the island continues to the east,and the grove\n" +
    "follows the shoreline west to Focus Point. The grove also continues\n"+
    "to the south.\n");
}


string *add_items()
{
    return ({
    "grove","You are just inside the grove, have a look",
    });
}

string *add_dirs()
{
    return ({
    PATH+"sislnd9","south",
    PATH+"sislnd12","east",
    PATH+"sislnd10","west",
    });
}

    

