


/* sshore22.c */

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
   PATH+"sforst21","north",
   PATH+"sforst27","west",
   PATH+"sshore23","northeast",
   PATH+"sshore21","southwest",
   });
}

