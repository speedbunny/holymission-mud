/* 12.05.93 Airborne: Re-written to fit "room/room" and replace_program */

inherit "room/room";

reset(arg){
  set_light(0);
  short_desc = "Dark passage";
  long_desc = "You are at the north end of a dark passage in the cellar.\n" 
	  "To the north there is a small wooden door that doesn't seem to\n" 
	  "have been opened in a long time, and other doors lead east and west.\n" 
	  "The passage continues south.\n";
  items = ({ "passage", "A dark passage through the cellar",
	"cellar", "A deep dark cellar",
	"door", "A small wooden door",
	"doors", "There is a small wooden door and a door to the east and west", });
  dest_dir = ({ "players/padrone/inside/big_under", "north",
	  "players/padrone/inside/dark_pass1", "south",
	  "players/padrone/inside/wine_cellar", "west",
	  "players/padrone/inside/boiler_room", "east" });

replace_program("room/room");
} 
