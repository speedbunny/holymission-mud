

/* sshore4.c */

inherit "/room/south/shore";
#include "_defs.h"

string add_long()
{
     return (
	  "At this place it seems possible to dive down into the cold lake.\n" +
	  "An earthy trail leads into the forest to the east. The shore of\n" +
	  "the Crescent Lake continues north and south. To the west you can\n"+
     "see the 'entrance of a beautiful villa'.\n");
}

string *add_item()
{
    return ({
    "villa","You see a beautiful villa. It looks like a lovers nest"
    });
}

string *add_dirs()
{
   return ({
   PATH+"sshore3","north",
   PATH+"sshore5","south",
   PATH+"sforst12","east",
   "/players/whisky/lake/room/lake1","down",
   "/players/whisky/houses/swifto/entrance","west",
   });
}


