


/* sshore27 */

inherit "/room/south/shore";
#include "_defs.h"

string add_long()
{
     return (
	  "Eathy Trails lead into the forest to the north and west. The\n" +
	  "shore of Crescent Lake continues northeast and southwest.\n");
}

string *add_dirs()
{
   return ({
   PATH+"sforst47","north",
   PATH+"sforst46","west",
   PATH+"sshore28","northeast",
   PATH+"sshore26","southwest",
   });
}

