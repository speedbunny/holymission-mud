
/* sislnd13.c */

inherit "/room/south/island";
#include "_defs.h"

string add_long()
{
    return (
     "You are halfway up the hill. On the top of the hill, to the south,\n" +
	  "stands the ruins of the tower of Arcanarton. The bridge to the\n" +
	  "mainland stands at the base of the hill to the north. A path heads\n" +
	  "around the hill to the east, and down the hill to the shore of the\n" +
	  "island to the west.\n");
}

string *add_items()
{
    return ({
    "hill","Next to you is a small earthy hill",
    "ruins","The ruins of the tower of Arcanarton",
    "bridge","A small ropebridge crossing the lake",
    });
}

string *add_dirs()
{
    return ({
    PATH+"sislnd1","north",
    PATH+"sislnd18","south",
    PATH+"sislnd14","east",
    PATH+"sislnd12","west",
    });
}

