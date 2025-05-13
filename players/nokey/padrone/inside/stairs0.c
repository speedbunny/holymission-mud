/* 170794: Nokey: strict typed */
#pragma strict_types
inherit "room/room";

void reset(int arg) {
  set_light(0);
  short_desc = "Stairs";
  long_desc = "You are at the bottom of the stairs.\n" 
	 "This is the cellar, and the stairs are leading up.\n";
  dest_dir = ({ "players/padrone/inside/dark_pass1", "north",
	 "players/padrone/inside/stairs1", "up" });

replace_program("room/room");
}
