
/* sislnd12.c */

inherit "/room/south/island";
#include "_defs.h"

string add_long()
{
     return (
     "You are standing on the shore of the Isle of the Magi. The shore\n" +
	  "of the island continues northeast to the ruined bridge and west\n" +
	  "into a small grove from here. To the south is an old, disused well.\n" +
	  "Standing atop a cliff to the southeast is the tower of Arcanarton,\n" +
	  "but there is no way to get up there from here. A path does lead up\n" +
	  "the hill to the east though.\n");
}

string *add_items()
{
   return ({
   "bridge","You see a ruined bridge to the northeast",
   "well","To the south you see an old, disused well",
   "cliff","You see a steep cliff to the southeast",
   "path","The path leads up a brown earthy hill",
   "hill","You see a small earthy hill",
   });
}

string *add_dirs()
{
    return ({
    PATH+"sislnd17","south",
    PATH+"sislnd13","east",
    PATH+"sislnd11","west",
    PATH+"sislnd1","northeast",
    });
}


