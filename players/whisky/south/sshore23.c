

/* sshore23.c */

inherit "/room/south/shore";
#include "_defs.h"

string add_long()
{
     return (
	  "An eathy trail leads into the forest to the west. The shore\n" +
	  "of the Crescent Lake continues southwest and east.\n");
}

string *add_dirs()
{
    return ({
    PATH+"sshore24","east",
    PATH+"sshore22","southwest",
    PATH+"sforest21","west",
    });
}
  

