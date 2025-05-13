/* 12.05.93 Airborne: Re-writting to fit "room/room" and replace_program */

inherit "room/room";

reset(arg){
  set_light(0);
  short_desc = "Dark passage";
  long_desc = "You are at the south end of a dark passage in the cellar.\n" 
	  "To the south you can see a glimpse of some light from the stairs,\n" 
	  "and there are doors leading east and west.\n" 
	  "The passage continues north.\n";
  items = ({ "passage", "A dark passage in the cellar",
		"stairs", "A glimpse of light shines from above",
		"doors", "Two doors, one leading east and the other west" });
  dest_dir = ({ "players/padrone/inside/dark_pass2", "north",
	  "players/padrone/inside/stairs0", "south",
	  "players/padrone/inside/food_cellar", "west",
	  "players/padrone/inside/coal_cellar", "east" });

replace_program("room/room");
}
