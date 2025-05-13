

/* sislnd8.c */

inherit "/room/south/island";
#include "_defs.h"


void get_objects()
{
    if (!present("Bard",this_object()))
    {
        move_object(
        clone_object("/players/moonchild/haunter/bard"),this_object());
    }
}

string add_long() 
{
     return (
     "You are standing on the shore of the Isle of the Magi.\n" +
	  "A path leads up the hill to the east. The shore of the\n" +
	  "continues southeast and northwest into a small grove from\n" +
	  "here. To the north, you can see an old disused well.\n");
}

string *add_items()
{
    return ({
    "well","To the north you can see an old well",
    "path","A path leads up the hill to the east",
    "grove","To the northwest you see a small grove",
    });
}

string *add_dirs()
{
    return ({
    PATH+"sislnd17","north",
    PATH+"sislnd16","east",
    PATH+"sislnd7","southeast",
    PATH+"sislnd9","northwest",
    });
}

