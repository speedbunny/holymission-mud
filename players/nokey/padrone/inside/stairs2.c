/* 170794: Nokey: strict typed */
#pragma strict_types
inherit "room/room";

void reset(int arg) {
  set_light(1);
  short_desc = "Stairs";
  long_desc =    "You are on a landing on the stairway.\n" 
     "This is the first floor, and there are stairs leading up and down.\n";
  dest_dir = ({ "players/padrone/inside/m_uhall", "north",
	   "players/padrone/inside/attic", "up",
	   "players/padrone/inside/stairs1", "down" });

replace_program("room/room");
}
