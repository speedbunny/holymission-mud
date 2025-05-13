inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "floor7";
  long_desc = 
	"This room is vacant.\n"
	"The walls and floor are bare.\n"
	"You see a small mouse scurry across the floor.\n";
  dest_dir = ({ "players/jake/hall", "west" });
  clone_list = ({ 1, 1, "mouse", "players/jake/monster/mouse", 0 });

replace_program("room/room");
}

