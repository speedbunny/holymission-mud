inherit "/room/room.c";

void reset(int arg) {
  ::reset(arg);
  if (arg) return;

  short_desc="At the rusted gates";
  long_desc="The thick, cold mist continues to obscure all but the closest objects from view. Directly northwards, two closed rusted gates provide the only access to the fenced off area. Southwards, the access road vanishes into the mist.\n";

  dest_dir=({
    "players/dworkin/startroom", "south",
    "players/dworkin/mine/start", "mine"
    });

  replace_program("room/room");
}


