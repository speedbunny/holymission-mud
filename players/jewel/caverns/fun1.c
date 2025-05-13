inherit "room/room";

reset(arg){
  if(!arg){
    set_light(0);
    short_desc = "Dim cavern.";
    long_desc = 
	"The cavern's dark rock walls seem to be interupted only by the "+
	"soft glistening of the pink colored cystals reflecting your "+
	"light source.  The cavern continues both to the west and east.\n";
     items = ({ "rock", "Cold dark rock creating the walls to the caverns",
		"walls", "Cold dark rock surface interupted only be a few"+
			" soft glowing crystals",
		"crystals", "Soft pink colored crystals",
		"crystal", "Soft pink colored crystal",
		"cavern", "A dark rock surfaced cavern leading east and west",
		});
     dest_dir = ({ "players/jewel/caverns/fun2", "west",
             "players/jewel/caverns/central", "east" });		

replace_program("room/room");
    }
}
