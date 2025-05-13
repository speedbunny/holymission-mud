

/* sislnd14.c */

inherit "/room/south/island";
#include "_defs.h"

string add_long()
{
    return (
    "You are halfway up the hill. On the top of the hill, to the\n" +
	 "southwest, stands the ruins of the tower of Arcanarton, but\n" +
	 "there is no direct route to the top from here. To the south\n" +
	 "stands some sort of crumbling monument. A small path winds\n" +
	 "around the hill to the west, and heads down to the shore of\n" +
	 "of the island to the north and east.\n");
}

string *add_items()
{
    return ({
    "hill","A small earty hill",
    "path","A small path winds itself around the hill",
    });
}

string *add_dirs()
{
    return ({
    PATH+"sislnd2","north",
    PATH+"sislnd15","south",
    PATH+"sislnd4","east",
    PATH+"sislnd13","west",
    });
}
    


