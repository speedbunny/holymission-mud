

/* sshore15 */

inherit "/room/south/shore";
#include "_defs.h"

string add_long()
{
     return(
          "A Trails lead into the forest to the south and west. The shore " +
	  "of the Crescent Lake continues northwest and southeast.\n");
}

string *add_dirs()
{
   return ({
   PATH+"sshore16","northwest",
   PATH+"sforst41","south",
   PATH+"sforst40","west",
   PATH+"sshore14","southeast",
   });
}
   
