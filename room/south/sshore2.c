

/* sshore2.c */

inherit "/room/south/shore";
#include "_defs.h"

string add_long()
{
     return (
	  "On this place it seems possible to dive down. A trail leads into the\n"+
	  "forest to the The shore of Crescent Lake continues north and south.\n");
}

string *add_dirs()
{
  return ({
   PATH+"sshore1","north",
   PATH+"sshore3","south",
   PATH+"sforst10","east",
//    "/players/whisky/lake/room/lake9","dive",
  });
}

