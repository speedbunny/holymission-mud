

/* sshore28 */

inherit "/room/south/shore";
#include "_defs.h"

string add_long()
{
     return (
	  "An earthy trail leads into the forest to the west. The shore\n" +
	  "of the Crescent Lake continues southwest and east.\n");
}

string *add_dirs()
{
   return ({
   PATH+"sshore29","east",
   PATH+"sshore27","southwest",
   PATH+"sforst47","west",
   });
}


