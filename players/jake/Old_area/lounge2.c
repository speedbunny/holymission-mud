inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "lounge2";
  long_desc = 
	"You have entered the second floor lounge.\n"
        "It is very similar to the first floor lounge.\n"
        "There is a hallway that extends to the north.\n";
  dest_dir =
        ({ "players/jake/upstairs", "south",
	"players/jake/2hall","north" });

replace_program("room/room");
}

