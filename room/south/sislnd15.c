

/* sislnd15.c */

inherit "/room/south/island";
#include "_defs.h"

string add_long()
{
    return (
    "You are halfway up the hill. A crumbling monument stands on\n" +
    "the side of the hill here. On the top of the hill, to the west\n" +
    "stands the ruins of the tower of Arcarnaton. A path winds around\n" +
    "the hill to the north, and heads down to the shore of the island\n" +
    "the south and east.\n");
}

string *add_items()
{
     return ({
     "hill","You see a brown earthy hill",
     "monument","The crumbling monument on the side of the hill reads:\n",
"+---------------------------------------------------------------------+\n"+
"|               BEWARE ALL YE WHO READ THIS MESSAGE                   |\n"+
"|   Be it known, that on this day, the tower of the evil mage         |\n"+
"|   Arcanarton was destroyed in an attack by the combined forces      |\n"+
"|           of all of the mages of the land of Lustria.               |\n"+
"|   The body of the mage Arcanarton was not found, and it is feared   |\n"+
"|         that his evil work in this world is not yet over.           |\n"+
"+---------------------------------------------------------------------+",
     "path","A small path winds around the hill",
     });
}

string *add_dirs()
{
   return ({
   PATH+"sislnd14","north",
   PATH+"sislnd6","south",
   PATH+"sislnd5","east",
   PATH+"sislnd18","west", 
   });
}


