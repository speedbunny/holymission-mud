inherit "/room/room.c";

void reset(int arg) {
  ::reset(arg);
  if (arg) return;

  short_desc="Area Start Room";
  long_desc="A thick, cold mist surrounds you, obscuring all but the closest objects from view. At the roadside, a wooden signpost displays the current destinations.\n";

  dest_dir=({
    "players/dworkin/workroom", "workroom",
    "players/dworkin/mine/start", "mine"
    });

  replace_program("room/room");
}



