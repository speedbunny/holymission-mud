

/* sshore7.c */

inherit "/room/south/shore";
#include "_defs.h"

string add_long()
{
     return (
	  "Earthy trails lead into the forest to the south and east. The\n" +
	  "shore of the Crescent Lake continues north and southwest.\n");
}

string *add_dirs()
{
   return ({
   PATH+"sshore6","north",
   PATH+"sshore8","southwest",
   PATH+"sforst19","south",
   PATH+"sforst15","east",
   });
}
   

