inherit "/room/south/shore";
#include "_defs.h"

string add_long() {

  return (
    "An earthy trail leads into the forest to the east. The shore of " +
    "the Crescent Lake continues north and south.\n");
}

string *add_item()
{
    return ({
    });
}

string *add_dirs()
{
   return ({
   PATH+"sshore3","north",
   PATH+"sshore5","south",
   PATH+"sforst12","east",
   });
}
