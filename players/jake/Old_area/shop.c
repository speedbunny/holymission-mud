inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "Shop";
  long_desc = 
        "This used to be Jake's shop, but it has been closed due to a bug.\n" 
	"Check back soon.\n";
  dest_dir = ({ "players/jake/enter", "up" });

replace_program("room/room");
}

