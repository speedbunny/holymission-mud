

/* sshore1.c */

inherit "/room/south/shore.c";
#include "_defs.h"


string add_long()
{
     return (
	  "Trails lead into the forest to the north and east. The shore\n" +
	  "of the Crescent Lake continues south and northwest.\n");
}

string *add_dirs()
{
   return ({
   PATH+"sforst8","north",
   PATH+"sshore2","south",
   PATH+"sforst9","east",
   PATH+"sshore30","northwest",
   });
}


