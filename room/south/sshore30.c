
/* sshore30.c */

inherit "/room/south/shore";
#include "_defs.h"

string add_long()
{
     return (
	  "At this place it seems possible to dive down into the cold lake.\n" +
	  "An earthy trail leads into the forest to the east. The shore of\n" +
	  "the Crescent Lake continues southeast and west.\n");
}

string *add_dirs()
{
   return ({
   PATH+"sforst8","east",
   PATH+"sshore29","west",
   PATH+"sshore1","southeast",
//    "/players/whisky/lake/room/lake13","down",
   });
}


