inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "astair";
  long_desc = 
        "You have entered a stairwell.\n"
        "To the north you hear movement.\n"
	"The stairs are old, but sturdy.\n";
   dest_dir = ({ "players/jake/upstairs.c","up",
        "players/jake/eastroom.c", "north",
        "players/jake/enter.c", "south" });

replace_program("room/room");
}

