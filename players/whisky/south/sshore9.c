

/* sshore9.c */

inherit "/room/south/shore";
#include "_defs.h"

string add_long()
{
     return (
	  "An earthy trail leads into the forest to the east. The shore\n" +
	  "of the Crescent Lake continues northeast and west\n");
}

string *add_dirs()
{
   return ({
   PATH+"sshore8","northeast",
   PATH+"sshore10","west",
   PATH+"sforst20","east",
   });
}

