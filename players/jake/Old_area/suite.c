inherit "room/room";

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc = "suite";
  long_desc = 
        "You have entered the suite on the fourth floor.\n"
        "To the south is an apartment.\n"
        "To the west is a kitchen, and to the east, a bathroom.\n";
  dest_dir = ({ "players/jake/Kirkroom", "south",
        "players/jake/3stairs", "north",
        "players/jake/kbath","east",
        "players/jake/Kkitchen", "west" });

replace_program("room/room");
}


