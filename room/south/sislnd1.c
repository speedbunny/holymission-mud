

/* sislnd1.c */

inherit "/room/south/island";
#include "_defs.h"

string add_long()
{
    return(
     "You are standing on the shore of the Isle of the Magi.\n" +
	  "The shore of the island continues east and southwest from here.\n" +
	  "To the south, a hill rises up to the ancient ruins of the Tower\n" +
	  "of Arcanarton, the archmage who used to live on this island.\n"+
     "A small ropebridge is leading over the lake to the shore.\n");
}

string *add_items()
{
    return ({
    "ruins","You see the ruins of the tower of Arcanarton",
    "tower","You see the ruins of the tower of Arcanarton",
    "bridge","You see an old ropebridge leading over the lake",
    "ropebridge","You see an old ropebridge leading over the lake",
    });
}

string *add_dirs()
{
    return ({
    PATH+"sislnd13","south",
    PATH+"sislnd2","east",
    PATH+"sislnd12","southwest",
    PATH+"sshore26","northwest",
    });
}



