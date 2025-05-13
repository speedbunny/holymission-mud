

/* sislnd9.c */

inherit "/room/south/island";
#include "_defs.h"

string add_long()
{
    return (
    "You are standing in a grove on the shore of the Isle of the Magi.\n" +
	 "All of the trees here are either diseased, dead or heavily mutated\n" +
	 "The shoreline continues southeast from here, as well as heading\n" +
	  "northwest to Focus Point. The small grove continues to the north.\n" +
	  "To the east, you can see an old disused well, and beyond that, on \n" +
	  "top of the hill, stands the ruined tower of Arcanarton.\n");
}

string *add_items()
{
   return ({
   "grove","You are just standing in the grove have a look",
   "well","To the east you can see an old well",
   "hill","You see a small earty hill",
   });
}

string *add_dirs()
{
  return ({
  PATH+"sislnd11","north",
  PATH+"sislnd17","east",
  PATH+"sislnd8","southeast",
  PATH+"sislnd10","northwest",
  "/players/beardy/port/pmagi","west",
  });
}



