

/* sshore18.c */

inherit "/room/south/shore";
#include "_defs.h"

string add_long()
{
     return (
	  "Earthy trails lead into the forest to the south and west. The\n" +
	  "shore of the Crescent Lake continues northwest and southeast.\n");
}

string *add_dirs()
{
   return ({
   PATH+"sshore19","northwest",
   PATH+"sshore17","southeast",
   PATH+"sforst33","south",
   PATH+"sforst31","west",
   });
}
   


