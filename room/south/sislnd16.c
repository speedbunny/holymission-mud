
/* sislnd16.c */

inherit "/room/south/island";
#include "_defs.h"

string add_long()
{
     return (
     "You are halfway up the hill. On the top of the hill, to the north\n" +
	  "stands the ruins of the tower of Arcanarton. A small path winds\n" +
	  "down to the shore of the island to the south, east and west.\n");
}

string *add_items()
{
   return ({
   "path","You see a small earthy path",
   "hill","You see a small hill to the north",
   });
}

string *add_dirs()
{
   return ({
   PATH+"sislnd18","north",
   PATH+"sislnd7","south",
   PATH+"sislnd6","east",
   PATH+"sislnd8","west",
   });
}


