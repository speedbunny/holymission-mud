

/* sshore12.c */

inherit "/room/south/shore";
#include "_defs.h"

string add_long()
{
	  return("The shore of Crescent Lake continues east and west.\n");
}

string *add_dirs()
{
   return ({
   PATH+"sshore11","east",
   PATH+"sshore13","west",
   });
}


