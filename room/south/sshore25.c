


/* sshore25.c */

inherit "/room/south/shore";
#include "_defs.h"

string add_long()
{
     return (
	  "Earthy trails lead into the forest to the north and west. The\n" +
	  "shore of the Crescent Lake continues northwest and southeast.\n");
}

string *add_dirs()
{
  return ({
  PATH+"sforst49","north",
  PATH+"sforst46","east",
  PATH+"sshore24","northwest",
  PATH+"sshore26","southeast",
  });
}


