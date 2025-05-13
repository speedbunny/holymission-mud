
/* sshore29.c */

inherit "/room/south/shore";
#include "_defs.h"


string add_long()
{
     return (
	  "To the north of here you can see a ropebridge crossing the river\n" +
     "That fills the lake. The shore of Crescent Lake continues east\n"+
     "and west\n");
}

string *add_item()
{
   return ({
   "bridge","You see an old ropebridge to the north",
   "ropebridge","You see an old ropebridge to the north",
   "river","It's the river that fills that beautiful, blue lake",
   });
}

string *add_dirs()
{
  return ({
  PATH+"sshore30","east",
  PATH+"sshore28","west",
  "/players/airborne/temple/entrance/bridge1","north",
  });
}



