

/* sshore17.c */

inherit "/room/south/shore";
#include "_defs.h"

string add_long()
{
     return (
	  "Trails lead into the forest to the south and west. The shore of\n" +
	  "the Crescent Lake continues northwest and southeast.\n");
}

string *add_dirs()
{
  return ({
  PATH+"sshore18","northwest",
  PATH+"sshore16","southeast",
  PATH+"sforst34","south",
  PATH+"sforst33","west",
  });
}

