

/* sshore21.c */

inherit "/room/south/shore";
#include "_defs.h"

string add_long()
{
     return (
	  "Earthy trails lead into the forest to the north and west. The\n" +
	  "shore of the Crescent Lake continues northeast and southwest.\n");
}

string *add_dirs()
{
   return ({
   PATH+"sforst27","north",
   PATH+"sforst28","west",
   PATH+"sshore22","northeast",
   PATH+"sshore20","southwest",
   });
}


