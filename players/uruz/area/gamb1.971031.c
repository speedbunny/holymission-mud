inherit "room/room";
#include "/players/trout/defs.h"
#include "/obj/door.h"
object obj_1, obj_2;

reset(arg){
	if(arg) return;
	set_light(1);
	short_desc= "Usegi's Gambling Hall";
	long_desc= "You are standing in a dim room, filled with smoke. People "+
	"fill the room, crowded around various tables. Each table has a "+
	"different game of chance on it. A band plays live music from the "+
	"southeast corner. \n";
	DD= ({ ZZ+"/alley8", "leave" });
	items= ({ "tables", "You see a poker table and a blackjack table "+
		"near you",
		"band", "An oriental jazz band. Imagine that!" });
	MAKE_DOORS(ZZ+"/gamb1", "east", ZZ+"/gamb2", "west", "black", "gambling_hall", "This heavy iron door says 'employees only' on it. \n", 1, 1, 1);
	obj_1->set_door_long("A heavy iron door");
	obj_1->set_closed(1);
	::reset(arg);
	replace_program("room/room");
	}
