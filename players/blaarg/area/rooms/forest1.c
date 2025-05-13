#include "/players/blaarg/defs.h"
inherit "room/room";
//Entryway to forest maze...area 2(when I get around to it;))
//Leaving init() in in case I have to add another action, probably
//will, just to make it harder to get into the maze. 
reset(arg) {
    if(!arg) {
	set_light(0);
	short_desc="North Road",
       long_desc=
		"You made it into the forest! But now what are you\n"+
		"going to do?\n";
	items=({
		"forest", "The forest is too thick to see through",
	      });
	dest_dir=({
	AROOMS+"road2", "back",
		 });
       property = ({
                    "no_steal",
                   });
       smell = "The scent of pines is almost overwhelming.";
	::reset(arg);
    }
}
//TODO after ranmaland impl: add init actions and code maze area to link.
init()
{
  ::init();
}