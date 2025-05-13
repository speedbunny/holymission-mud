

/* sshore9.c */

inherit "/room/south/shore";
#include "_defs.h"

string add_long()
{
     return (
          "An earthy trail leads into the forest to the east. The shore " +
           "of the Crescent Lake continues northeast and west " +
           "out of site. You also notice on further inspection " +
           "a path leading off to the south form here.\n");
}

string *add_dirs()
{
   return ({
   PATH+"sshore8","northeast",
   PATH+"sshore10","west",
   "/players/saffrin/area/hamlet/room/enter","south",
   PATH+"sforst20","east",
   });
}

