

/* sshore8.c */

inherit "/room/south/shore";
#include "_defs.h"

string add_long()
{
     return (
	  "Earthy trails lead into the forest to the south and east. The\n" +
	  "shore of the Crescent Lake continues northeast and southwest.\n");
}

string *add_dirs()
{
   return ({
   PATH+"sshore7","northeast",
   PATH+"sshore9","southwest",
   PATH+"sforst20","south",
   PATH+"sforst19","east",
   });
}

