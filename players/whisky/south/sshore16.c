

/* sshore16.c */

inherit "/room/south/shore";
#include "_defs.h"

string add_long()
{
     return(
	  "Trails lead into the forest to the south and west. The shore of\n" +
	  "the Crescent Lake continues northwest and southeast.\n");
}

string *add_dirs()
{
  return ({
  PATH+"sshore17","northwest",
  PATH+"sshore15","southeast",
  PATH+"sforst40","south",
  PATH+"sforst34","west",
  });
}


