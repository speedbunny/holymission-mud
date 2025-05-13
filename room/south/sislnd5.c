
/* sislnd5.c */

inherit "/room/south/island";
#include "_defs.h"

string add_long()
{
    return (
     "You are standing on the shore of the Isle of the Magi.\n" +
	  "The shore of the island continues north and southwest from here.\n" +
	  "To the west, a hill rises up to the ancient ruins of the Tower\n" +
	  "of Arcanarton, the archmage who used to live on this island.\n" +
	  "Halfway up the hill you can see some sort of crumbled monument.\n"); 
}

string *add_items()
{
   return ({
   "hill","A small earthy hill",
   "ruin","The ruins of the tower of Arcanarton",
   "ruins","The ruins of the tower of Arcanarton",
   "monument","Halfway up the hill you see a crumbled monument",
   });
}

string *add_dirs()
{
  return ({
  PATH+"sislnd4","north",
  PATH+"sislnd15","west",
  PATH+"sislnd6","southwest",
  });
}
  

