inherit "room/room";

reset(arg){
	if (arg) return;
	set_light(0);
	short_desc = "Inside Crystalline River";
	long_desc = "You are standing waist-high in Crystalline River, the "+
	"underground river of the Crystal Caverns.  You feel the currents "+
	"pulling you northeasterly.  If you were not so wet, and therefore "+
	"cold, you would find the soothing sounds of the river relaxing.\n";
items = ({"river", "The river runs smooth and relaxing here",
	  "cavern", "The cavern is filled with the Crystalline River",
	  "currents", "They pull you downstream to the northeast",
	  "bank", "The river bank is back to the east" });
dest_dir = ({"players/jewel/caverns/fun6", "east",
	     "players/jewel/caverns/fun8", "west",
	     "players/jewel/caverns/medi6", "upstream",
	     "players/jewel/caverns/hard6", "downstream", });
/*
clone_list = ({1,1,"fish","/players/jewel/caverns/monsters/fish",0});
*/

::reset();
replace_program("room/room");
}
