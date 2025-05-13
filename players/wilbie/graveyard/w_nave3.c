inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/

void reset(int arg){
    set_light(1);
    short_desc=
	"Northwestern corner of the church";
    long_desc=
	"You stand at the northwestern corner in the huge cathedral.  "+
	"A small, dark passageway leads off to the west.  The "+
	"chill in the air seems to grow stronger.  To the northeast you "+
	"can see an altar and a rather disturbing idol.\n";
    items=({
	"walls", 
	    "They are ancient walls of granite",
	"idol", 
	    "You are too far away to see details",
	"cathedral", 
	    "It is a fairly old looking cathedral",
	"altar", 
	    "It is a large stone altar",
	"air", 
	    "You cannot see the air.  At first you think you might "+
	    "be going blind, but then you breath a sigh of relief as "+
	    "you realize that air is transparent",
	"chill", 
	    "You can't see that",
	"corner", 
	    "It is the northwest corner",
	"passageway", 
	    "It's pretty dark and spooky looking",
	"pillars", 
	    "They are of black polished granite",
	"hallway", 
	    "It is too dark to see very far",
	"window", 
	    "It depicts a wizard of great power destroying a town",
    });
    dest_dir=({
	GPATH+"nave3","east",
	GPATH+"w_nave2","south",
	GPATH+"w_pass1","west",
    });
    ::reset(arg); 
    replace_program("/room/room");
}
