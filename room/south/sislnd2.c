

/* sislnd2.c */

inherit "/room/south/shore";
#include "_defs.h"

string add_long()
{
     return (
     "You are standing on the shore of the Isle of the Magi.\n" +
	  "The shore of the island continues east and west from here.\n" +
	  "To the south, a hill rises up to the ancient ruins of the Tower\n" +
	  "of Arcanarton, the archmage who used to live on this island.\n"); 
}

string *add_items()
{
   return ({
   "ruin","You see the ancient ruins of the tower of Aracnarton",
   "ruins","You see the ancient ruins of the tower of Aracnarton",
   });
}

string *add_dirs()
{
  return ({
  PATH+"sislnd14","south",
  PATH+"sislnd3","east",
  PATH+"sislnd1","west",
  });
}


