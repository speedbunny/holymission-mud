

/* sshore6.c */

inherit "/room/south/shore";
#include "_defs.h"

string add_long()
{
     return (
	  "An this place it seems possible to dive down into the cold water.\n" +
	  "An earthy trail leads into the forest to the east. The shore of\n" +
	  "the Crescent Lake continues north and south.\n");
}

string *add_dirs()
{
   return ({
   PATH+"sshore5","north",
   PATH+"sshore7","south",
   PATH+"sforst14","east",
   "/players/whisky/lake/room/lake5","down",
   });
}

