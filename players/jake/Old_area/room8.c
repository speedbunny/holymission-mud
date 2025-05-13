inherit "room/room";

reset(arg) {
  set_light(1);
  short_desc = "room8";
  long_desc = 
	"This room is just the opposite of the room across the hall.\n"
 	"It is incredibly dusty in here.\n"
 	"Apparently the maid hasn't made it here yet.\n";
  dest_dir = ({ "players/jake/2halld","west" });
  clone_list = ({ 1, 1, "dust", "players/jake/monster/dust", 0 });

::reset();
replace_program("room/room");
}
