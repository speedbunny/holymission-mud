inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/

void reset(int arg) {
    set_light(1);
    short_desc=	
	"Northeastern corner of the church";
    long_desc=
	"You stand at the northeastern corner in the huge cathedral.  "+
	"A small, dark passageway leads off to the east.  The chill "+
	"in the air seems to grow stronger.  To the northwest you "+
	"can see an altar and a rather disturbing idol.\n";
    items=({
	"walls",
	    "They are ancient walls of granite",
	"idol",
	    "You are too far away to see details..",
	"chill",
	    "The 'chill' is a reference to the temperature, and "+
	    "cannot be seen.",
	"air",
	    "You squint really hard, and suddenly see millions of "+
	    "little molecules of nitrogen, oxygen, and carbon dioxide.  "+
	    "You wonder what nitrogen, oxygen, and carbon dioxide are "+
	    "for a moment, but it gives you a headache",
	"cathedral",
	    "A large, dark, spooky cathedral",
	"passageway",
	    "It's too dark to tell what is in there",
	"pillars",
	    "They are of black polished granite",
	"hallway",
	    "It is too dark to see very far..",
	"passageway",
	    "It is too dark down there to see anything",
	"altar",
	    "A large altar in front of an even larger Idol",
    });
    dest_dir=({
	GPATH+"nave3","west",
	GPATH+"e_nave2","south",
	GPATH+"e_pass1","east",
    });
    ::reset(arg); 
    replace_program("/room/room");
}
