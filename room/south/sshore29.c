
/* sshore29.c */

inherit "/room/south/shore";
#include "_defs.h"


string add_long()
{
     return (
     "The shore of Crescent Lake continues to the east\n"+
     "and west.\n");
}

string *add_item()
{
   return ({
   "river","It's the river that fills that beautiful, blue lake",
   });
}

string *add_dirs()
{
  return ({
  PATH+"sshore30","east",
  PATH+"sshore28","west",
  });
}



