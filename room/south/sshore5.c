

/* sshore5.c */

inherit "/room/south/shore";
#include "_defs.h"


string add_long()
{
     return (
	  "An earthy trail leads into the forest to the east. The shore\n" +
	  "of the Crescent Lake continues north and south.\n");
}

string *add_dirs()
{
    return ({
    PATH+"sshore4","north",
    PATH+"sshore6","south",
    PATH+"sforst13","east",
    });
}
    

