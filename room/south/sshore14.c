

/* sshore14 */

inherit "/room/south/shore";
#include "_defs.h"

string add_long()
{
     return(
          "A trail leads into the forest to the west. The shore of the " +
	  "Crescent Lake continues northwest and east.\n");
}

string *add_dirs()
{
   return ({
   PATH+"sshore15","northwest",
   PATH+"sshore13","east",
   PATH+"sforst41","west",
   });
}


