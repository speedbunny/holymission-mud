#include "/obj/door.h"

inherit "room/room";

reset(arg){
object obj_1,obj_2,key,pr;
  if(arg) return;
	if(!present("door")){
		MAKE_DOORS("players/airborne/temple/levelb/room8", "north", "players/airborne/temple/levelb/room10", "south", "blackened_steel", "altardoor", "This is a blackened steel altar door.\n", 1,1,1)
