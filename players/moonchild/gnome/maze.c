inherit "room/room";

setup(str) {
  int *exit;
  string *tmp;
  tmp=explode(str, "#");
  exit="players/moonchild/gnome/temple"->random_array(4);
  dest_dir=({ "players/moonchild/gnome/maze" + tmp[exit[0]], "north",
        "players/moonchild/gnome/maze" + tmp[exit[1]], "east",
        "players/moonchild/gnome/maze" + tmp[exit[2]], "south",
        "players/moonchild/gnome/maze" + tmp[exit[3]], "west" });
  short_desc="In a dark cavern";
  long_desc="You are standing in the midst of a dark underground cavern. Rocks spring up\n"
        + "around you, supporting the ceiling, and your voice echoes off the walls.\n";
  items=({ "rocks", "Huge rocks support the ceiling of this cavern",
	"ceiling", "Rocks provide a natural ceiling to this cavern",
	"walls", "The rock walls are covered in condensation", });
  property=({ "no_teleport" });
}
