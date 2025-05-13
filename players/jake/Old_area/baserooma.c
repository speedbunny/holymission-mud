inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "baserooma";
  long_desc = 
        "This is Sam's storage room.\n"
	"There are several cleaning items stacked neatly on the shelf.\n";
  dest_dir =  ({ "players/jake/basea.c", "east" });

replace_program("room/room");
}

