inherit "room/room";

reset(arg){
  set_light(1);
  short_desc = "Upper hall";
  long_desc = "You are in the upper hall.\n" 
    "You can look down at the courtyard through the windows facing north.\n" 
    "The stairs are to the south, and the hall extends east and west.\n";
  items = ({ "courtyard", "You see the courtyard through the small windows",
	"windows", "Pretty little windows" });
  dest_dir = ({ "players/padrone/inside/e_uhall", "east",
	   "players/padrone/inside/w_uhall", "west",
	   "players/padrone/inside/stairs2", "south" });

replace_program("room/room");
}
