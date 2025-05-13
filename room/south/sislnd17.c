
/* sislnd17.c */

inherit "/room/south/island";
#include "_defs.h"

string add_long()
{
     return (
     "You are halfway up the hill. The old, disused well stands here,\n" +
	  "the roof having fallen in from neglect. On the top of the hill\n" +
	  "to the east, stands the ruins of the tower of Arcanarton. A small\n" +
	  "paths winds down to the shore of the island to the north and south\n" +
	  "Down on the shore to the west is a small grove. The well has a ladder\n" +
	  "running down into it.\n");
}

string *add_items()
{
    return ({
    "well","You see an old, disused well",
    "roof","The roof is broken down",
    "path","The path winds down to the shore of the island",
    "ladder","The ladder is running down into the well",
    });
}

string *add_dirs()
{
  return ({
  PATH+"sislnd12","north",
  PATH+"sislnd8","south",
  PATH+"sislnd9","west",
  PATH+"sislnd18","east",
  PATH+"lair","down",
  });
}

